#ifndef GAME_H
#define GAME_H

#include <random>
#include <vector>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "Food.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  Snake snake;
  //Food food;
  std::vector<Food> foods;
  std::vector<Food> toxicFoods;



  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  bool HasEatenToxicFood(int player_x, int player_y);
  bool IsOtherFoodAtPosition(int new_x, int new_y);
  void PlaceFood(Food *pFood);
  void VerifyOnlyToxicFood();

  void Update();
};

#endif