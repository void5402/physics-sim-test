#include "physics.hpp"
#include <algorithm>
#include <cmath>

void physicshandler::dophysics(float dt) {
  for (ball &b : stuff) {
    const float newx = 2 * b.x - b.px;
    const float newy = 2 * b.y - b.py + 50 * dt * dt;
    b.px = b.x;
    b.py = b.y;
    b.x = newx;
    b.y = newy;
  }

  for (int i = 0; i < stuff.size(); ++i) {
    for (int j = i + 1; j < stuff.size(); ++j) {
      ball &b = stuff[i];
      ball &c = stuff[j];
      if (b.x - 16 <= c.x && c.x <= b.x + 16 && b.y - 16 <= c.y &&
          c.y <= b.y + 16 && &b != &c) {
        const float dx = b.x - c.x;
        const float dy = b.y - c.y;
        const float dist = std::sqrt(dx * dx + dy * dy);
        if (dist > 16.f)
          continue;
        const float scale = (1 - dist / 16.f) * 0.5;
        b.x += dx * scale;
        b.y += dy * scale;
        c.x -= dx * scale;
        c.y -= dy * scale;
      }
    }
  }

  for (ball &b : stuff) {
    b.x = std::clamp(b.x, 8.f, 512.f - 8.f);
    b.y = std::clamp(b.y, 8.f, 512.f - 8.f);
  }
  t += dt;
  if (t >= 0.1 && stuff.size() < 500) {
    stuff.emplace_back(10, 10, -160 * dt + 10, 0 + 10);
    t = 0;
  }
}