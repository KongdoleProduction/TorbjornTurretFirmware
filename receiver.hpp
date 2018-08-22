#ifndef __RECEIVER_HPP_
#define __RECEIVER_HPP_

namespace receiver {
  const uint16_t RC1_MID = 1500;
  const uint16_t RC1_MIN = 988;
  const uint16_t RC1_MAX = 2012;
  const uint16_t RC2_MID = 1500;
  const uint16_t RC2_MIN = 988;
  const uint16_t RC2_MAX = 2012;
  const uint16_t RC3_MID = 1500;
  const uint16_t RC3_MIN = 988;
  const uint16_t RC3_MAX = 2012;
  const uint16_t RC4_MID = 1500;
  const uint16_t RC4_MIN = 988;
  const uint16_t RC4_MAX = 2012;
  const uint16_t RC5_MID = 1500;
  const uint16_t RC5_MIN = 988;
  const uint16_t RC5_MAX = 2012;
  const uint16_t RC6_MID = 1500;
  const uint16_t RC6_MIN = 988;
  const uint16_t RC6_MAX = 2012;

  void init();
  void readReceiver(int*);

}

#endif
