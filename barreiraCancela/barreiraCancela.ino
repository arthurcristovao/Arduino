#include <Servo.h>
 
#define SERVO 6 
#define ANGULO 105
#define botao 7

int valorBotao = 0;
int ativado = 0;

Servo s; // Variável Servo
int pos; // Posição Servo

void setup ()
{
  pinMode(botao, INPUT);
  Serial.begin(9600);
  s.attach(SERVO);
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero
}
 
void loop()
{
  valorBotao = digitalRead(botao);
  delay(100);

  if(valorBotao == 1 ){
    for(pos = 0; pos < ANGULO; pos++){
        s.write(pos);
        delay(7);
    }
      ativado++;
    delay(1000);
  }
  
  if(ativado == 1){
    delay(2000);
    for(pos = ANGULO; pos >= 0; pos--){
        s.write(pos);
        delay(7);
      }
      ativado--;
  }

      
}
