#include <Wire.h>
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
#define r 9
#define g 7
#define b 8
#define rotary_dt 6
#define rotary_clk 5
#define rotary_sw 16
#define lcd0 3
#define lcd1 2
#define barometerscl 3
#define barometersda 2
#define speaker 4
#define waterlsensor 20
#define ldr 19
#define dht_pin 18
#define DHTTYPE DHT11
#include <DHT.h>
DHT dht(dht_pin, DHTTYPE);
int i;
int currentCLK;
int lastCLK;
unsigned long lastbutton;
int temp;
int btn_value;
int btn_on;
float bmp_temp;
float bmp_pressure;
float bmp_altitude;
float dht_value;
float value;
int ldr_light;
int water_value;
String message;
String temp_string;
int lastState;
int buttonPress(){
  int state;
  int button = digitalRead(rotary_sw);
  if(button == LOW){
    if(lastState == 0){
      lastState = 1;
      tone(speaker, 3000);
      delay(500);
      noTone(speaker);
      }
    else if(lastState == 1){
      lastState = 0;
      tone(speaker, 2000);
      delay(500);
      noTone(speaker);
      lcd.clear();
      }
  }
  
}



void setup() {
Serial.begin(9600);
pinMode(r, OUTPUT);
pinMode(g, OUTPUT);
pinMode(b, OUTPUT);
pinMode(rotary_dt, INPUT);
pinMode(rotary_clk, INPUT);
pinMode(rotary_sw, INPUT_PULLUP);
pinMode(lcd0, OUTPUT);
pinMode(lcd1, OUTPUT);
pinMode(speaker, OUTPUT);
pinMode(waterlsensor, INPUT);
pinMode(ldr, INPUT);
lcd.init();
lcd.init();
lcd.backlight();
dht.begin();
bmp.begin();
lastCLK = digitalRead(rotary_clk);
btn_on = 0;
i = 1;
lastState = 0;
}

void loop() {
  currentCLK = digitalRead(rotary_clk);
  if(currentCLK != lastCLK && currentCLK == 1){
    if(digitalRead(rotary_dt) != currentCLK){
     i --;
    }
    else {
      i ++;
    }
  }
  lastCLK = currentCLK;
  buttonPress();
  if(lastState == 0){
    digitalWrite(g, HIGH);
    analogWrite(r, 0);
  }
  else {
    digitalWrite(g, LOW);
    analogWrite(r, 255);
  }
  if(lastState == 1){
    switch(i){
    case 1:
      dht_value = dht.readTemperature();
      bmp_temp = bmp.readTemperature();
      value = (dht_value + bmp_temp)/2;
      lcd.setCursor(0,0);
      lcd.print("  Temperature:  ");
      lcd.setCursor(0,1);
      temp_string = String(value);
      message ="  " + temp_string + " Celsius  ";
      lcd.print(message);
      break;
    case 2:
      bmp_pressure = bmp.readPressure();
      lcd.setCursor(0,0);
      lcd.print("   Pressure:    ");
      lcd.setCursor(0,1);
      temp_string = String(bmp_pressure);
      message = "   " + temp_string + " Bar  ";
      lcd.print(message);
      break;
    case 3:
      bmp_altitude = bmp.readAltitude();
      lcd.setCursor(0,0);
      lcd.print("   Altitude:    ");
      lcd.setCursor(0,1);
      temp_string = String(bmp_altitude);
      message = "     " + temp_string + " m    ";
      lcd.print(message);
      break;
    case 4:
      water_value = analogRead(waterlsensor);
      lcd.setCursor(0,0);
      lcd.print("      Rain:     ");
      lcd.setCursor(0,1);
      if(water_value > 800){
        lcd.print("      Dry       ");
      }else if(water_value > 500 && water_value < 800){
        lcd.print("  Intermediate  ");
      }
      else{
        lcd.print("      Rain      ");
      }
      Serial.println(water_value);
      message = "    " + temp_string + " mm      ";
      lcd.print(message);
      break;
    case 5:
      ldr_light = analogRead(ldr);
      lcd.setCursor(0,0);
      lcd.print("  Birghtness:   ");
      lcd.setCursor(0,1);
      temp_string = String(ldr_light);
      message = "   " + temp_string + " lumen   ";
      lcd.print(message);
      break;
    case 6:
      dht_value = dht.readHumidity();
      lcd.setCursor(0,0);
      lcd.print("    Humidity:   ");
      lcd.setCursor(0,1);
      temp_string = String(dht_value);
      message = "     " +temp_string + " %    ";
      lcd.print(message);
      break;
    default:
      if(i < 1){
        i = 6;
        }
        else{
          i = 1;
          }
    break;
  }  
  } 
}
