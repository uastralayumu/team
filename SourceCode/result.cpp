#include "all.h"
#include "result.h"
result r;
Sprite* result_render;
Sprite* font5;
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
	font5 = sprite_load(L"./Data/Fonts/font5.png");
}

void result::update()
{

}

void result::render()
{
	int place = 1,i = 1;
	sprite_render(result_render, 0, 0);
	do {
		sprite_render(font5, 900 - i * 64, 440 + (i * 10), 2.2, 2.2, 32 * ((r.score / place) % 10)   //0‚©‚ç9‚Ü‚Å‚Ì’l‚ðŒˆ‚ß‚Ä‚é
			, 96, 32, 32, 0, 0, ToRadian(-9), 0, 0, 0, 1);
		place *= 10;
		i++;
	} while (place < r.score);
	sprite_render(font5, 884, 440, 2.2, 2.2, 0, 160, 32, 32, 0, 0, ToRadian(-9), 0, 0, 0, 1);
	sprite_render(font5, 932, 435, 2, 2, 128, 224, 32, 32, 0, 0, ToRadian(-9), 0, 0, 0, 1);

}