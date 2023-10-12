#define motorEsq1 6
#define motorEsq2 7
#define EsqVelo 5

#define motorDir1 9
#define motorDir2 8
#define DirVelo 10

#define maxVel 255
#define minVel 125

void setup() {
  pinMode(motorEsq1, OUTPUT);
  pinMode(motorEsq2, OUTPUT);
  pinMode(motorDir1, OUTPUT);
  pinMode(motorDir2, OUTPUT);


}

void loop() {
  acelerar(50);

}


void acelerar(int dlay){

  for( int i = minVel; i <= maxVel; i+=3){
    controlaVelocidade(i, i);
    delay(dlay);
  }

}

void re(){

}


void controlaVelocidade(int velDir, int velEsq){
  digitalWrite(motorEsq1, HIGH);
  digitalWrite(motorEsq2, LOW);
  analogWrite(EsqVelo, velEsq);

  digitalWrite(motorDir1, HIGH);
  digitalWrite(motorDir2, LOW);
  analogWrite(DirVelo, velDir);
}

