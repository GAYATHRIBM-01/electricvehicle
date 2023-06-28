#include <LiquidCrystal.h> 

const int analogInput = A1;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
 
  Serial.begin(9600);
  pinMode(analogInput, INPUT);
   lcd.begin(16, 2);
  // Print a message to the LCD.
  if (B1>B2)
  lcd.print("B2 is selected");
  else
  lcd.print("B1 is selected");
 
}

void loop(){
  Serial.print(getCurrent());  
  Serial.print(" "); 
  Serial.println(getVoltage(),2);
  delay(500);
  lcd.noDisplay();
  delay(500);
  // Turn on the display:
  lcd.display();
  delay(500);
}

float getCurrent() {    
  float average = 0;
  for(int i = 0; i < 1000; i++) {
    average = average + (.0264 * analogRead(A0) -13.385) / 1000;//this is 
   //for the 5A mode, if 20A or 30A mode, need to modify this formula to s
    //(.19 * analogRead(A0) -25) for 20A mode and 
    //(.044 * analogRead(A0) -3.78) for 30A mode
    delay(3);
  }
return average;
}

float getVoltage() {
   const float R1 = 30000.0; //  
   const float R2 = 7500.0; // 
   float value = analogRead(analogInput);
   float vout = (value * 5.0) / 1024.0; // see text
   float vin = vout / (R2/(R1+R2)); 
  return vin;
}
