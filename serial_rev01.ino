


int Led = 13; //porta Led conectado

//difinir as variáveis e os caracteres para ligar e desligar os Led
char x = 'L';//caracter entre aspas simples
char y = 'D';
char caracter;

//int estadoLed;

void setup()
{
  pinMode(Led, OUTPUT);
  Serial.begin(9600); //Inicia comunição serial a 9600 bits/seg
  
  Serial.println("\n\n\n");
  Serial.println("INICIANDO O SISTEMA...");
  Serial.print("Digite ");
  Serial.print(x);
  Serial.print(" para ligar ou ");
  Serial.print(y);
  Serial.print(" desligar o LED:");
  Serial.println();
}

void loop()
{
  
  if (Serial.available() > 0){//verifica se foi digitado algo
    caracter = Serial.read(); //Variável dentro do IF (armazena a variável digitada)
    if (caracter == x) { 
      digitalWrite(Led,HIGH);//comando para acender led
      Serial.print("Voce digitou ");
        Serial.println(caracter);//varíavel exibe o caracter digitado
        Serial.println("Led Ligado!");
        Serial.println();
        Serial.print("Digite "); 
        Serial.print(y);
        Serial.println(" para Desligar o LED!");
    }
    else if (caracter == y) {
        digitalWrite(Led,LOW);
        Serial.print("Voce digitou "); 
        Serial.println(caracter);//varíavel exibe o caracter digitado
        Serial.println("Led Desligado!");
        Serial.print("Digite "); 
        Serial.print(x);
        Serial.println(" para ligar o LED!");
        Serial.println();
    }
    else if(caracter != x && caracter != y){ //se for digitado um valor não correspondente  
        Serial.print("Voce digitou um valor nao aceito!"); 
        Serial.print("Digite ");
        Serial.print(x);
        Serial.print(" para ligar ou ");
        Serial.print(y);
        Serial.println(" desligar o LED:");
        Serial.println("\n\n");
    }
    
    delay(500); 
  }
  
}
