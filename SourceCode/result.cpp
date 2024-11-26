#include "all.h"
#include "result.h"
result r;
Sprite* result_render;
result::result()
{

}

result::~result()
{

}

void result::init()
{
	score = 0;
	judge = 0;
	result_render= sprite_load(L"./Data/Images/result.png");
}

void result::update()
{

}

void result::render()
{
	sprite_render(result_render, 0, 0);
	GameLib::text_out(5, std::to_string(r.score),700,480,3,3,0,0,0,1,TEXT_ALIGN::UPPER_RIGHT);
}