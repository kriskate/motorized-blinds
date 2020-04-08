#include <Arduino.h>
#include <SparkFunSX1509.h>

class MotorBi
{
private:
  void (*print)(String str);

  int dirPin;
  int stepPin;
  bool ccw = false;
  int delay = 3000;

  long max = 2000000;
  long current = 0;

  void step()
  {
    digitalWrite(dirPin, HIGH);
    digitalWrite(stepPin, HIGH);
    current += ccw ? -1 : 1;

    delayMicroseconds(delay);
  }

public:
  MotorBi(){};
  MotorBi(int dirPin, int stepPin, void (*print)(String str))
  {
    this->print = print;

    this->dirPin = dirPin;
    this->stepPin = stepPin;

    pinMode(dirPin, OUTPUT);
    pinMode(stepPin, OUTPUT);
  }

  void setMin()
  {
    current = 0;
  }
  void setMax()
  {
    max = current;
  }

  void stop()
  {
    digitalWrite(stepPin, LOW);
  }

  void rotateCCW()
  {
    if (!ccw)
      ccw = true;
    step();
  }
  void rotateCW()
  {
    if (ccw)
      ccw = false;
    step();
  }
};
