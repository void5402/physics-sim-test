#include "render.hpp"
#include "physics.hpp"
#include <SFML/Graphics/Color.hpp>

//todo: use a texture to optimize gpu side

static std::vector<sf::Color> cc{sf::Color::Red,   sf::Color::Yellow,
                                 sf::Color::Green, sf::Color::Blue,
                                 sf::Color::Cyan,  sf::Color::Magenta};
void render(sf::RenderWindow *window, System *mainsys) {
  sf::CircleShape circle(8);
  circle.setOrigin({circle.getRadius(), circle.getRadius()});
  int m = 0;
  window->clear();
  for (int i = 0; i < mainsys->x.size();++i) {
    circle.setPosition({mainsys->x[i], mainsys->x[i]});
    circle.setFillColor(cc[m++ % 6]);
    window->draw(circle);
  }

  window->display();
}