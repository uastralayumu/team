#include "title.h"
#include "all.h"

Sprite* title1;

void title::init()
{
	title1 = sprite_load(L"./Data/Images/title.png");
}


void title::render()
{
	sprite_render(title1, 0, 0);
	GameLib::text_out(5, "ENTER START", 1280, 600, 2, 2, 0, 0, 0, 1, TEXT_ALIGN::UPPER_RIGHT);
}

void title::render_delete()
{
	safe_delete(title1);
}