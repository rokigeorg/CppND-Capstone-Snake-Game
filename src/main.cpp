#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "aggregator.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  //TODO create Aggregator instance
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  Aggregator aggregator(game);
  game.Run(controller, renderer, kMsPerFrame);

  // TODO call aggregator function to output score and snake size
  aggregator.Run();
  // std::cout << "Game has terminated successfully!\n";
  // std::cout << "Score: " << game.GetScore() << "\n";
  // std::cout << "Size: " << game.GetSize() << "\n";

  // TODO call aggregator function display Ranging Table
  return 0;
}