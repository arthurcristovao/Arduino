const int verde = 8;
const int amarelo = 7;
const int vermelho = 10;

void setup() {
  pinMode(verde, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(vermelho, OUTPUT);
}

void loop() {
  digitalWrite(vermelho, HIGH);  // Liga o LED
  digitalWrite(amarelo, LOW);
  delay(3000);

  digitalWrite(vermelho, LOW);
  digitalWrite(verde, HIGH);
  delay(4000);

  digitalWrite(verde, LOW);
  digitalWrite(amarelo, HIGH);
  delay(1000);
}