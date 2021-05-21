#include "Food.h"
#include "SDL.h"

Food::Food(): 
x(0), 
y(0), 
isToxic(true)
{}

Food::~Food()
{}

void Food::SetPosition(int x_pos, int y_pos)
{
    x = x_pos;
    y = y_pos;
}

SDL_Point Food::GetPosition()
{
    SDL_Point p;
    p.x = x;
    p.y = y;
    return p;
}

int Food::GetPosX()
{
    return x;
}

int Food::GetPosY()
{
    return y;
}

bool Food::IsToxic()
{
    return isToxic;
}