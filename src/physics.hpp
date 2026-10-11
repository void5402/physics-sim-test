#pragma once
#include <vector>


struct ball {
  float x{0};
  float y{0};
  float px{0};
  float py{0};
  ball(float x, float y, float px, float py) : x(x), y(y), px(px), py(py) {}
};

class physicshandler {
public:
  std::vector<ball> stuff;
  void dophysics(float dt);
  float t;
};
