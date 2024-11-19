#include "mission.h"
#include "all.h"
Sprite* tamago2;
Sprite* chikuwa2;
Sprite* octopus2;
Sprite* konjac2;
Sprite* daikon2;
Sprite* hanpen2;
Sprite* kusi2;
void mission::init()
{
	srand((unsigned int)time(NULL));
	obj1 = rand() % 2;
	obj2 = rand() % 2;
	obj3 = rand() % 2;

	tamago2 = sprite_load(L"./Data/Images/tamago.png");
	octopus2 = sprite_load(L"./Data/Images/octopus.png");
	chikuwa2 = sprite_load(L"./Data/Images/chikuwa.png");
	konjac2 = sprite_load(L"./Data/Images/konjac.png");
	daikon2 = sprite_load(L"./Data/Images/daikon.png");
	hanpen2 = sprite_load(L"./Data/Images/hanpen.png");
	kusi2 = sprite_load(L"./Data/Images/kusi.png");
}

void mission::update()
{
	obj1 = rand() % 2;
	obj2 = rand() % 2;
	obj3 = rand() % 2;
}

void mission::render()
{
	sprite_render(kusi2, 70, 450, 2, 2, 56, 20, 64, 128);
	if (obj1 == 0)
	{
		sprite_render(
			hanpen2,
			90, 450,
			0.7, 0.7,
			0, 0,
			128, 128,
			64, 64,
			ToRadian(0)
		);
	}
	else
	{
		sprite_render(
			konjac2,
			90, 450,
			0.7, 0.7,
			0, 0,
			128, 128,
			64, 64,
			ToRadian(0)
		);
	}
	if (obj2 == 0)
	{
		sprite_render(
			tamago2,
			90, 520,
			0.8, 0.8,
			0, 0,
			128, 128,
			64, 64,
			ToRadian(270)
		);
	}
	else
	{
		sprite_render(
			daikon2,
			90, 520,
			0.7, 0.7,
			0, 0,
			128, 128,
			64, 64,
			ToRadian(0)
		);
	}
	if (obj3 == 0)
	{
		sprite_render(
			octopus2,
			90, 570,
			0.7, 0.7,
			0, 0,
			128, 128,
			64, 64,
			ToRadian(0)
		);
	}
	else
	{
		sprite_render(
			chikuwa2,
			90, 570,
			0.8, 0.8,
			0, 0,
			128, 128,
			64, 64,
			ToRadian(0)
		);
	}
}