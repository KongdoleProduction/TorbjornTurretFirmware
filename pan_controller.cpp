#include "pan_controller.hpp"
#include "pins.hpp"
#include <Arduino.h>

using namespace pins;

namespace pan_controller {
  void init() {
    pinMode(PAN_MOTOR_DRV_IN1, OUTPUT);
    pinMode(PAN_MOTOR_DRV_IN2, OUTPUT);
    pinMode(PAN_MOTOR_DRV_EN, OUTPUT);
    pinMode(PAN_MOTOR_HALL_A, INPUT);
    pinMode(PAN_MOTOR_HALL_B, INPUT);

    move(0);
  }

  // positive value: clockwise
  void move(float speed) {
    if (speed < MOTOR_DEADZONE &&
        speed > - MOTOR_DEADZONE) {
      digitalWrite(PAN_MOTOR_DRV_IN1, LOW);
      digitalWrite(PAN_MOTOR_DRV_IN2, LOW);
    } else if (speed > 0) {
      digitalWrite(PAN_MOTOR_DRV_IN1, LOW);
      digitalWrite(PAN_MOTOR_DRV_IN2, HIGH);
      analogWrite(PAN_MOTOR_DRV_EN, speed * 255);
    } else if (speed < 0) {
      digitalWrite(PAN_MOTOR_DRV_IN1, HIGH);
      digitalWrite(PAN_MOTOR_DRV_IN2, LOW);
      analogWrite(PAN_MOTOR_DRV_EN, -speed * 255);
    }
  }
}
