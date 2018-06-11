// definerer pins
const int trigPin = 9;
const int echoPin = 10;
const int trigPin2 = 5;
const int echoPin2 = 6;
int led = 4;
int knapp = 3;


// definerer variabler
long duration;
long duration2;
int distance;
int distance2;

void setup() {
// Oppretter pinmodes
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT); 
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT); 
pinMode(led, OUTPUT);
pinMode(knapp, INPUT);
}

void loop() {
// Setter alt til LOW for å resette
digitalWrite(trigPin, LOW);
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);

//Setter trigpinnen til HIGH i 10 microsekunder
digitalWrite(trigPin, HIGH);
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
digitalWrite(trigPin2, LOW);

// Leser av echoPin, og returnerer lydbølgenes reisetid i mikrosekunder
duration = pulseIn(echoPin, HIGH);
duration2 = pulseIn(echoPin2, HIGH);

// Kalkulerer distansen
distance= duration*0.034/2;
distance2= duration2*0.034/2;


// Dersom sensoren blir krysset, altsaa at distansen ultralydmaaleren klarer aa male blir
// mindre enn 100 cm, settes led lyset til HIGH
if (distance < 100){
  digitalWrite(led, HIGH);
}
if (distance2 < 100){
  digitalWrite(led, HIGH);
}

// Dersom knappen blir trykket inn, gaar det stroem gjennom, saa digitalRead blir HIGH
  if (digitalRead(knapp) == HIGH){
    if (erTrykket(knapp)){
      digitalWrite(led, LOW);
    }
  }
}

unsigned long previousClick = 0;
unsigned long debounceDelay = 150;

// Modul faar a registrere om knappen er trykket ved hjelp av millis istedet for delay
boolean erTrykket(int pin){
  if ((millis() - previousClick) >=debounceDelay){
    previousClick = millis();
    return true;
  }
  return false;
}
