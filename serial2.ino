int ECHO = 6;
int TRIG = 7;
int duracao = 0;
long distancia = 0;
int red = 12;
int yel = 11;
int gre = 13;

void setup() {
  Serial.begin(9600);

  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
}

void loop() {
  digitalWrite(TRIG, LOW);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duracao = pulseIn(ECHO, HIGH);
  distancia = duracao / 58;
  Serial.println(distancia);      
  delay(100);

  digitalWrite(TRIG, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duracao = pulseIn(ECHO, HIGH);
  distancia = duracao / 58;                   

  if (Serial.available() > 0) {
    int leitura = Serial.read();

    digitalWrite(red, LOW);
    digitalWrite(yel, LOW);
    digitalWrite(gre, LOW);

    if (leitura == 'R') {
      digitalWrite(red, HIGH);
    }

    else if (leitura == 'A') {
      digitalWrite(yel, HIGH);
    }

    else {
      digitalWrite(gre, HIGH);
    }
  }
  delay(1000);
}