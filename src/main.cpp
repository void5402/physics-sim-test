#include "physics.hpp"
#include "render.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode({500, 500}), "test",sf::Style::Titlebar);
  window.setVerticalSyncEnabled(true);

  physicshandler physics;
  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
      if (const auto *key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->scancode == sf::Keyboard::Scan::Q) {
          window.close();
        }
      }
    }
    physics.dophysics();
    render(&window, &physics.stuff);
  }
  return 0;
}