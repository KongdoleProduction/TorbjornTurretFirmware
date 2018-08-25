#include "launcher.hpp"
#include "pins.hpp"
#include <Servo.h>

namespace launcher {
  bool _isArmed = false;

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
    bolt_l.writeMicroseconds(BOLT_SERVO_L_PUSH);
    bolt_r.writeMicroseconds(BOLT_SERVO_R_PUSH);

    barrel_l.attach(pins::BARREL_SERVO_L);
    barrel_r.attach(pins::BARREL_SERVO_R);
    barrel_l.writeMicroseconds(BARREL_SERVO_L_PUSH);
    barrel_r.writeMicroseconds(BARREL_SERVO_R_PUSH);
  }

  void arm() {
    roller_l1.writeMicroseconds(ROLLER_MAX);
    roller_l2.writeMicroseconds(ROLLER_MAX);
    roller_r1.writeMicroseconds(ROLLER_MAX);
    roller_r2.writeMicroseconds(ROLLER_MAX);

    _isArmed = true;
  }

  void disarm() {
    roller_l1.writeMicroseconds(ROLLER_IDLE);
    roller_l2.writeMicroseconds(ROLLER_IDLE);
    roller_r1.writeMicroseconds(ROLLER_IDLE);
    roller_r2.writeMicroseconds(ROLLER_IDLE);

    _isArmed = false;
  }

  bool isArmed() {
    return _isArmed;
  }

  void fire_left() {
    bolt_l.writeMicroseconds(BOLT_SERVO_L_PULL);
    delay(300);
    bolt_l.writeMicroseconds(BOLT_SERVO_L_PUSH);
    //barrel_l.writeMicroseconds(BARREL_SERVO_L_PULL);
    //delay(50);
    //barrel_l.writeMicroseconds(BARREL_SERVO_L_PUSH);
    //delay(100);
  }

  void fire_right() {
    bolt_r.writeMicroseconds(BOLT_SERVO_R_PULL);
    delay(300);
    bolt_r.writeMicroseconds(BOLT_SERVO_R_PUSH);
    //barrel_r.writeMicroseconds(BARREL_SERVO_R_PULL);
    //delay(50);
    //barrel_r.writeMicroseconds(BARREL_SERVO_R_PUSH);
    //delay(100);
  }

  void fire_one() {
    static bool toggle_lr = false;

    if (!toggle_lr) {
      fire_left();
      toggle_lr = true;
    } else {
      fire_right();
      toggle_lr = false;
    }
  }
  
}
