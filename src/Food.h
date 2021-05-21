#ifndef FOOD_H
#define FOOD_H

#include <random>
#include "SDL.h"

struct RgbaColor
{
    unsigned int red;
    unsigned int green;
    unsigned int blue;
    unsigned int alpha;
    
    RgbaColor():        
        red(0x00),
        green(0x00),
        blue(0x00),
        alpha(0x00)
    {}
};


class Food : public RgbaColor  {
    public:
    Food();
    ~Food();

    void SetPosition(int x_pos, int y_pos);
    SDL_Point GetPosition();
    int GetPosX();
    int GetPosY();
    bool IsToxic();

    private:
    bool isToxic;
    int x;
    int y;
};

#endif