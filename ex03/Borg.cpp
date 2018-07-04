
#include "Borg.hh"
#include "Destination.hh"
#include "Federation.hh"

namespace Borg{

Ship::Ship(int wF) :_weaponFrequency(wF){
  _side = 300;
  _maxWarp = 9;
  _location= UNICOMPLEX;
  _home = _location;
  _shield = 100;
  _repair = 3;
  std::cout <<"We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout <<"Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout<<  "Resistance is futile." << std::endl;
}

Ship::Ship(int wF, short re) : _weaponFrequency(wF), _repair(re) {
  _side = 300;
  _maxWarp = 9;
  _location= UNICOMPLEX;
  _home = _location;
  _shield = 100;
  std::cout <<"We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
  std::cout <<"Your biological characteristics and technologies will be assimilated." << std::endl;
  std::cout<<  "Resistance is futile." << std::endl;
}
Ship::~Ship() {

}
void Ship::fire(Federation::Starfleet::Ship *s) {
  s->setShield(s->getShield() - _weaponFrequency);
  std::cout << "Firing on target with "<<_weaponFrequency<< "GW frequency."<<std::endl;
}

void Ship::fire(Federation::Ship *s) {
  s->getCore();
  std::cout << "Firing on target with "<<_weaponFrequency<< "GW frequency."<<std::endl;
}

void Ship::repair() {
  if(_repair>0) {
    std::cout << "Begin shield re-initialisation... Done. Awaiting further instructions." << std::endl;
    _shield = 100;
    _repair--;
  }
  else {
    std::cout << "Energy cells depleted, shield weakening." << std::endl;
  }

}
void Ship::setupCore(WarpSystem::Core *c) {
  _core = c;

}

void Ship::checkCore() {
  if(_core->checkReactor()->isStable()) {
    std::cout << "Everything is in order." << std::endl;
  }
  else {
    std::cout << "Critical failure imminent." << std::endl;
  }
}

}