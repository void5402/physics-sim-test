#include "render.hpp"
#include "physics.hpp"
#include <SFML/Graphics/Color.hpp>

//todo: use a texture to optimize gpu side

static std::vector<sf::Color> cc{sf::Color::Red,   sf::Color::Yellow,
                                 sf::Color::Green, sf::Color::Blue,
                                 sf::Color::Cyan,  sf::Color::Magenta};
void render(sf::RenderWindow *window, std::vector<float> *X, std::vector<float> *Y) {
  sf::CircleShape circle(8);
  circle.setOrigin({circle.getRadius(), circle.getRadius()});
  int m = 0;
  window->clear();
  for (int i = 0; i < X->size();++i) {
    circle.setPosition({(*X)[i], (*Y)[i]});
    circle.setFillColor(cc[m++ % 6]);
    window->draw(circle);
  }

  window->display();
}