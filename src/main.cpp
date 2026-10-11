#include "physics.hpp"
#include "render.hpp"
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
int main() {
  sf::RenderWindow window(sf::VideoMode({512, 512}), "test", sf::Style::None);
  window.setVerticalSyncEnabled(true);
  // sf::Clock clock;
  physicshandler physics;
  // clock.start();
  window.display();
  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
      if (event->is<sf::Event::MouseButtonPressed>())
        render(&window, &physics.stuff);
      if (const auto *key = event->getIf<sf::Event::KeyPressed>()) {
        if (key->scancode == sf::Keyboard::Scan::Q) {
          window.close();
        }
      }
    }
    // sf::sleep(sf::milliseconds(16));
    // physics.dophysics(static_cast<float>(clock.restart().asMilliseconds())/1000);
    physics.dophysics(0.016);
    render(&window, &physics.stuff);
  }
  return 0;
}