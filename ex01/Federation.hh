
#ifndef INC_0703_FEDERATION_H
#define INC_0703_FEDERATION_H

#include <string>
#include <iostream>
#include "WarpSystem.hh"

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
  ~Ship();
 private:
  int _length;
  int _width;
  std::string _name;
  short _maxWarp;
  WarpSystem::Core *_core;
  Captain *_captain;
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
 private:
  int _length;
  int _width;
  std::string _name;
  WarpSystem::Core *_core;
};
}

#endif //INC_0703_FEDERATION_H
