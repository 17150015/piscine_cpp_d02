#ifndef INC_0703_WARPSYSTEM_H
#define INC_0703_WARPSYSTEM_H
#include "WarpSystem.hh"

namespace WarpSystem {
class QuantumReactor {
 private:
  bool _stability;
 public:
  QuantumReactor();
  ~QuantumReactor();
  bool isStable();
  void setStability(bool);
};

class Core {
 private:
  QuantumReactor *_coreReactor;
 public:
  Core(QuantumReactor *);
  ~Core();
  QuantumReactor *checkReactor();
};
}
#endif //INC_0703_WARPSYSTEM_H
