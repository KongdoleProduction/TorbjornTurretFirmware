#include "dynamixel.hpp"
#include "launcher.hpp"

void setup()
{
  Serial.begin(115200);
  dx::init();
  Serial.println("Begin!");

  dx::torque_enable(true);

  delay(1000);

  dx::move(512);

  delay(1000);
  
  launcher::init();
  delay(5000);
  launcher::arm();
  delay(5000);
  launcher::disarm();
  
}

void loop()
{
}
