#include "WarpSystem.hh"

namespace WarpSystem{
Core::Core(QuantumReactor *quantum_reactor) : _coreReactor(quantum_reactor){

}

Core::~Core() {

}

QuantumReactor* Core::checkReactor() {
  return _coreReactor;
}


QuantumReactor::QuantumReactor() :_stability (true){

}

QuantumReactor::~QuantumReactor() {

}

bool QuantumReactor::isStable() {
  return _stability;
}
void QuantumReactor::setStability(bool s) {
  _stability = s;
}

}