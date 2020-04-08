#include <Wire.h>
#include <SparkFunSX1509.h>
#include <Motors.h>

int pins[3] = {0, 1, 2};
int pin_dir = 3;

Motors motors;

// SX1509 I2C address (set by ADDR1 and ADDR0 (00 by default):
const byte SX1509_ADDRESS = 0x3E; // SX1509 I2C address (00)
// const byte SX1509_ADDRESS = 0x3F; // SX1509 I2C address (01)
// const byte SX1509_ADDRESS = 0x70; // SX1509 I2C address (10)
// const byte SX1509_ADDRESS = 0x71; // SX1509 I2C address (11)

void setupGPIOandMotors(SX1509 &io, void (*print)(String str))
{
  print("Initializing GPIO extender...");

  if (!io.begin())
  {
    print("gpio extender failed... restarting in 5 seconds");
    delay(5000);
    ESP.restart();
  }

  io.clock(INTERNAL_CLOCK_2MHZ);

  motors.setup(pin_dir, pins, print);
}