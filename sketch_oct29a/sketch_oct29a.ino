#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
double x = 0.0;
double y = 0.0;
double z = 0.0;
double a = 0.0;
double b = 0.0;

void setup()
{
  pinMode(A0, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  x = analogRead(A0); 
  z = x*5/1023;
  a = 1000*((5/z)-1);
  b = pow(a/6012.4,-1/0.701);
  y = ((b/9.81)*1000);
  lcd.setCursor(0, 0);
  lcd.print("Fuerza: ");
  lcd.print(b,3);
  lcd.print(" N");
  lcd.setCursor(0, 1);
  lcd.print("Peso: ");
  lcd.print(y,3);
  lcd.print(" gr");
  delay(500);
  lcd.clear();
}
