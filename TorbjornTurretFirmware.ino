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
  move_manual();
  //move_auto();
}

void move_manual() {
  static int tilt_desired = 0;
  int rc[6]; 
  receiver::readReceiver(rc);
  for (int i=0; i<6; i++) {
    Serial.print(rc[i]);
    Serial.print(" ");
  }
  Serial.println("");

  int tilt_desired_diff = rc[2] - receiver::RC3_MID;
  tilt_desired_diff = - tilt_desired_diff;
  if (abs(tilt_desired_diff) < 10) tilt_desired_diff = 0;
  tilt_desired += (tilt_desired_diff >> 4);
  tilt_desired = constrain(tilt_desired, -150, 550);
  Serial.println(tilt_desired);
  dx::move(1, 2048 + tilt_desired);
  delay(5);
  dx::move(2, 1980 - tilt_desired);

  float pan_speed = ((float)rc[1] - receiver::RC2_MID) / (receiver::RC2_MAX - receiver::RC2_MID);
  pan_controller::move(-pan_speed);

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

void move_auto() {
  int tilt_desired;
  float pan_speed;

  tilt_desired = random(-100, 400);
  pan_speed = random(-0.5, 0.5);

  for (int i=0; i<5; i++) {
    int tilt_diff = float(tilt_desired) * i / 20.0; 
    dx::move(1, 2048 + tilt_diff);
    delay(5);
    dx::move(2, 1980 - tilt_diff);

    if (pan_speed > 0.4 || pan_speed < -0.4) {
      pan_controller::move(pan_speed);
    }

    delay(50);
  }

  delay(1500);
}
