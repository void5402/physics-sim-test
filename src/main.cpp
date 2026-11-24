#include "physics.hpp"
#include "render.hpp"
int main(int,char**) {
  sf::RenderWindow window(sf::VideoMode({512, 512}), "test", sf::Style::Default);
  window.setVerticalSyncEnabled(true);
  sf::Clock clock;
  physicshandler physics;
  clock.start();
  window.display();
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

    sf::sleep(sf::milliseconds(16) - clock.restart());
    // physics.dophysics(static_cast<float>(clock.restart().asMilliseconds())/1000);

    physics.dophysics();
    render(&window,&(physics.X),&(physics.Y));
  }
  return 0;
}