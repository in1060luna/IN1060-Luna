/**
 * program for aa maale av flex sensoren, og gi riktig feedback
 */

const int FLEX_PIN = A0;
int standardFlex = 670; // Denne endres fra person til person, ettersom alle rygger er forskjellig
int knapp = 3;
unsigned long millis2 = millis();

void setup() 
{
  // Starter Serial overvaakning, og setter pinMode's
  Serial.begin(9600);
  pinMode(FLEX_PIN, INPUT);
  pinMode(knapp, INPUT);
}

void loop() 
{
  // Leser av flex sensoren
  int flexADC = analogRead(FLEX_PIN);
  
  if (millis() - millis2 > 500){
  //Serial.println("AdC :" + String(flexADC));
  millis2 = millis();
  }

  //Dersom flexsensoren er 30 stoerre enn standardFlexen, som er kalibrert utifra brukers rygg
  if (flexADC > standardFlex+30){
    if (millis() - millis2 > 150){
    Serial.println("FOR KRUM RYGG");
    Serial.print("Feil ble gjort ");
    Serial.print(millis()/1000); // For aa finne sekunder
    Serial.println(" sekunder ut i settet");
    Bean.setLed(255, 0, 0); //Roedt
    }
  }
/**
 * Ikke nodvendig aa male svai
 * 
  else if (flexADC < standardFlex-50){
    if (millis() - millis2 > 150){
    //Serial.println("FOR MYE SVAI!"); //Trenger ikke svai utslag
    Bean.setLed(255, 0, 0); // Roedt
    }
  }
**/
  else {
    Bean.setLed(0, 255, 0); //Groent
  }
}
/**
 * Knappen er kommentert bort
 
  if (digitalRead(knapp) == HIGH){
    if (erTrykket(knapp)){
      standardFlex = flexADC;
      Serial.println("Standard er endret til: " + String(standardFlex));
    }
  }
}

unsigned long previousClick = 0;
unsigned long debounceDelay = 150;

boolean erTrykket(int pin){
  if ((millis() - previousClick) >=debounceDelay){
    previousClick = millis();
    return true;
  }
  return false;
}
**/
