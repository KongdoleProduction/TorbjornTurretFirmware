#include "dynamixel.hpp"
#include "launcher.hpp"
#include "pan_controller.hpp"
#include "receiver.hpp"

void setup()
{
  receiver::init();
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
  int rc[6]; 
  receiver::readReceiver(rc);
  for (int i=0; i<6; i++) {
    Serial.print(rc[i]);
    Serial.print(" ");
  }
  Serial.println("");

  delay(50);
}
