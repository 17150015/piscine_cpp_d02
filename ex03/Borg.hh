#ifndef INC_0703_BORG_H
#define INC_0703_BORG_H

#include <iostream>
#include "WarpSystem.hh"
#include "Destination.hh"

namespace Federation{
class Ship;
namespace Starfleet{
class Ship;
}
}

namespace Borg{

class Ship{
 public:
  Ship(int wF, short);
  Ship(int wF);
  void setupCore(WarpSystem::Core *);
  void checkCore();
  bool move(int warp, Destination d) {return warp <= _maxWarp && d != _location && _core->checkReactor()->isStable();} // move _location to d
  bool move(int warp) {return warp <= _maxWarp && _core->checkReactor()->isStable(); } // move _location to _home
  bool move(Destination d) {return d !=_location && _core->checkReactor()->isStable() ;}; // move _location to d
  bool move() {return _core->checkReactor()->isStable();}; // move _location to _home

  int getShield() {return _shield;}
  void setShield(int sh) {_shield = sh;}
  int getWeaponFrequency() {return _weaponFrequency;}
  void setWeaponFrequency(int wf) {_weaponFrequency = wf;}
  short getRepair() {return _repair;}
  void setRepair(short re) {_repair = re;}

  void fire(Federation::Starfleet::Ship*);
  void fire(Federation::Ship*);
  void repair();

  ~Ship();
 private:
  int _side;
  short _maxWarp;
  WarpSystem::Core *_core;
  Destination _location;
  Destination _home;
  int _shield; // vaut 100 lors de la construction.
  int _weaponFrequency; // doit etre fourni a la construction
  short _repair; // peut etre fourni. Sinon, vaut 3
};
}

#endif //INC_0703_BORG_H
