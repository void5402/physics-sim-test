#include "render.hpp"
#include "physics.hpp"
#include <SFML/Graphics/Color.hpp>

// possible approaches:
// 1-using 1 ball to draw all
// 2-using an array of primals
// 3-using vertex array of triangle primals and make circles using them

//maybe later, the current rendered seems to be enough for now
//maybe i will make all of these into a class?

void render(sf::RenderWindow *window, std::vector<ball> *stuff) {
  sf::CircleShape circle(8);
  circle.setOrigin({circle.getRadius(), circle.getRadius()});
  window->clear();
  int m = 0;
  for (ball &i : *stuff) {
    circle.setPosition({i.x, i.y});
    circle.setFillColor(sf::Color(m*2%255,m*3%255,m*5%255));
    window->draw(circle);
    m+=10;
  }

  window->display();
}