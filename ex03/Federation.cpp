
#include "Federation.hh"

namespace Federation {
namespace Starfleet {

Ship::Ship(int length, int width, std::string name, short maxWarp, int tor) :
    _length(length), _width(width), _name(name), _maxWarp(maxWarp), _photonTorpedo(tor){
  _home = _location = EARTH;
  std::cout << "The ship USS" << _name << " has been finished. It is " <<
            _length << " m in length and " << _width << " m in width" <<std::endl;
  std::cout << "It can go to Warp "<<_maxWarp <<" !" <<std::endl;
  std::cout << "Weapons are set: "<<_photonTorpedo <<"\n"
               "torpedoes ready." << std::endl;

}

Ship::Ship() : _length(289), _width(132),_name("Entreprise"), _maxWarp(6), _photonTorpedo(20){
  _home = _location = EARTH;
  std::cout << "The ship USS" << _name << " has been finished. It is " <<
            _length << " m in length and " << _width << " m in width" <<std::endl;
  std::cout << "It can go to Warp "<<_maxWarp <<" !" <<std::endl;
  std::cout << "Weapons are set: "<<_photonTorpedo <<"\n"
                                                     "torpedoes ready." << std::endl;
}

void Ship::fire(Borg::Ship *s) {
  if(_photonTorpedo == 0) {
    std::cout << _name<<": No more torpedo to fire, "<<_captain->getName()<<"!" << std::endl;
    return;
  }
  _photonTorpedo--;
  s->setShield(s->getShield() - 50);
  std::cout <<_name <<": Firing on target. "<<_photonTorpedo<<" torpedoes remaining." << std::endl;
}

void Ship::fire(int torpedoes, Borg::Ship *s) {
  if(_photonTorpedo < torpedoes) {
    std::cout << _name<<": No enough torpedoes to fire, "<<_captain->getName()<<"!" << std::endl;
    return;
  }
  _photonTorpedo -=torpedoes;
  s->setShield(s->getShield() - torpedoes*50);
  std::cout <<_name <<": Firing on target. "<<_photonTorpedo<<" torpedoes remaining." << std::endl;
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
  _maxWarp = 1;
  _home = _location = VULCAN;
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