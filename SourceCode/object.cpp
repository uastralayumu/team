#include "all.h"
#include "object.h"

Sprite* tamago;
Sprite* chikuwa;
Sprite* octopus;
Sprite* konjac;
Sprite* daikon;
Sprite* hanpen;

void object::init()
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < overnumber; i++)
	{

		overpositionx[i] = -128 * 1.5f;
		overpositiony[i] = 100;
		overchange[i] = rand() % 2;
	}
	for (int i = 0; i < centernumber; i++)
	{
		centerpositionx[i] = SCREEN_W;
		centerpositiony[i] = 278;
		centerchange[i] = rand() % 2;
	}
	for (int i = 0; i < undernumber; i++)
	{
		underpositionx[i] = -128;
		underpositiony[i] = 460;
		underchange[i] = rand() % 2;
	}

	tamago = sprite_load(L"./Data/Images/tamago.png");
	octopus = sprite_load(L"./Data/Images/octopus.png");
	chikuwa = sprite_load(L"./Data/Images/chikuwa.png");
	konjac = sprite_load(L"./Data/Images/konjac.png");
	daikon = sprite_load(L"./Data/Images/daikon.png");
	hanpen = sprite_load(L"./Data/Images/hanpen.png");
}

void object::update(int timer)
{

	overcount = timer + 1;
	if (overcount >= overnumber)
	{
		overcount = overnumber;
	}
	centercount = timer + 1;
	if (centercount >= centernumber)
	{
		centercount = centernumber;
	}
	undercount = timer + 1;
	if (undercount >= undernumber)
	{
		undercount = undernumber;
	}

	for (int i = 0; i < overcount; i++)
	{
		overpositionx[i] += 4;
		if (overpositionx[i] > SCREEN_W + 128 && (overpositionx[overnumber - 1] > 96 && i + overnumber == overnumber || i != 0 && overpositionx[i - 1] > 64))
		{
			overpositionx[i] = -128 * 1.5f;
			overchange[i] = rand() % 2;
		}
	}
	for (int i = 0; i < undercount; i++)
	{
		underpositionx[i] += 3;
		if (underpositionx[i] > SCREEN_W + 128 && (underpositionx[undernumber - 1] > 32 && i + undernumber == undernumber || i != 0 && underpositionx[i - 1] > 32))
		{
			underpositionx[i] = -128;
			underchange[i] = rand() % 2;
		}
	}
	for (int i = 0; i < centercount; i++)
	{
		centerpositionx[i] -= 4;
		if (centerpositionx[i] < -128 && (centerpositionx[centernumber - 1] < SCREEN_W - 192 && i + centernumber == centernumber || i != 0 && centerpositionx[i - 1] < SCREEN_W - 192))
		{
			centerpositionx[i] = SCREEN_W;
			centerchange[i] = rand() % 2;
		}
	}
}

void object::render()
{
	for (int i = 0; i < overcount; i++)
	{
		if (overchange[i] == 0)
		{
			sprite_render(
				hanpen,
				overpositionx[i], overpositiony[i],
				1, 1,
				0, 0,
				128, 128,
				0, 0,
				ToRadian(0)
			);
		}
		else
		{
			sprite_render(
				konjac,
				overpositionx[i], overpositiony[i],
				1, 1,
				0, 0,
				128, 128,
				0, 0,
				ToRadian(0)
			);
		}
	}
	for (int i = 0; i < centercount; i++)
	{
		if (centerchange[i] == 0)
		{
			sprite_render(
				tamago,
				centerpositionx[i], centerpositiony[i] + 128,
				1, 1,
				0, 0,
				128, 128,
				0, 0,
				ToRadian(270)
			);
		}
		else
		{
			sprite_render(
				daikon,
				centerpositionx[i], centerpositiony[i],
				1, 1,
				0, 0,
				128, 128,
				0, 0,
				ToRadian(0)
			);
		}

	}
	for (int i = 0; i < undercount; i++)
	{
		if (underchange[i] == 0)
		{
		sprite_render(
			chikuwa,
			underpositionx[i], underpositiony[i],
			1, 1,
			0, 0,
			128, 128,
			0, 0,
			ToRadian(0)
		);
		}
		else
		{
			sprite_render(
				octopus,
				underpositionx[i], underpositiony[i],
				1, 1,
				0, 0,
				128, 128,
				0, 0,
				ToRadian(0)
			);
		}
	}
}