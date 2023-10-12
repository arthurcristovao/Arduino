#define maxVel 255
#define minVel 125
#define centroMin 470
#define centroMax 530
#define maxAnalog 1022

int x = A1; //Saída analógica (Eixo X)
int y = A0; //Saída analógica (Eixo Y)
int botao = 7; //Saída digital do botão (Eixo Z)
char modo; //Variável para armazenar o caractere digitado pelo usuário

float media = (float)maxVel / maxAnalog;

int diferenca = centroMax - centroMin;



void setup() {
  Serial.begin(9600); //Inicializa a comunicação serial
  pinMode(botao, INPUT_PULLUP); //Define botao como entrada e em modo PULL UP, ou seja, lê HIGH quando o botão não estiver pressionado

}

void loop() {
    int leituraX = analogRead(x);
    
    int leituraY = analogRead(y);
    int leituraBotao = digitalRead(botao);

    bool centroX = (leituraX >= centroMin && leituraX <= centroMax);
    bool centroY = (leituraY >= centroMin && leituraY <= centroMax);

    if (centroX && centroY) {
        Serial.println("No centro nos dois eixos");
    } 
    else if (centroX) {
        if(leituraY < centroMin)
          Serial.println("Direita");
        else if (leituraY > centroMax){
          Serial.println("Esquerda");
        }
    } 
    else if (centroY) {
        if(leituraX < centroMin)
          Serial.println("Frente");
        else if (leituraX > centroMax){
          Serial.println("Tras");
        }
    } 

    

    //CANTOS
    if (!centroX && !centroY) {
        if (leituraX < centroMin) {
            if (leituraY < centroMin) {
                Serial.println("Canto superior direito");
                float valor = (float) media * (maxAnalog - leituraY); 
                Serial.println(valor);
            } else if (leituraY > centroMax) {
                Serial.println("Canto superior esquerdo");
                float valor = (float) media * leituraY; 
                Serial.println((int)valor);
            }
        } else if (leituraX > centroMax) {
            if (leituraY < centroMin) {
                Serial.println("Canto inferior direito");
            } else if (leituraY > centroMax) {
                Serial.println("Canto inferior esquerdo");
            }
        }
    }


    // if (leituraBotao == LOW) {
    //     Serial.println("Botão pressionado");
    // } else {
    //     Serial.println("Botão não pressionado");
    // }

        delay(3000);
        Serial.println("------------------------------------");
}



