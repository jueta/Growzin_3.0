
    const unsigned long SECOND = 1000;
    const unsigned long HOUR = 3600*SECOND;

  //VARIAVEIS
  int rele = 10;
  int led_ligado = 12; // --> Led VERDE == luz acesa
  int led_apagado = 9;  // --> Led VERMELHO == luz apagada
  int segA = 2;
  int segB = 3;
  int segC = 6;
  int segD = 7;
  int segE = 8;
  int segF = 1;
  int segG = 0;

//SETUP
void setup(){
    
    pinMode(segA, OUTPUT); //IO 2 -> SEGMENTO A  
    pinMode(segB, OUTPUT); //IO 3 -> SEGMENTO B
    pinMode(segC, OUTPUT); //IO 6 -> SEGMENTO C
    pinMode(segD, OUTPUT); //IO 7 -> SEGMENTO D
    pinMode(segE, OUTPUT); //IO 8 -> SEGMENTO E
    pinMode(segF, OUTPUT); //IO 1 -> SEGMENTO F
    pinMode(segG, OUTPUT); //IO 0 -> SEGMENTO G
    pinMode(5, OUTPUT); //PINO 5 -> SEGMENTO pt
    
    pinMode(rele, OUTPUT);
    pinMode(led_ligado, OUTPUT);
    pinMode(led_apagado, OUTPUT);


// F de floracao
    digitalWrite(segA, LOW);
    digitalWrite(segB, HIGH);
    digitalWrite(segC, HIGH);
    digitalWrite(segD, HIGH);
    digitalWrite(segE, LOW);
    digitalWrite(segF, LOW);
    digitalWrite(segG, LOW);
    digitalWrite(5, LOW);
}



void loop() {

// FLORACAO
    digitalWrite(rele, LOW);
    digitalWrite(led_ligado, LOW);
    digitalWrite(led_apagado, HIGH);
    delay(12*HOUR);
    digitalWrite(rele, HIGH);
    digitalWrite(led_ligado, HIGH);
    digitalWrite(led_apagado, LOW);
    delay(12*HOUR);



}
