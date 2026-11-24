#include "physics.hpp"
#include "render.hpp"

int main(int,char**) {
  sf::RenderWindow window(sf::VideoMode({512, 512}), "test", sf::Style::Default);
  window.setVerticalSyncEnabled(true);
  sf::Clock clock;
  physicshandler physics;
  clock.start();
  window.display();
  bool m{true};
  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
      if (const auto *key = event->getIf<sf::Event::KeyPressed>()) {
        switch (key->scancode) {
          case sf::Keyboard::Scan::Q:
            window.close();
            break;
          case sf::Keyboard::Scan::Space:
            m = !m;
            break;
          default:
            break;
        }
      }
    }

    sf::sleep(sf::milliseconds(16) - clock.restart());
    // physics.dophysics(static_cast<float>(clock.restart().asMilliseconds())/1000);

    if (m) physics.dophysics();
    render(&window,&(physics.X),&(physics.Y));
  }
  return 0;
}