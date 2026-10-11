#include "physics.hpp"
#include "render.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode({512, 512}), "test",sf::Style::None);
  window.setVerticalSyncEnabled(true);
  //sf::Clock clock;
  physicshandler physics;
  //clock.start();
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
    //physics.dophysics(static_cast<float>(clock.restart().asMilliseconds())/1000);
    physics.dophysics(0.016);
    render(&window, &physics.stuff);
  }
  return 0;
}