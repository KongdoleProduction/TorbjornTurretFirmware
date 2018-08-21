#include "dynamixel.hpp"
#include "launcher.hpp"
#include "pan_controller.hpp"

void setup()
{
  Serial.begin(115200);
  dx::init();

  Serial.println("Begin!");

  dx::torque_enable(true);

  delay(1000);

  dx::move(2048);

  delay(1000);

  pan_controller::init();
  pan_controller::move(1);
  
  launcher::init();
  //delay(5000);
  //launcher::arm();
  //delay(5000);
  //launcher::disarm();
  
}

void loop()
{
}
