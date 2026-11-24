
#include "physics.hpp"
#include <cmath>

inline int physicshandler::checkgridforindex(int i) {
  // since i will be hardcoding this project for now just remmeber
  // 512 x 512 screen -> 16 x 16 cells (+extra byond screen) -> 32 + 2 x 32 + x
  // -> 34 x 34 grid -> 1156 cells(0->1155) each balwill have a radius of 13
  // cell = row*34 + coloum(counting from 0, first visible coloum is 1)[aka
  // 0->33,34->...]
  return (floor(X[i] / 16) + 1) * 34 + floor(Y[i] / 16) + 1;
}

void physicshandler::addball(float x, float y, float vx, float vy) {
  X.emplace_back(x);
  Y.emplace_back(y);
  vX.emplace_back(vx);
  vY.emplace_back(vy);
}

void physicshandler::dophysics() {
  // steps to be implemented are as follows:
  // 1-handle forces(add acceleration to velocity)
  // 2-compute the new [temporary] positions
  // 3-check for any collision with constraints(other balls, walls)
  // 4-adjust new position and velocity accordingly
  // 5-actually update the positions
  for (int i = 0; i < n; ++i) {
    //add gravity
    vX[i] += 10;
    

  }
  // add new ball
  addball(10, 10, 10, 0);
  cells.emplace_back(checkgridforindex(n++));
}
