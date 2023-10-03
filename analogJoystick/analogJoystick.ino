int x = A1; //Saída analógica (Eixo X)
int y = A0; //Saída analógica (Eixo Y)
int botao = 7; //Saída digital do botão (Eixo Z)
char modo; //Variável para armazenar o caractere digitado pelo usuário

int media = 1022/2;


void setup() {
  Serial.begin(9600); //Inicializa a comunicação serial
  pinMode(botao, INPUT_PULLUP); //Define botao como entrada e em modo PULL UP, ou seja, lê HIGH quando o botão não estiver pressionado
}

void loop() {
  // if (Serial.available()) { //Se a serial receber algum caractere
  //   modo = Serial.read(); //Lê o caractere e guarda na variável sentido
  //   Serial.println(modo); //Imprime na serial o conteúdo de sentido
  // }

//zona do meio


// if( x < media ){

// }
  

    Serial.print("Leitura do eixo X: ");
    Serial.println(analogRead(x));
    Serial.print("Leitura do eixo Y: ");
    Serial.println(analogRead(y));
    Serial.print("Leitura do botão: ");
    Serial.println(digitalRead(botao));
    Serial.println("------------------");
    delay(3000);
}
