#include <Arduino.h>

#include <MotorBi.h>

class Motors
{
private:
  void (*print)(String str);

  bool ccw = false;
  int currentDir = 1; // -1
  bool autoMoving = false;

public:
  Motors() {}

  void setup(int dirPin, int stepPins[3], void (*print)(String str))
  {
    this->print = print;

    for (int i = 0; i < 3; ++i)
      motors[i] = MotorBi(dirPin, stepPins[i], print);
  }
  MotorBi motors[3];

  // move motor checks
  void loop()
  {
    // if (sound) {  }
    // if websocket
    // if mqtt
    // if button

    test();
  }
  void test()
  {
    if (millis() <= 5000)
    {
      print("moving up");
      moveUp();
    }
    else
      stop();
  }

  void stop(int motorID = -1)
  {
    if (motorID == -1)
      for (int i = 0; i < 3; ++i)
        motors[i].stop();
    else
      motors[motorID].stop();
  }

  void moveDown(int motorID = 1)
  {
    if (motorID == -1)
      for (int i = 0; i < 3; ++i)
        goDown(i);
    else
      goDown(motorID);
  }
  void goDown(int motorID)
  {
    ccw ? motors[motorID].rotateCCW() : motors[motorID].rotateCW();
  }

  void moveUp(int motorID = -1)
  {
    if (motorID == -1)
      for (int i = 0; i < 3; ++i)
        goUp(i);
    else
      goUp(motorID);
  }
  void goUp(int motorID)
  {
    ccw ? motors[motorID].rotateCW() : motors[motorID].rotateCCW();
  }
};
