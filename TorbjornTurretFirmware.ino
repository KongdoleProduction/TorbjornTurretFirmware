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

  dx::ping(0xFE);
  delay(5000);

  dx::torque_enable(1, true);
  delay(10);
  dx::torque_enable(2, true);
  delay(10);

  dx::move(1, 2048);
  delay(10);
  dx::move(2, 2048);
  delay(10);

  delay(1000);

  pan_controller::init();
  pan_controller::move(0);
  
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

  uint16_t tilt_ang_1 = map(rc[2], 970, 2030, 0, 4095);
  uint16_t tilt_ang_2 = map(rc[2], 970, 2030, 4095, 0);
  dx::move(1, tilt_ang_1);
  delay(10);
  dx::move(2, tilt_ang_2);

  float pan_speed = ((float)rc[1] - 1500) / 520;
  pan_controller::move(pan_speed);

  delay(50);
}
