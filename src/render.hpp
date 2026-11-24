#pragma once
#include "physics.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// from my talks with certain llms i found 3 rendering communication paths
// that are both performant and simple enough for me to be able to implement:
// 1-direct memory:
//  pro:best performance
//  con:possible race conditions with threads
// 2-compositing(renderer as subobject after updates):
//  pro:easy to implement(specially with my data hierarchy)
//  con:one huge class+only single threaded(minimum framerate is capped at
//  simulation speed) con:possible simulation time lost to rendering
// 3-snapshots(or double buffer):
//  pro:safe for multithreading+more responsive with multiple threads
//  con:data getting copied
// but here is the catch:
// the only data the rendered needs are current x and y arrays
// so for the first implementation i could just go with a direct access aproach

void render(sf::RenderWindow *window, std::vector<float> *X, std::vector<float> *Y);