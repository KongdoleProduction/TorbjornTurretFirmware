#ifndef __DYNAMIXEL_HPP_
#define __DYNAMIXEL_HPP_

#define DYNAMIXEL_BAUDRATE 57600

namespace dx {

  void init();
  void ping(uint8_t id);
  void change_id(uint8_t id, uint8_t desired_id);
  void torque_enable(uint8_t id, bool enable);
  void move(uint8_t id, unsigned int pos);
  void send(char *data, unsigned short len);

}

#endif
