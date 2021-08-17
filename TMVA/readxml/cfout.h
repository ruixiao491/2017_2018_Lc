#ifndef _CFOUT_H_
#define _CFOUT_H_

#include <iostream>
#include <fstream>

class cfout
{
 public:
 cfout(std::ostream& out1, std::ostream& out2) : out1_(out1), out2_(out2) {}
  ~cfout(){};
  std::ostream& out1_;
  std::ostream& out2_;  
};

template <typename T>
cfout& operator<<(cfout& cf, const T& t)
{
  cf.out1_<<t;
  cf.out2_<<t;
  return cf;
}

cfout& operator<<(cfout& cf, std::ostream&(*f)(std::ostream&))
{
  cf.out1_<<f;
  cf.out2_<<f;
  return cf;
}

#endif
