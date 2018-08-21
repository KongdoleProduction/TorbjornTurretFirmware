#ifndef __PAN_CONTROLLER_
#define __PAN_CONTROLLER_

namespace pan_controller {
  const float MOTOR_DEADZONE = 0.1;

  void init();
  void move(float speed);
}

#endif
