const int FLEX_PIN = A0;
int standardFlex = 670;
int knapp = 3;
unsigned long millis2 = millis();

void setup() 
{
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

  if (flexADC > standardFlex+30){
    if (millis() - millis2 > 150){
    Serial.println("FOR KRUM RYGG");
    Serial.print("Feil ble gjort ");
    Serial.print(millis()/1000);
    Serial.println(" sekunder ut i settet");
    Bean.setLed(255, 0, 0); //Roedt
    }
  }
  else if (flexADC < standardFlex-50){
    if (millis() - millis2 > 150){
    //Serial.println("FOR MYE SVAI!"); //Trenger ikke svai utslag
    Bean.setLed(255, 0, 0); // Roedt
    }
  }
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
