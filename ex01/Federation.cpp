
#include "Federation.hh"

namespace Federation {
namespace Starfleet {

Ship::Ship(int length, int width, std::string name, short maxWarp) :
    _length(length), _width(width), _name(name), _maxWarp(maxWarp){
  std::cout << "The ship USS" << _name << " has been finished. It is " <<
            _length << " m in length and " << _width << " m in width" <<std::endl;
  std::cout << "It can go to Warp "<<_maxWarp <<" !" <<std::endl;
}

void Ship::setupCore(WarpSystem::Core *c) {
  _core = c;
  std::cout << "USS "<<_name <<": The core is set." << std::endl;
}

void Ship::checkCore() {
  std::cout << "USS "<<_name<<": The core is "<<
                                              (_core->checkReactor()->isStable() ? "stable":"unstable")<<" at the time."<<std::endl;
}
Ship::~Ship() {

}
void Ship::promote(Federation::Starfleet::Captain *cap) {
  _captain  =cap;
  std::cout << ""<<_captain->getName()<<": I’m glad to be the captain of the USS "<<_name<<"." << std::endl;
}

}

Ship::Ship(int length, int width, std::string name) :
    _length(length), _width(width), _name(name) {
  std::cout << "The independant ship "<< name << " just finished its construction. It is "<<
       _length<<" m in length and "<<_width<<" m in width."<<std::endl;
}

void Ship::setupCore(WarpSystem::Core *c) {
  _core = c;
  std::cout <<_name <<": The core is set." << std::endl;
}

void Ship::checkCore() {
  std::cout <<_name<<": The core is "<<
            (_core->checkReactor()->isStable() ? "stable":"unstable")
            <<" at the time."<<std::endl;
}
Ship::~Ship() {

}

}