//variaveis da led
const int vermelho = 5;
const int verde = 6;
const int azul = 7;

bool estadoLedVermelho = false;
bool estadoLedVerde = false;
bool estadoLedAzul = false;

//variaveis botões
const int botao1 = 2;
const int botao2 = 3;

unsigned long lastDebounceTime2 = 0;
unsigned long lastDebounceTime1 = 0;
const int botaoDelay = 100;

void setup()
{
//entradas
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

//saidas
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);

  Serial.begin(9600);

  Serial.println("AC1 - Meu Primeiro Projeto 2021");
  Serial.println("                           V1.0");
  Serial.println("Grupo: SmartEnergy");
}

void loop()

{
//Temperatura - led azul
   if(getTemperatura() > 15){
    digitalWrite(azul, true);
     Serial.println("Temperatura alta");
  } else {
     digitalWrite(azul, false); 
  }
  
 //Luminosidade - led verde
  if(getLuminosidade() > 5){
      digitalWrite(verde, true);
    Serial.println("Luminosidade alta");
  } else {
      digitalWrite(verde, false);
  }
  	
//botão ligar - led vermelho
   if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao1)){
    Serial.println("botao 1 apertado");
     digitalWrite(vermelho, true);
    lastDebounceTime1 = millis();}
	
//botão desligar - led vermelho
    if((millis() - lastDebounceTime1) > botaoDelay && digitalRead(botao2)){
    Serial.println("botao 2 apertado");
     digitalWrite(vermelho, false);
      lastDebounceTime1 = millis();}
	
  delay(10);
}

//led vermelho
  void ledVermelho(bool estado){
  estadoLedVermelho = !estadoLedVermelho;
  digitalWrite(vermelho,estadoLedVermelho);
  }

//led verde
  void ledVerde(bool estado){
  estadoLedVerde = !estadoLedVerde;
  digitalWrite(verde,estadoLedVerde);
  }

//sensor de luminosidade
int getLuminosidade(){
      int luminosidade;
    luminosidade = map(analogRead(A1), 6, 619, -3, 10);
      return luminosidade;
}

//led azul
  void ledAzul(bool estado){
  estadoLedAzul = !estadoLedAzul;
  digitalWrite(azul,estadoLedAzul);
  }

//sensor de temperatura
int getTemperatura(){
      int temperaturaC;
    temperaturaC = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
      return temperaturaC;
}
