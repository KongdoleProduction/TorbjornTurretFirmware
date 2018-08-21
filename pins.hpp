#ifndef __PINS_HPP_
#define __PINS_HPP_

#include <Arduino.h>

namespace pins {

  const uint8_t PAN_MOTOR_DRV_IN2 = 2;
  const uint8_t PAN_MOTOR_DRV_IN1 = 3;
  const uint8_t PAN_MOTOR_DRV_EN  = 4;
  const uint8_t PAN_MOTOR_HALL_A  = 34;
  const uint8_t PAN_MOTOR_HALL_B  = 36;

  const uint8_t ESC_1_PIN = 6;
  const uint8_t ESC_2_PIN = 7;
  const uint8_t ESC_3_PIN = 5;
  const uint8_t ESC_4_PIN = 9;

  const uint8_t DX_TTL_TX_EN = 8;
  //#define Tilt_Motor_TTL_DI_Pin 18
  //#define Tilt_Motor_TTL_RO_Pin 19

  const uint8_t BOLT_SERVO_L   = 10;
  const uint8_t BOLT_SERVO_R   = 11;
  const uint8_t BARREL_SERVO_L = 12;
  const uint8_t BARREL_SERVO_R = 13;

  //#define Rasp_TX_Pin 14
  //#define Rasp_RX_Pin 15
  //#define AUX_TX_Pin 16
  //#define AUX_RX_Pin 17
  //#define BU_Degree_SW_Pin 22
  //#define ANG_Degree_SW_Pin 24
  //#define Fan_Relay_Pin 30

  //uint8_t SPEAKER       = 38;
  //uint8_t TEST_MODE_SW  = 40;
  //uint8_t BLDC_RUN      = 42;
  //uint8_t BLOWER_TEST   = 45;
  //uint8_t BLDC_MOTOR_SW = 46;
  //uint8_t TILT_MOTOR_SW = 48;
  //uint8_t Pan_Motor_SW  = 50;
  //uint8_t BOLT_POT   = A13;
  //uint8_t BARREL_POT = A14;

  const uint8_t RC_RX1 = A8;
  const uint8_t RC_RX2 = A9;
  const uint8_t RC_RX3 = A10;
  const uint8_t RC_RX4 = A11;
  const uint8_t RC_RX5 = A12;
  const uint8_t RC_RX6 = A15;

  void init();

}

#endif
