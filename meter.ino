#include <LiquidCrystal.h>

// LiquidCrystal lcd(Rs, Enable, 4, 5, 6, 7);

LiquidCrystal lcd(9, 8, 4, 5, 6, 7);

int lcd_setup_time = 1000;

String str = "Resistance Meter ";


int volt_1023;

float converter = (5./1023.);

float volt_real;


int measure = A5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  

  pinMode(measure, INPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print(str);
 

  delay(lcd_setup_time);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  

  for(int i = 0; i < 3; i++){
    lcd.setCursor(i,1);
    lcd.print(" ");
  }

  lcd.setCursor(0, 1); 
  volt_1023 = analogRead(measure);
  volt_real = converter * volt_1023; // Map the analog reading to a voltage range
  int resistance = (volt_real * 1000) / (5 - volt_real);


  Serial.println(volt_real * 1000);
  Serial.println(5 - volt_real);
  Serial.println(resistance);
   

  lcd.setCursor(0, 1); // Set the cursor to the second row of the LCD


  if(resistance > 1000){  
    double _resistance = resistance / 1000.0;
    lcd.print("V:");
    lcd.print(volt_real, 2); // Display the voltage on the LCD with 2 decimal places
    lcd.print(" R:");
    lcd.print(_resistance,2);
    lcd.print("k");
    lcd.setCursor(14,1);
    lcd.print("     ");
  }
  else{
    lcd.print("V:");
    lcd.print(volt_real, 2); // Display the voltage on the LCD with 2 decimal places
    lcd.print(" R:");
    lcd.print(resistance);
    lcd.setCursor(12,1);
    lcd.print("     ");
  }

  
  delay(500); // Delay for readability, adjust as needed
  
}
