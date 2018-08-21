#ifndef __DYNAMIXEL_HPP_
#define __DYNAMIXEL_HPP_

#define DYNAMIXEL_BAUDRATE 57600

namespace dx {

  void init();
  void torque_enable(bool enable);
  void move(unsigned int pos);
  void send(char *data, unsigned short len);

}

#endif
