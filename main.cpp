#define LED_VERDE 2
#define LED_AMARELO 3
#define LED_VERMELHO 4
#define LED_AZUL 5

#define BTN_VERDE 8
#define BTN_AMARELO 9
#define BTN_VERMELHO 10
#define BTN_AZUL 11

#define UM_SEGUNDO 1000
#define MEIO_SEGUNDO 500

#define TAMANHO_SEQUENCIA 4
#define INDEFINIDO -1

#define INDEFINIDO -1


int sequenciaLuzes[TAMANHO_SEQUENCIA];


void setup(){
    Serial.begin(9600);
    iniciaPortas();
    iniciaJogo();
}

void iniciaJogo(){

  for (int f = 0; f < TAMANHO_SEQUENCIA; f++) {
    sequenciaLuzes[f] = sorteiaCor();
  }

}


int sorteiaCor() {
  return random(LED_VERDE, LED_AZUL + 1);
}

void iniciaPortas(){
    //LED
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_AMARELO, OUTPUT);
    pinMode(LED_VERMELHO, OUTPUT);
    pinMode(LED_AZUL, OUTPUT);

    //Botoes
    pinMode(BTN_VERDE, INPUT_PULLUP);
    pinMode(BTN_AMARELO, INPUT_PULLUP);
    pinMode(BTN_VERMELHO, INPUT_PULLUP);
    pinMode(BTN_AZUL, INPUT_PULLUP);

}


void loop(){
  
  for(int i = 0; i < TAMANHO_SEQUENCIA; i++) {
    piscaLed(sequenciaLuzes[i]);
  }
  
}



int checaRespostaJogador() {
  if(digitalRead(BTN_VERDE) == LOW) {
    return piscaLed(LED_VERDE);
  } 
  
  if (digitalRead(BTN_AMARELO) == LOW) {
    return piscaLed(LED_AMARELO);
  } 
  
  if (digitalRead(BTN_VERMELHO) == LOW) {
    return piscaLed(LED_VERMELHO);
  } 
  
  if (digitalRead(BTN_AZUL) == LOW) {
    return piscaLed(LED_AZUL);
  }

  return INDEFINIDO;

}


int piscaLed(int portaLed){
  digitalWrite(portaLed,HIGH);
  delay(UM_SEGUNDO); 
  digitalWrite(portaLed,LOW);
  delay(MEIO_SEGUNDO);
  return portaLed;
}
