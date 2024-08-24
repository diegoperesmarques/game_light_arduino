#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_AZUL 5
#define LED_VERMELHO 4
#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500


void setup() {

 //Inicia de portas
  iniciaPortas();
}

void loop() {

}


//Funções

void iniciaPortas() {
 pinMode(LED_VERDE, OUTPUT);
 pinMode(LED_AMARELO, OUTPUT);
 pinMode(LED_AZUL, OUTPUT);
 pinMode(LED_VERMELHO, OUTPUT);
}

void piscaSequencial() {
  piscaLed(LED_VERDE);
  piscaLed(LED_AMARELO);
  piscaLed(LED_VERMELHO);
  piscaLed(LED_AZUL);
}


void piscaSequencia2() {
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AMARELO, HIGH);
  digitalWrite(LED_VERMELHO, HIGH);
  digitalWrite(LED_AZUL, HIGH);
  delay(UM_SEGUNDO);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  digitalWrite(LED_AZUL, LOW);
  delay(UM_SEGUNDO);
}


void piscaLed(int portaLed) {
 digitalWrite(portaLed, HIGH);
 delay(UM_SEGUNDO);
 digitalWrite(portaLed, LOW);
 delay(MEIO_SEGUNDO);
}
