#include <LiquidCrystal.h>

// LiquidCrystal lcd(Rs, Enable, 4, 5, 6, 7);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int lcd_setup_time = 1000;

const double UPPER_VOLTAGE_THRESHOLD = 4.8;
const double LOWER_VOLTAGE_THRESHOLD = 0.2;

String str = "Resistance Meter ";

int volt_1023;
float converter = (5.0 / 1023.0);
float volt_real;

int measure = A5;
long r_ref;
bool use_high_resistance = false; 

void setup() {
    Serial.begin(9600);
    pinMode(measure, INPUT);

    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print(str);
    delay(lcd_setup_time);
}

void loop() {
  
    r_ref = use_high_resistance ? 100000 : 1000;

    lcd.setCursor(0, 1);
    lcd.print("                "); // Clear the second row

    lcd.setCursor(0, 1);

    volt_1023 = analogRead(measure);
    volt_real = converter * volt_1023;

    // Voltage threshold check with tolerance
    if (volt_real > UPPER_VOLTAGE_THRESHOLD) {
        lcd.print("Change to 100k.");
        use_high_resistance = true;
        return;
    }

    if (volt_real < LOWER_VOLTAGE_THRESHOLD) {
        lcd.print("Change to 1k.");
        use_high_resistance = false;
        return;
    }

    unsigned long resistance = (volt_real * r_ref) / (5.0 - volt_real);

    lcd.setCursor(0, 1);

    lcd.print("V:");
    lcd.print(volt_real, 2);
    lcd.print(" R:");

    // Display resistance with units
    if (resistance > 1000 && resistance < 1000000) {
        double _resistance = resistance / 1000.0;
        lcd.print(_resistance, 2);
        lcd.print("k");
    } else if (resistance >= 1000000) {
        double _resistance = resistance / 1000000.0;
        lcd.print(_resistance, 2);
        lcd.print("M");
    } else {
        lcd.print(resistance);
    }

    delay(300); 
}
