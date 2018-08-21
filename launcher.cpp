#include "launcher.hpp"
#include "pins.hpp"
#include <Servo.h>

namespace launcher {

  Servo roller_l1;
  Servo roller_l2;
  Servo roller_r1;
  Servo roller_r2;

  Servo bolt_l;
  Servo bolt_r;
  
  Servo barrel_l;
  Servo barrel_r;

  void init() {
    roller_l1.attach(pins::ESC_1_PIN);
    roller_l2.attach(pins::ESC_2_PIN);
    roller_r1.attach(pins::ESC_3_PIN);
    roller_r2.attach(pins::ESC_4_PIN);
    disarm();

    bolt_l.attach(pins::BOLT_SERVO_L);
    bolt_r.attach(pins::BOLT_SERVO_R);

    barrel_l.attach(pins::BARREL_SERVO_L);
    barrel_r.attach(pins::BARREL_SERVO_R);
  }

  void arm() {
    roller_l1.writeMicroseconds(ROLLER_MAX);
    roller_l2.writeMicroseconds(ROLLER_MAX);
    roller_r1.writeMicroseconds(ROLLER_MAX);
    roller_r2.writeMicroseconds(ROLLER_MAX);
  }

  void disarm() {
    roller_l1.writeMicroseconds(ROLLER_IDLE);
    roller_l2.writeMicroseconds(ROLLER_IDLE);
    roller_r1.writeMicroseconds(ROLLER_IDLE);
    roller_r2.writeMicroseconds(ROLLER_IDLE);
  }

  void fire_left() {
  }

  void fire_right() {
  }
  
}
