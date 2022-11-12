#include <Servo.h>          
#include <NewPing.h>        
#define M1 15
#define M2 13
#define M3 12
#define M4 14
#define pin_trig 0
#define pin_ech 2
Servo servo;
NewPing sensor (pin_trig,pin_ech,200);

void setup() {
servo.attach(16);
pinMode(M1,OUTPUT);
pinMode(M2,OUTPUT);
pinMode(M3,OUTPUT);
pinMode(M4,OUTPUT);
servo.write(90);
    
}

void maju() {
    digitalWrite(M1,HIGH);
    digitalWrite(M2,LOW);
    digitalWrite(M3,HIGH);
    digitalWrite(M4,LOW);
}

void mundur() {
    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);
    digitalWrite(M3,LOW);
    digitalWrite(M4,HIGH);
}

void kanan() {
    digitalWrite(M1,LOW);
    digitalWrite(M2,LOW);
    digitalWrite(M3,HIGH);
    digitalWrite(M4,LOW);
}

void kiri() {
    digitalWrite(M1,HIGH);
    digitalWrite(M2,LOW);
    digitalWrite(M3,LOW);
    digitalWrite(M4,LOW);
}

void stop() {
    digitalWrite(M1,LOW);
    digitalWrite(M2,LOW);
    digitalWrite(M3,LOW);
    digitalWrite(M4,LOW);
}

void loop(){

  int jarakkanan = 0;
  int jarakkiri = 0;
  delay(50);

  if (jarak <= 20){
    stop();
    delay(100);
    mundur();
    delay(400);
    stop();
    delay(100);
    jarakkanan = lihatkanan();
    delay(300);
    jarakkiri = lihatkiri();
    delay(300);

    if (jarakkanan >= jarakkiri){
      kanan();
            delay(400);
      stop();
    }
    else{
      kiri();
            delay(400);
      stop();
    }
  }
  else{
    maju(); 
  }
    jarak = readPing();
}

int lihatkiri(){  
  servo.write(50);
  delay(500);
  int jarak = readPing();
  delay(100);
  servo.write(115);
  return jarak;
}

int lihatkanan(){
  servo.write(170);
  delay(500);
  int jarak = readPing();
  delay(100);
  servo.write(115);
  return jarak;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}
