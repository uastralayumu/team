#include "stage.h"
#include "all.h"
#include "result.h"
extern result r;
Sprite* gamescene;

void stage::init()
{
	gamescene = sprite_load(L"./Data/Images/gamescene.png");
}

void stage::render()
{
	sprite_render(gamescene, 0, 0);
	GameLib::text_out(5, std::to_string(r.score), 1850, 0, 2, 2, 0, 0, 0, 1, TEXT_ALIGN::UPPER_RIGHT);
	GameLib::text_out(5, "Pt", 1960, 0, 2, 2, 0, 0, 0, 1, TEXT_ALIGN::UPPER_RIGHT);
}

void stage::render_delete()
{
	safe_delete(gamescene);
}