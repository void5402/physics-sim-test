#include "physics.hpp"

void physicshandler::dophysics(float dt) {
  for (ball &b : stuff) {
    b.vy += dt*10
  }
  for (ball &b : stuff) {
    b.x += b.vx;
    b.y += b.vy;
  }
  // n-add new ball
  stuff.emplace_back(10, 10, 16, 0);
}