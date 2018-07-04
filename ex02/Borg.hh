#ifndef INC_0703_BORG_H
#define INC_0703_BORG_H

#include <iostream>
#include "WarpSystem.hh"
#include "Destination.hh"

namespace Borg{
class Ship{
 public:
  Ship();
  void setupCore(WarpSystem::Core *);
  void checkCore();
  bool move(int warp, Destination d) {return warp <= _maxWarp && d != _location && _core->checkReactor()->isStable();} // move _location to d
  bool move(int warp) {return warp <= _maxWarp && _core->checkReactor()->isStable(); } // move _location to _home
  bool move(Destination d) {return d !=_location && _core->checkReactor()->isStable() ;}; // move _location to d
  bool move() {return _core->checkReactor()->isStable();}; // move _location to _home
  ~Ship();
 private:
  int _side;
  short _maxWarp;
  WarpSystem::Core *_core;
  Destination _location;
  Destination _home;
};
}

#endif //INC_0703_BORG_H
