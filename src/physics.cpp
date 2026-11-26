
#include "physics.hpp"
#include <algorithm>
#include <cmath>

physicshandler::physicshandler() { cells.resize(1156, -1); }

inline int physicshandler::checkgrid(int i) {
  // since i will be hardcoding this project for now just remmeber
  // 512 x 512 screen -> 16 x 16 cells (+extra byond screen) -> 32 + 2 x 32 + x
  // -> 34 x 34 grid -> 1156 cells(0->1155) each balwill have a radius of 13
  // cell = row*34 + coloum(counting from 0, first visible coloum is 1)[aka
  // 0->33,34->...]
  return (floor(X[i] / 16) + 1) * 34 + floor(Y[i] / 16) + 1;
}

inline int physicshandler::checkgrid(float x, float y) {
  return (floor(x / 16) + 1) * 34 + floor(y / 16) + 1;
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
  // 6-check for grid updates
  for (int i = 0; i < n; ++i) {
    // maybe we refrence needed date to reduce member access?
    // add gravity
    vY[i] += 10;
    // temporary positions
    float newx = X[i] + vX[i];
    float newy = Y[i] + vY[i];
    // check for walls
    if (newx >= 499) {
      newy = vY[i] * (499 - X[i]) / (newx - X[i]) + Y[i];
      newx = 499;
      vX[i] *= -0.8;
    } else if (newx <= 13) {
      newy = vY[i] * (13 - X[i]) / (newx - X[i]) + Y[i];
      newx = 13;
      vX[i] *= -0.8;
    }
    if (newy >= 499) {
      newx = vX[i] * (499 - Y[i]) / (newy - Y[i]) + X[i];
      newy = 499;
      vY[i] *= -0.8;
    } else if (newy <= 13) {
      newx = vX[i] * (13 - Y[i]) / (newy - Y[i]) + X[i];
      newy = 13;
      vY[i] *= -0.8;
    }
    // do collision detection
    const int c = checkgrid(newx, newy);
    for (int m = -1; m < 2; ++m) {
      for (int j = -1; j < 2; ++j) {
        const int ii = cells[c + 34 * m + j];
        if (ii > i) {
          const float dx = newx - X[ii];
          const float dy = newy - Y[ii];
          if (dx*dx + dy*dy < 26*26) {
            newx += (newx - X[ii]) / 2;
            vX[ii] -= (newx - X[ii]) / 2;
            newy += (newy - Y[ii]) / 2;
            vY[ii] -= (newy - Y[ii]) / 2;
          }
        }
      }
    }

    // update grid
    const int oc = checkgrid(i);
    const int nc = checkgrid(newx, newy);
    if (cells[nc] != i) {
      cells[oc] = -1;
      cells[nc] = i;
    }

    // update the finall positions and grid
    X[i] = newx;
    Y[i] = newy;
  }

  // add new ball
  addball(13, 13, 40, 0);
  cells[checkgrid(n)] = n;
  n++;
}
