#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "noDelayTimer.h"

#define PinLED 2
#define WS2812LED 5

Adafruit_NeoPixel neoPixel(1, WS2812LED, NEO_GRB + NEO_KHZ800);

int ledPWM = 0;
int stateLED = 0;
bool led2State = false;
int brightness = 0;
noDelayTimer timer1(2000);
noDelayTimer timer1_2(timer1.getInterval() / 250);
noDelayTimer timer2(20);

// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

// ############################################################################################

void setup()
{
  Serial.begin(115200);
  pinMode(PinLED, OUTPUT);
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(PinLED, ledChannel);

  neoPixel.begin();
  timer1.startTimer();
  timer1_2.startTimer();
  timer2.startTimer();
}

void loop()
{
  if (timer1.isTriggered()) // run every 2000ms
  {
    Serial.printf("Timer Triggered @ %ldms\r\n", millis());
    stateLED++;
    if (stateLED > 6)
    {
      // timer1.stopTimer();
      stateLED = 1;
    }
    brightness = 0;
  }

  if (timer1_2.isTriggered()) // trigger every 2000ms/200 times
  {
    brightness++;
    switch (stateLED)
    {
    case 1:
      neoPixel.setPixelColor(0, neoPixel.Color(0, 0, brightness));
      neoPixel.show();
      break;
    case 2:
      neoPixel.setPixelColor(0, neoPixel.Color(0, brightness, 0));
      neoPixel.show();
      break;
    case 3:
      neoPixel.setPixelColor(0, neoPixel.Color(brightness, 0, 0));
      neoPixel.show();
      break;
    case 4:
      neoPixel.setPixelColor(0, neoPixel.Color(0, brightness, brightness));
      neoPixel.show();
      break;
    case 5:
      neoPixel.setPixelColor(0, neoPixel.Color(brightness, brightness, 0));
      neoPixel.show();
      break;
    case 6:
      neoPixel.setPixelColor(0, neoPixel.Color(brightness, 0, brightness));
      neoPixel.show();
      break;
    default:
      neoPixel.setPixelColor(0, neoPixel.Color(0, 0, 0));
      neoPixel.show();
      stateLED = 1;
      break;
    }
  }

  if (timer2.isTriggered()) // run every 20ms
  {
    // Serial.println("Timer 2 Triggered");
    ledcWrite(ledChannel, ledPWM);
    if (led2State)
    {
      ledPWM--;
    }
    else
    {
      ledPWM++;
    }
    if (ledPWM >= 255 && !led2State)
    {
      led2State = true;
      Serial.printf("LED reset low PWM @ %ldms\r\n", millis());
    }
    else if (ledPWM <= 0 && led2State)
    {
      led2State = false;
      Serial.printf("LED reset high PWM @ %ldms\r\n", millis());
    }
  }
}