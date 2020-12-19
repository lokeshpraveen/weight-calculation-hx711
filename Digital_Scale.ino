// Digital Scale using Arduino By Engr. USMAN AHMAD
// Easy HomeMade Projects YouTube Channel


#include <HX711_ADC.h> // https://github.com/olkal/HX711_ADC
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // LiquidCrystal_I2C library
HX711_ADC LoadCell(4, 5); // parameters: dt pin, sck pin
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
int led = 2;
int taree = 6;
int buzzer = 10;
int a = 0;
float b = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode (taree, INPUT_PULLUP);
  LoadCell.begin(); // start connection to HX711
  LoadCell.start(1000); // load cells gets 2000ms of time to stabilize
  LoadCell.setCalFactor(832.10); // calibration factor for load cell => strongly dependent on your individual setup
  lcd.begin(); // begins connection to the LCD module
  lcd.backlight(); // turns on the backlight

  tone(buzzer, 1200);
  delay(100);
  noTone(buzzer);
  
  lcd.setCursor(1, 0); // set cursor to first row
  lcd.print("Digital Scale "); // print out to LCD
  lcd.setCursor(0, 1); // set cursor to first row
  lcd.print("By: Engr. USMAN"); // print out to LCD
delay(3000);
lcd.clear();
  tone(buzzer, 1200);
  delay(300);
  noTone(buzzer);
  
}
void loop() { 

  lcd.setCursor(1, 0); // set cursor to first row
  lcd.print("Digital Scale "); // print out to LCD
  
  LoadCell.update(); // retrieves data from the load cell
  float i = LoadCell.getData(); // get output value
 if (i<0)
 {
  i = i * (-1);
  lcd.setCursor(0, 1);
  lcd.print("-");
   lcd.setCursor(8, 1);
  lcd.print("-");
 }
 else
 {
   lcd.setCursor(0, 1);
  lcd.print(" ");
   lcd.setCursor(8, 1);
  lcd.print(" ");
 }
  
  lcd.setCursor(1, 1); // set cursor to secon row
  lcd.print(i, 1); // print out the retrieved value to the second row
  lcd.print("g ");
  float z = i/28.3495;
  lcd.setCursor(9, 1);
  lcd.print(z, 2);
  lcd.print("oz ");

  if (i>=1000)
  {
    i=0;
   tone(buzzer, 1600);
  delay(200);
  noTone(buzzer);
    digitalWrite(led, HIGH);
   lcd.setCursor(0, 0); // set cursor to secon row
  lcd.print("  Over Loaded   "); 
  delay(200);
  }
  digitalWrite(led, LOW);
  if (digitalRead (taree) == HIGH)
  {
  tone(buzzer, 1000);
  delay(100);
  noTone(buzzer);
    digitalWrite(led, HIGH);
    lcd.setCursor(0, 1); // set cursor to secon row
    lcd.print("   Taring...    ");
    LoadCell.start(1000);
     tone(buzzer, 1000);
  delay(300);
  noTone(buzzer);
  lcd.setCursor(0, 1);
   lcd.print("                ");
  }
}
