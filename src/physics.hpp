#pragma once
#include <vector>

class physicshandler {
private:
  void addball(float x, float y, float vx, float vy);
  inline int checkgridforindex(int i);
public:
  // locations
  std::vector<float> X;
  std::vector<float> Y;
  // velocities
  std::vector<float> vX;
  std::vector<float> vY;
  // cells are chunks of screen with defined size from top left(beyond screen) to right
  // and warp one row down untill at bottom right
  // basicly each cell must only contain a maximum of one cell
  // and we will store the index of that cell in this grid
  // each cell will check its location every tick for any changes
  // and if needed it will update its grid position
  std::vector<int> cells;
  void dophysics();
};
