#include "all.h"
#include "object.h"

Sprite* tamago;
Sprite* chikuwa;
Sprite* octopus;

void object::init()
{
	for (int i = 0; i < 6; i++)
	{
		
		if (i % 3 == 0)
		{
			positionx[i] = 0;
			positiony[i] = 0;
		}
		if (i % 3 == 1)
		{
			positionx[i] = SCREEN_W;
			positiony[i] = 128;
		}
		if (i % 3 == 2)
		{
			positionx[i] = 0;
			positiony[i] = 256;
		}
	}
	tamago = sprite_load(L"./Data/Images/tamago.png");
	octopus = sprite_load(L"./Data/Images/octopus.png");
	chikuwa = sprite_load(L"./Data/Images/chikuwa.png");
}

void object::update(int timer)
{
	
	count = ((timer / 1) + 1) * 3;
	if (count >= 6)
	{
		count = 6;
	}

	for (int i = 0; i < count; i++)
	{
		if (i % 3 == 0||i % 3 == 2)
		{
			if (i % 3 == 0)
			{
				positionx[i] += 5;
			}
			if (i % 3 == 2)
			{
				positionx[i] += 4;
			}
			if (positionx[i] > SCREEN_W + 128)
			{
				positionx[i] = 0;
			}
		}
		if (i % 3 == 1)
		{
			positionx[i] -= 5;
			if (positionx[i] < 0)
			{
				positionx[i] = SCREEN_W;
			}
		}
	}
}

void object::render()
{
	for (int i = 0; i < count; i++)
	{
		if (i % 3 == 0)
		{
			sprite_render(
				octopus,
				positionx[i], positiony[i],
				1, 1,
				0, 0,
				128, 128,
				0, 0,
				ToRadian(90)
			);
		}
		if (i % 3 == 1)
		{
			sprite_render(
				tamago,
				positionx[i], positiony[i] + 128,
				1, 1,
				0, 0,
				128, 128,
				0, 0,
				ToRadian(270)
			);
		}
		if (i % 3 == 2)
		{
			sprite_render(
				chikuwa,
				positionx[i], positiony[i],
				1, 1,
				0, 0,
				128, 128,
				0, 0,
				ToRadian(90)
			);
		}
	}
}

void object::render_delete()
{
	safe_delete(tamago);
}