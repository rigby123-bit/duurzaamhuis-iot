int A, B, C, D;

void setup() {
  Serial.begin(115200);
  
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // Genereer willekeurige getallen
  A = random(999);
  B = random(999);
  C = random(999);
  D = random(999);

  // Print de waarden
  Serial.println("=== Nieuwe ronde ===");
  Serial.print("A = "); Serial.println(A);
  Serial.print("B = "); Serial.println(B);
  Serial.print("C = "); Serial.println(C);
  Serial.print("D = "); Serial.println(D);
  Serial.println();

  // Zet alle LEDs eerst uit
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);

  // D3 aan: A > B of A < C
  if (A > B || A < C) {
    digitalWrite(3, HIGH);
    Serial.println("D3 AAN (A > B of A < C)");
  }

  // D5 aan: C > A en A < B
  if (C > A && A < B) {
    digitalWrite(5, HIGH);
    Serial.println("D5 AAN (C > A en A < B)");
  }

  // D6 aan: B > C en B > A en C < A
  if (B > C && B > A && C < A) {
    digitalWrite(6, HIGH);
    Serial.println("D6 AAN (B > C en B > A en C < A)");
  }

  // Snel knipperen als D het grootste getal is
  if (D > A && D > B && D > C) {
    Serial.println("D is het grootste! LEDs knipperen...");
    for (int i = 0; i < 10; i++) {
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      delay(100);
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(100);
    }
  }

  Serial.println();
  delay(10000); // Wacht 10 seconden
}
