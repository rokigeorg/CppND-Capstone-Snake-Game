# Project idea

The sneak game works like the orginal game. 
It will be extend as following: 
* 3x foods are displayed at the same time
* 2x foods are bad, it will kill the snake
* only 1x food is good and can be eaten by the snake 
* eatable food has same color as snake body
* none eatable food has random color, but not the color of the snakes body
* each time the snake eats good food, 3x new foods are spawned
* each time the snake eats a good food it grows and speed increases

## Extra ideas
* snake has 3 lifes, life decrease when snake eats bad food
* snake can change color each time it eats one good food


### Realization of project idea
1. Create food class
2. Inheritate Food class from SDL_Point
3. Create a vector of foods in game.h
4. Pass vector of foods to render method Render(Snake const snake, vector<Food> const &foods);
5. Implement a member function for PlaceFood in class Food


### Realization of aggregator
1. Create Aggregator class
2. Write to file the current game results (Name, Score, Size)
3. Read from file and parse name, score, size in object result-item, save each result item in vector
4. Sort result items vector for size or score
5. Print sorted result item vector