#ifndef __dynamixel_h_
#define __dynamixel_h_

#define TX_ENABLE_PIN 8
#define DYNAMIXEL_BAUDRATE 57600

void dx_init();
void dx_torque_enable(bool enable);
void dx_move(unsigned int pos);
void dx_send(char *data, unsigned short len);

#endif
