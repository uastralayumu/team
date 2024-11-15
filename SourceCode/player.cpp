#include "player.h"
#include "all.h"

Sprite* playercontroller;



void player::init()
{
	state = 0;
	playerpositionx = SCREEN_W / 2 - 50;
	playerpositiony = SCREEN_H - 300;
	playerscalex = 2.5;
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
		if (STATE(0) & PAD_LEFT && playerpositionx > 0)
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
			playerpositiony = SCREEN_H - 300;
			state--;
		}
		break;
	}

}

void player::render()
{
	sprite_render(
		playercontroller,
		playerpositionx, playerpositiony,
		playerscalex, playerscaley,
		56, 20,
		64, 128
	);

	
}

void player::render_delete()
{
	safe_delete(playercontroller);
	
}