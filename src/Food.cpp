#include "Food.h"
#include "SDL.h"



RgbaColor::RgbaColor():        
    red(0xFF),
    green(0xFF),
    blue(0xFF),
    alpha(0xFF)
{}

void RgbaColor::SetSnakeColor()
{
    red= 0xFF; 
    green = 0xCC; 
    blue = 0x00; 
    alpha = 0xFF;
}

void RgbaColor::SetFoodColor()
{
    red= 0x0c; 
    green = 0xFF; 
    blue = 0x0c; 
    alpha = 0xFF;    
}

void RgbaColor::SetToxicFoodColor()
{
    red= 0xFF; 
    green = 0x00; 
    blue = 0x00; 
    alpha = 0xFF;    
}

unsigned int RgbaColor::GetRed(){return red;}
unsigned int RgbaColor::GetGreen(){return green;}
unsigned int RgbaColor::GetBlue(){return blue;}
unsigned int RgbaColor::GetAlpha(){return alpha;}

//################################################################################################
//############################ Food Implenetation ################################################
//################################################################################################

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

void Food::SetIsToxic(bool pIsToxic)
{
    isToxic = pIsToxic;
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