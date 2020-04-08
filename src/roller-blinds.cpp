#include <Arduino.h>
#include <GPIOE.h>

SX1509 io;

void print(String str)
{
  Serial.println(str);
}

void setup()
{
  Serial.begin(76800);
  print("starting up... ");

  setupGPIOandMotors(io, print);
}

int idx = 0;
void loop()
{
  // print("breathe " + String(idx++));

  motors.loop();
}