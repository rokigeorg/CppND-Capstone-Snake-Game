#ifndef FOOD_H
#define FOOD_H

#include <random>
#include "SDL.h"

class RgbaColor
{
    private:
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int alpha;

    int RandomNumber(int min, int max);
    
    public:

    RgbaColor();
    void SetSnakeColor();
    void SetFoodColor();
    void SetToxicFoodColor();

    unsigned int GetRed();
    unsigned int GetGreen();
    unsigned int GetBlue();
    unsigned int GetAlpha();

    void SetRandomColor();
};


class Food : public RgbaColor  {
    public:
    Food();
    ~Food();

    void SetPosition(int x_pos, int y_pos);
    void SetIsToxic(bool pIsToxic);
    SDL_Point GetPosition();
    int GetPosX();
    int GetPosY();
    bool IsToxic();

    Food& operator=(const Food& f);

    private:
    bool isToxic;
    int x;
    int y;

};

#endif