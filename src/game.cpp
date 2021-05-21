#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) 
{
  Food food;
  // Create 3 instances of Food class
  for(int i = 0; i < 3; i++)
  {
    food = Food();
    PlaceFood(food);
    foods.emplace_back(food);
  }
//  PlaceFood(); Can be deleted if not needed anymore
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, foods);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

/* DETELE if not needed anymore
void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {

      food.SetPosition(x,y);
      return;
    }
  }
}
*/

void Game::PlaceFood(Food &pFood) 
{
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);

    // TODO check all currently placed foods too, before set x,y

    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      pFood.SetPosition(x,y);
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  for(Food food : foods)
  {
    SDL_Point foodPos = food.GetPosition();

    // Check if there's food over here
    if (foodPos.x == new_x && foodPos.y == new_y) 
    {
      score++;
      PlaceFood(food);                                  // TODO potential ERROR here
      // Grow snake and increase speed.
      snake.GrowBody();
      snake.speed += 0.008;
    }
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }