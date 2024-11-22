#include "all.h"
#include "result.h"
Sprite* result1;
result::result()
{

}

result::~result()
{

}

void result::init()
{
	result1= sprite_load(L"./Data/Images/result.png");
}

void result::update()
{

}

void result::render()
{
	sprite_render(result1, 0, 0);
}