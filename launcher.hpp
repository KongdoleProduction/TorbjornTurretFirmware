#ifndef __LAUNCHER_HPP_
#define __LAUNCHER_HPP_

#include <Servo.h>

namespace launcher {
  const uint16_t ROLLER_IDLE = 980;
  const uint16_t ROLLER_MAX  = 1700;

  const uint16_t BOLT_SERVO_L_PUSH = 1850;
  const uint16_t BOLT_SERVO_L_PULL = 1150;
  const uint16_t BOLT_SERVO_R_PUSH = 1200;
  const uint16_t BOLT_SERVO_R_PULL = 2000;
  
  const uint16_t BARREL_SERVO_L_PUSH = 1050;
  const uint16_t BARREL_SERVO_L_PULL = 1250;
  const uint16_t BARREL_SERVO_R_PUSH = 2000;
  const uint16_t BARREL_SERVO_R_PULL = 1800;

  void init();
  void arm();
  void disarm();
  bool isArmed();
  void fire_left();
  void fire_right();
  void fire_one();
}

#endif
