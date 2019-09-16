#ifndef __LAUNCHER_HPP_
#define __LAUNCHER_HPP_

#include <Servo.h>

namespace launcher {
  const uint16_t ROLLER_IDLE = 980;
  const uint16_t ROLLER_MAX  = 1350;

  const uint16_t BOLT_SERVO_L_PUSH = 1000;
  const uint16_t BOLT_SERVO_L_PULL = 1850;
  const uint16_t BOLT_SERVO_R_PUSH = 1900;
  const uint16_t BOLT_SERVO_R_PULL = 1100;
  
  const uint16_t BARREL_SERVO_L_PUSH = 1200;
  const uint16_t BARREL_SERVO_L_PULL = 1200;
  const uint16_t BARREL_SERVO_R_PUSH = 1900;
  const uint16_t BARREL_SERVO_R_PULL = 1900;

  void init();
  void arm();
  void disarm();
  bool isArmed();
  void fire_left();
  void fire_right();
  void fire_one();
}

#endif
