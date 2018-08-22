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
  dx::move(2, 1980);
  delay(10);

  pan_controller::init();
  pan_controller::move(0);
  
  launcher::init();
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

  uint16_t tilt_ang_1 = map(rc[2], 970, 2030, 1700, 2395);
  uint16_t tilt_ang_2 = map(rc[2], 970, 2030, 2395, 1700);
  dx::move(1, tilt_ang_1);
  delay(5);
  dx::move(2, tilt_ang_2 - 70);

  float pan_speed = ((float)rc[1] - receiver::RC2_MID) / (receiver::RC2_MAX - receiver::RC2_MID);
  Serial.println(pan_speed);
  pan_controller::move(pan_speed);

  if (rc[4] > receiver::RC5_MID) {
    launcher::arm();
  } else {
    launcher::disarm();
  }

  if (rc[5] > receiver::RC6_MID && launcher::isArmed()) {
    launcher::fire_one();
  }

  delay(50);
}
