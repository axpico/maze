class Motore {
  public:
    int pin1;
    int pin2;
    int en;

    Motore(int pin1, int pin2, int en) {
      this->pin1 = pin1;
      this->pin2 = pin2;
      this->en = en;
      this->setPin();
    }

    void setPin() {
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
      pinMode(en, OUTPUT);
    }

    void cw(int speed = 100) { // Provide a default speed value
      speed = map(speed, 0, 100, 0, 255);
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, HIGH);
      analogWrite(en, speed);
    }
    
    void ccw(int speed = 100) { // Provide a default speed value
      speed = map(speed, 0, 100, 0, 255);
      digitalWrite(pin1, HIGH);
      digitalWrite(pin2, LOW);
      analogWrite(en, speed);
    }

    void stop(){
      digitalWrite(en, LOW);
    }
};

Motore m1(7, 8, 9); // Declare the object after the class definition
Motore m2(13, 12, 11);

void avanti(int speed) {
  m1.cw(speed);
  m2.ccw(speed);
}
void indietro(int speed) {
  m1.ccw(speed);
  m2.cw(speed);
}
void sinistra(int speed) {
  m1.ccw(speed);
  m2.ccw(speed);
}
void destra(int speed) {
  m1.cw(speed);
  m2.cw(speed);
}

void stop() {
  m1.stop();
  m2.stop();
}
void setup() {
  // put your setup code here, to run once:
  avanti(50);
  delay(1000);
  indietro(50);
  delay(1000);
  sinistra(50);
  delay(1000);
  destra(50);
  delay(1000);
  stop();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
