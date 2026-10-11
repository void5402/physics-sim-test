#include "render.hpp"
#include "physics.hpp"
#include <SFML/Graphics/Color.hpp>

// possible approaches:
// 1-using 1 ball to draw all
// 2-using an array of primals
// 3-using vertex array of triangle primals and make circles using them

// maybe later, the current rendered seems to be enough for now
// maybe i will make all of these into a class?

static std::vector<sf::Color> cc{sf::Color::Red,   sf::Color::Yellow,
                                 sf::Color::Green, sf::Color::Blue,
                                 sf::Color::Cyan,  sf::Color::Magenta};
void render(sf::RenderWindow *window, std::vector<ball> *stuff) {
  sf::CircleShape circle(8);
  circle.setOrigin({circle.getRadius(), circle.getRadius()});
  int m = 0;
  window->clear();
  for (ball &i : *stuff) {
    circle.setPosition({i.x, i.y});
    circle.setFillColor(cc[m++%6]);
    window->draw(circle);
  }

  window->display();
}