#include "mission.h"
#include "object.h"
#include"player.h"
#include "all.h"
extern Sprite* tamago;
extern Sprite* chikuwa;
extern Sprite* octopus;
extern Sprite* konjac;
extern Sprite* daikon;
extern Sprite* hanpen;
extern Sprite* playercontroller;
void mission::init()
{
	srand((unsigned int)time(NULL));
	obj1 = rand() % 2;
	obj2 = rand() % 2;
	obj3 = rand() % 2;
}

void mission::update()
{
	obj1 = rand() % 2;
	obj2 = rand() % 2;
	obj3 = rand() % 2;
}

void mission::render()
{
	sprite_render(playercontroller, 70, 800, 2, 2, 56, 20, 64, 128);
	if (obj1 == 0)
	{
		sprite_render(
			hanpen,
			90, 800,
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
			konjac,
			90, 800,
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
			tamago,
			90, 870,
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
			daikon,
			90, 870,
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
			octopus,
			90, 920,
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
			chikuwa,
			90, 920,
			0.8, 0.8,
			0, 0,
			128, 128,
			64, 64,
			ToRadian(0)
		);
	}
}