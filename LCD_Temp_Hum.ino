/* 
 
                      11    GND   10                            4     5      6    7
   GND   VCC C.POT    RS    RW    E                             D4    D5    D6    D7
    |     |     |     |     |     |     |     |     |     |     |     |     |     | 
    --------------------------------------------------------------------------------
    !                                                                              |
    !                                   LCD                                        |
    !                                                                              |
    !                                                                              |
    --------------------------------------------------------------------------------

* For Alim and GND of Potentiometer define two Digital Pin.

* 
*/
#include <LiquidCrystal.h>  
#include "DHT.h"  
 
#define ALIM_POT 14
#define GND_POT 15
#define TEMP_PIN A8
#define HUM_PIN A9
#define DHTTYPE DHT11

DHT dht(HUM_PIN, DHTTYPE);
float temperature = 0;
float humidity = 0;

LiquidCrystal lcd(11, 10, 4, 5, 6, 7);  

void setup() {  
  pinMode(ALIM_POT, OUTPUT);
  pinMode(GND_POT, OUTPUT);
  digitalWrite(ALIM_POT,HIGH);
  digitalWrite(GND_POT,LOW);
  dht.begin();
  lcd.begin(16, 2);   
  lcd.print("Temp & Humidity reader");
  lcd.setCursor(0, 1);
  lcd.print("Bastianini Mirko");
  delay(1000);
  lcd.clear();   
}  
  
void loop() {
  lcd.setCursor(0, 0);
  humidity = dht.readHumidity();  
  temperature = (5.0 * analogRead(TEMP_PIN) * 100.0) / 1024.0;
  lcd.print("Temp: "); 
  lcd.print(temperature);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  lcd.print(humidity);
  lcd.print(" %");
}  
