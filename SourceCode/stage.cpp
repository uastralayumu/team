#include "stage.h"
#include "all.h"
Sprite* gamescene;

stage::stage()
{

}

stage::~stage()
{

}

void stage::init()
{
	gamescene = sprite_load(L"./Data/Images/gamescene.png");
}

void stage::update()
{

}

void stage::render()
{
	sprite_render(gamescene, 0, 0);
}