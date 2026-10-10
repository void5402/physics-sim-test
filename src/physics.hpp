#pragma once
#include <vector>

struct ball {
  float x{0};
  float y{0};
  float vx{0};
  float vy{0};
  ball(float x, float y, float vx, float vy) : x(x), y(y), vx(vx), vy(vy) {}
};

class physicshandler {
public:
  std::vector<ball> stuff;
  void dophysics();
};
