#include "pins.hpp"

namespace pins {

  void init() {
    pinMode(PAN_MOTOR_DRV_IN1, OUTPUT);
    pinMode(PAN_MOTOR_DRV_IN2, OUTPUT);
    pinMode(PAN_MOTOR_DRV_EN, OUTPUT);
    pinMode(PAN_MOTOR_HALL_A, INPUT);
    pinMode(PAN_MOTOR_HALL_B, INPUT);

    pinMode(DX_TTL_TX_EN, OUTPUT);

    /*pinMode(RC_RX1, OUTPUT);
    pinMode(RC_RX2, OUTPUT);
    pinMode(RC_RX3, OUTPUT);
    pinMode(RC_RX4, OUTPUT);
    pinMode(RC_RX5, OUTPUT);
    pinMode(RC_RX6, OUTPUT);*/
  }
}
