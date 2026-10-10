#include "physics.hpp"

void physicshandler::dophysics() {

  
  for (ball &b : stuff){
    b.x += b.vx;
    b.y += b.vy;
  }  
  // n-add new ball
  stuff.emplace_back(10, 10, 16, 0);
}