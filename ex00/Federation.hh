
#ifndef INC_0703_FEDERATION_H
#define INC_0703_FEDERATION_H

#include <string>
#include <iostream>
#include "WarpSystem.hh"

namespace Federation {
namespace Starfleet{
class Ship{
 public:
  Ship(int length, int width, std::string name, short maxWarp);
  void setupCore(WarpSystem::Core *);
  void checkCore();
  ~Ship();
 private:
  int _length;
  int _width;
  std::string _name;
  short _maxWarp;
  WarpSystem::Core *_core;
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
