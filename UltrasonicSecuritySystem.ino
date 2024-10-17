int TRIG = 13;
int ECHO = 12;
int BUZZER = 2;
int G1PIN = 3, G2PIN = 4, Y1PIN = 5, Y2PIN = 6, Y3PIN = 7, R1PIN = 8, R2PIN = 9;
int SIGNAL;
float DISTANCE;
float CHANGER;

void setup() {
    Serial.begin(9600);
    pinMode(TRIG, OUTPUT);
    pinMode(ECHO, INPUT);
    pinMode(G1PIN, OUTPUT);
    pinMode(G2PIN, OUTPUT);
    pinMode(Y1PIN, OUTPUT);
    pinMode(Y2PIN, OUTPUT);
    pinMode(Y3PIN, OUTPUT);
    pinMode(R1PIN, OUTPUT);
    pinMode(R2PIN, OUTPUT);

    CHANGER = 348.14 * 0.0001;
    CHANGER = CHANGER / 2.0;
    CHANGER = 1.0 / CHANGER;
}

void loop() {
    digitalWrite(TRIG, LOW);
    delayMicroseconds(5);
    digitalWrite(TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG, LOW);
    SIGNAL = pulseIn(ECHO, HIGH);
    DISTANCE = SIGNAL / CHANGER;

    if (DISTANCE < 5) {
        digitalWrite(G1PIN, HIGH);
        digitalWrite(G2PIN, HIGH);
        digitalWrite(Y1PIN, HIGH);
        digitalWrite(Y2PIN, HIGH);
        digitalWrite(Y3PIN, HIGH);
        digitalWrite(R1PIN, HIGH);
        digitalWrite(R2PIN, HIGH);
        tone(BUZZER, 500);
    }
}
else if (DISTANCE < 10) {
    digitalWrite(G1PIN, HIGH);
    digitalWrite(G2PIN, HIGH);
    digitalWrite(Y1PIN, HIGH);
    digitalWrite(Y2PIN, HIGH);
    digitalWrite(Y3PIN, HIGH);
    digitalWrite(R1PIN, LOW);
    digitalWrite(R2PIN, LOW);
    tone(BUZZER, 300);
}

else if (DISTANCE < 15) {
    digitalWrite(G1PIN, HIGH);
    digitalWrite(G2PIN, HIGH);
    digitalWrite(Y1PIN, HIGH);
    digitalWrite(Y2PIN, LOW);
    digitalWrite(Y3PIN, LOW);
    digitalWrite(R1PIN, LOW);
    digitalWrite(R2PIN, LOW);
    tone(BUZZER, 150);
}

else if (DISTANCE < 20) {
    digitalWrite(G1PIN, HIGH);
    digitalWrite(G2PIN, LOW);
    digitalWrite(Y1PIN, LOW);
    digitalWrite(Y2PIN, LOW);
    digitalWrite(Y3PIN, LOW);
    digitalWrite(R1PIN, LOW);
    digitalWrite(R2PIN, LOW);
    tone(BUZZER, 50);
}

else {
    digitalWrite(G1PIN, LOW);
    digitalWrite(G2PIN, LOW);
    digitalWrite(Y1PIN, LOW);
    digitalWrite(Y2PIN, LOW);
    digitalWrite(Y3PIN, LOW);
    digitalWrite(R1PIN, LOW);
    digitalWrite(R2PIN, LOW);
}
