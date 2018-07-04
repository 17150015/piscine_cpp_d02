
#ifndef INC_0703_FEDERATION_H
#define INC_0703_FEDERATION_H

#include <string>
#include <iostream>
#include "WarpSystem.hh"
#include "Destination.hh"

namespace Federation {
namespace Starfleet{
class Captain {
 protected:
  std::string _name;
  int _age;
 public:
  Captain(std::string name):_name(name) {

  }
  std::string getName() {return _name;}
  void setName(std::string name) { _name = name;}
  int getAge() {return _age;}
  void setAge(int age) {_age = age;}
  ~Captain() {}
};

class Ship{

 public:
  Ship(int length, int width, std::string name, short maxWarp);
  void setupCore(WarpSystem::Core *);
  void checkCore();
  void promote(Captain*);
  bool move(int warp, Destination d) {return warp <= _maxWarp && d != _location && _core->checkReactor()->isStable();} // move _location to d
  bool move(int warp) {return warp <= _maxWarp && _core->checkReactor()->isStable(); } // move _location to _home
  bool move(Destination d) {return d !=_location && _core->checkReactor()->isStable() ;}; // move _location to d
  bool move() {return _core->checkReactor()->isStable();}; // move _location to _home
  ~Ship();
 private:
  int _length;
  int _width;
  std::string _name;
  short _maxWarp;
  WarpSystem::Core *_core;
  Captain *_captain;
  Destination _location;
  Destination _home;
};



class Ensign{
 public:
  explicit Ensign(std::string name) : _name(name) {
    std::cout << "Ensign "<<_name<<", awaiting orders."<<std::endl;
  };
  ~Ensign() {}
 private:
  std::string _name;
};
}

class Ship {
 public:
  Ship(int length, int width, std::string name);
  ~Ship();
  void setupCore(WarpSystem::Core *);
  void checkCore();
  bool move(int warp, Destination d) {return warp <= _maxWarp && d != _location && _core->checkReactor()->isStable();} // move _location to d
  bool move(int warp) {return warp <= _maxWarp && _core->checkReactor()->isStable(); } // move _location to _home
  bool move(Destination d) {return d !=_location && _core->checkReactor()->isStable() ;}; // move _location to d
  bool move() {return _core->checkReactor()->isStable();}; // move _location to _home
 private:
  int _length;
  int _width;
  short _maxWarp;
  std::string _name;
  WarpSystem::Core *_core;
  Destination _location;
  Destination _home;
};
}

#endif //INC_0703_FEDERATION_H
