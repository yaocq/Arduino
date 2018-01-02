#include <ChainableLED.h>
#define NUM_LEDS  3
ChainableLED leds(7, 8, NUM_LEDS);

//按钮
int buttonvalue = 0;
//初始针脚设定
int buttoninput = 3;
//总控
float ebrightness = 25;
float brightness2 = 0.4;
float hue1 = 0.67;
float hue2 = 0.97;
//触摸
int chumoinput = 2;
boolean chumovalue = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttoninput, INPUT);
  pinMode(chumoinput,INPUT);
  leds.init();
  for (byte led = 0; led < NUM_LEDS; led++)
    leds.setColorHSB(led, hue1, 1.0, brightness2);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonvalue = digitalRead (buttoninput);
  if (buttonvalue == 1) {
    for (byte led = 0; led < NUM_LEDS; led++)
      leds.setColorHSB(led, hue2, 1.0, brightness2);
  }
  chumovalue = digitalRead (chumoinput);
  if(chumovalue==true){
    for (byte led = 0; led < NUM_LEDS; led++)
      leds.setColorHSB(led, hue1, 1.0, brightness2);
  }
  delay(300);
}

