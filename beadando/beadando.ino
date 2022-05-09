
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_I2C.h>

#define sealevel 1013.25
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
#define rht 18
#define ldr 19
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
Adafruit_BMP085 bmp;


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
pinMode(barometerscl, INPUT);
pinMode(barometersda, INPUT);
pinMode(speaker, OUTPUT);
pinMode(waterlsensor, INPUT);
pinMode(rht, INPUT);
pinMode(ldr, INPUT);
lastCLK = digitalRead(rotary_clk);
btn_on = 0;
i = 1;
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
    Serial.print(i);
  }
  lastCLK = currentCLK;
  btn_value = digitalRead(rotary_sw);
  if(btn_value == LOW && btn_on == 0){
    btn_on = 1;
  }
  if(btn_value == LOW && btn_on == 1){
    btn_on = 0;
  }
  if(btn_on == 1){
    switch(i){
    case 1:
      bmp_temp = bmp.readTemperature();
      break;
    case 2:
      bmp_pressure = bmp.readPressure();
      break;
    case 3:
      bmp_altitude = bmp.readAltitude();
      break;
    case 4:
      break;
    case 5:
      ldr_light = analogRead(ldr);
      break;
    case 6:
      break;
  }  
  } 
}
