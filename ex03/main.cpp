#include <iostream>
#include "WarpSystem.hh"
#include "Federation.hh"
#include "Borg.hh"

int main(void)
{
  Federation::Starfleet::Ship UssKreog(289, 132, "Kreog", 6, 20);
  Federation::Starfleet::Captain James("James T. Kirk");
  Federation::Starfleet::Ensign Ensign("Pavel Chekov");
  WarpSystem::QuantumReactor QR;
  WarpSystem::QuantumReactor QR2;
  WarpSystem::Core core(&QR);
  WarpSystem::Core core2(&QR2);
  UssKreog.setupCore(&core);
  UssKreog.checkCore();
  UssKreog.promote(&James);
  Borg::Ship Cube(12);
  Cube.setupCore(&core2);
  Cube.checkCore();
  return 0;
}