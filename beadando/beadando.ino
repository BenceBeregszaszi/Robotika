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
if(button != lastState){
if(button == HIGH){
state = 1;
}
else{
state = 0;
}
lastState = button;
Serial.print(lastState);
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
//pinMode(waterlsensor, INPUT);
pinMode(ldr, INPUT);
lcd.init();
lcd.init();
lcd.backlight();
dht.begin();
bmp.begin();
lastCLK = digitalRead(rotary_clk);
btn_on = 0;
i = 1;
Serial.println("VOID SETUP IS READY");
}

void loop() {
  Serial.println("LOOP");
  currentCLK = digitalRead(rotary_clk);
  if(currentCLK != lastCLK && currentCLK == 1){
    if(digitalRead(rotary_dt) != currentCLK){
     i --;
    }
    else {
      i ++;
    }
    Serial.println(i);
  }
  lastCLK = currentCLK;
  /*
  btn_value = digitalRead(rotary_sw);
  if(btn_value == LOW && btn_on == 0){
    btn_on = 1;
    Serial.print(btn_on);
  }
  if(btn_value == LOW && btn_on == 1){
    btn_on = 0;
    Serial.print(btn_on);
  }
  */
  buttonPress();
  Serial.println("Button Press után");
  if(lastState == 1){
    switch(i){
    case 1:
      Serial.println("Switch 1");
      dht_value = dht.readTemperature();
      Serial.println("bmp-k után");
      value = (dht_value + dht_value)/2;
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Hőmérséklet: ");
      lcd.setCursor(3,1);
      temp_string = String(value);
      message = temp_string + " C*";
      lcd.print(bmp.readTemperature());
      Serial.println(message);
      break;
    case 2:
      Serial.println("switch 2");
      bmp_pressure = bmp.readPressure();
      Serial.println("bmp 2");
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Légnyomás: ");
      lcd.setCursor(3,1);
      temp_string = String(bmp_pressure);
      message = temp_string + " Bar";
      lcd.print(message);
      break;
    case 3:
      bmp_altitude = bmp.readAltitude();
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Magasság: ");
      lcd.setCursor(3,1);
      temp_string = String(bmp_altitude);
      message = temp_string + " m";
      lcd.print(message);
      break;
    case 4:
      water_value = analogRead(waterlsensor);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Vizszint magasság: ");
      lcd.setCursor(3,1);
      temp_string = String(water_value);
      message = temp_string + " ml";
      lcd.print(message);
      break;
    case 5:
      ldr_light = analogRead(ldr);
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Fény mennyisége: ");
      lcd.setCursor(3,1);
      temp_string = String(ldr_light);
      message = temp_string + " lumen";
      lcd.print(message);
      break;
    case 6:
      dht_value = dht.readHumidity();
      lcd.clear();
      lcd.setCursor(1,0);
      lcd.print("Páratartalom: ");
      lcd.setCursor(3,1);
      temp_string = String(dht_value);
      message = temp_string + " %";
      lcd.print(message);
      break;
    default:
    i = 1;
    break;
  }  
  } 
}
