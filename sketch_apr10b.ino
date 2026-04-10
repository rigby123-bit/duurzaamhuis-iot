#include <ArduinoJson.h>

int minLDR = 1023;
int maxLDR = 0;


bool weinigLicht(int waarde) {
  return waarde < 500;
}


void stuurLampen(int waarde) {
  if (waarde >= 500 && waarde < 700) {
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
  } else if (waarde >= 700) {
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
  } else {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  int ldr_value = analogRead(A0);

  // Min en max bijhouden
  if (ldr_value < minLDR) minLDR = ldr_value;
  if (ldr_value > maxLDR) maxLDR = ldr_value;

 
  StaticJsonDocument<200> doc;
  doc["ldr_huidig"] = ldr_value;
  doc["ldr_laagst"] = minLDR;
  doc["ldr_hoogst"] = maxLDR;
  serializeJson(doc, Serial);
  Serial.println();

 
  if (weinigLicht(ldr_value)) {
    digitalWrite(3, HIGH);
    int snelheid = random(100, 500);
    digitalWrite(3, HIGH);
    delay(snelheid);
    digitalWrite(3, LOW);
    delay(snelheid);
  } else {
    digitalWrite(3, LOW);
  }

  
  stuurLampen(ldr_value);

  delay(500); 
}
