#include "player.h"
#include "all.h"

Sprite* playercontroller;



void player::init()
{
	state = 0;
	playerpositionx = SCREEN_W / 2 - 50;
	playerpositiony = SCREEN_H - 400;
	playerscalex = 2.5f;
	playerscaley = 2.5f;
	playercontroller = sprite_load(L"./Data/Images/kusi.png");
	
}


void player::update()
{
	using namespace input;
	switch (state) {
	case 0:
		state++;
	case 1:
		if (STATE(0) & PAD_LEFT && playerpositionx > 500)
		{
			playerpositionx -= 5;

		}
		if (STATE(0) & PAD_RIGHT && playerpositionx < 1240)
		{
			playerpositionx += 5;
		}
		if (TRG(0) & PAD_START)
		{
			state++;
		}
		break;
	case 2:

		playerpositiony -= 15;
		if (playerpositiony < -500)
		{
			playerpositiony = SCREEN_H - 400;
			state--;
		}
		break;
	}

}

void player::render(int timer)
{
	sprite_render(
		playercontroller,
		playerpositionx, playerpositiony,
		playerscalex, playerscaley,
		56, 0,
		64, 128
	);

		sprite_render(
			playercontroller,
			390, 28,
			2.5, 2.5,
			56, 0,
			64, 128,
			0, 0,
			ToRadian(90)
		);
}

void player::render_delete()
{
	safe_delete(playercontroller);
	
}