// Importando a Biblioteca do visor LCD
#include <LiquidCrystal.h>

// Definindo os pinos
const int SMS = A0;
const int motor = 13;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// Variavel
int percentValue = 0;

// Funcao de configuracao dos pinos e perifericos
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Sistema de Irri-");
  lcd.setCursor(0,1);
  lcd.print("gacao Automatico!");
  pinMode(motor, OUTPUT);
  delay(2000);
  lcd.clear();
  lcd.print("Umidade = ");
  lcd.setCursor(0,1);
  lcd.print("Agua = ");
}

// Funcao principal (loop)
void loop() {

  int value = analogRead(SMS); // Definindo o valor recebido pelo sensor de umidade
  float Moisture = value * 500.0 / 1023.0; // Definindo o valor da umidade
  // Definindo onde o valor de umidade vai aparecer no visor
  lcd.setCursor(10,0);
  lcd.print(Moisture); 
  lcd.setCursor(6,1);
  
  // Definindo o que fazer de acordo com o valor de umidade recebido
  if (Moisture < 310){
    digitalWrite(motor, HIGH);
    lcd.print(" Ligado");
  }
  else {
    digitalWrite(motor, LOW);
    lcd.print(" Desligado");
  }
  
  // Fazendo o valor de umidade aparecer no visor
  Serial.print ("Umidade");
  Serial.println (Moisture);
}