#ifndef INC_0703_BORG_H
#define INC_0703_BORG_H

#include <iostream>
#include "WarpSystem.hh"

namespace Borg{
class Ship{
 public:
  Ship();
  void setupCore(WarpSystem::Core *);
  void checkCore();
  ~Ship();
 private:
  int _side;
  short _maxWarp;
  WarpSystem::Core *_core;
};
}

#endif //INC_0703_BORG_H
