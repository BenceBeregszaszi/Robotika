#define r 9
#define g 7
#define b 8
#define rotary1 6
#define rotary2 5
#define rotary3 
#define lcd0 3
#define lcd1 2
#define barometerscl 3
#define barometersda 2
#define speaker 4
#define waterlsensor 20
#define rht 18
#define ldr 19

void setup() {
Serial.begin(9600);
pinMode(btn, INPUT);
pinMode(r, OUTPUT);
pinMode(g, OUTPUT);
pinMode(b, OUTPUT);
pinMode(rotary1, INPUT);
pinMode(rotary2, INPUT);
pinMode(rotary3, INPUT);
pinMode(lcd0, OUTPUT);
pinMode(lcd1, OUTPUT);
pinMode(barometerscl, INPUT);
pinMode(barometersda, INPUT);
pinMode(speaker, OUTPUT);
pinMode(waterlsensor, INPUT);
pinMode(rht, INPUT);
pinMode(ldr, INPUT);
}

void loop() {

}
