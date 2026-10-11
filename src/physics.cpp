#include "physics.hpp"
#include <algorithm>
#include <cmath>

void physicshandler::dophysics(float dt) {
  for (ball &b : stuff) {
    const float newx = b.x + (b.x - b.px) * 1;
    const float newy = b.y + (b.y - b.py) * 1 + 50 * dt * dt;
    b.px = b.x;
    b.py = b.y;
    b.x = newx;
    b.y = newy;
  }

  for (int i = 0; i < 3; i++) {
    for (ball &b : stuff) {
      for (ball &c : stuff) {
        if (b.x - 16 <= c.x && c.x <= b.x + 16 && b.y - 16 <= c.y &&
            c.y <= b.y + 16 && &b != &c) {
          const float dx = b.x - c.x;
          const float dy = b.y - c.y;
          const float dist = std::sqrt(dx * dx + dy * dy);
          if (dist > 16.f)
            continue;
          const float scale = 1 - dist / 16.f;
          b.x += dx * scale;
          b.y += dy * scale;
          c.x -= dx * scale;
          c.y -= dy * scale;
        }
      }
    }
  }
  for (ball &b : stuff) {
    b.x = std::clamp(b.x, 8.f, 512.f - 8.f);
    b.y = std::clamp(b.y, 8.f, 512.f - 8.f);
  }
  t += dt;
  if (t >= 0.1) {
    stuff.emplace_back(10, 10, -160 * dt + 10, 0 + 10);
    t = 0;
  }
}