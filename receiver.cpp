#define EI_ARDUINO_INTERRUPTED_PIN // this sets atmega variable for interrupt

#include <Arduino.h>
#include <EnableInterrupt.h>
#include "receiver.hpp"
#include "pins.hpp"

#define READ_SIGNAL(pin, channel) \
  if (digitalRead((pin)) == HIGH) { \
    timeStamp[channel] = micros(); \
  } else { \
    _values[channel] = micros() - timeStamp[channel]; \
  }

#define NEUTRALIZE(value) \
  (1500 - (value))

#define CHANNEL_NUM 6

namespace receiver {

  uint16_t _values[CHANNEL_NUM];

  uint8_t _pins[CHANNEL_NUM] = {
    pins::RC_RX1,
    pins::RC_RX2,
    pins::RC_RX3,
    pins::RC_RX4,
    pins::RC_RX5,
    pins::RC_RX6
  };

  volatile long timeStamp[CHANNEL_NUM];

  void readRX1() { READ_SIGNAL(_pins[0], 0) }
  void readRX2() { READ_SIGNAL(_pins[1], 1) }
  void readRX3() { READ_SIGNAL(_pins[2], 2) }
  void readRX4() { READ_SIGNAL(_pins[3], 3) }
  void readRX5() { READ_SIGNAL(_pins[4], 4) }
  void readRX6() { READ_SIGNAL(_pins[5], 5) }

  void readSignal() {
    uint8_t pin = arduinoInterruptedPin;
    long m = micros();
    for (uint8_t i=0; i<CHANNEL_NUM; i++) {
      if (_pins[i] == pin) {
        if (digitalRead(pin) == HIGH) {
          timeStamp[i] = m;
        } else {
          _values[i] = m - timeStamp[i];
        }
      }
    }
  }

  void init() {
    for (int i=0; i<CHANNEL_NUM; i++) {
      //pinMode(_pins[i], INPUT);
    }
    enableInterrupt(_pins[0], &readRX1, CHANGE);
    enableInterrupt(_pins[1], &readRX2, CHANGE);
    enableInterrupt(_pins[2], &readRX3, CHANGE);
    enableInterrupt(_pins[3], &readRX4, CHANGE);
    enableInterrupt(_pins[4], &readRX5, CHANGE);
    enableInterrupt(_pins[5], &readRX6, CHANGE);
  }

  void readReceiver(int *values) {
    for (int i=0; i<CHANNEL_NUM; i++) {
      values[i] = (int)_values[i];
    }
  }
}
