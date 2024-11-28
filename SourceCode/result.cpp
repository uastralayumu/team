#include "all.h"
#include "result.h"
#include "object.h"
#include "player.h"
result r;
extern player p;
extern object o;
extern Sprite* playercontroller;
extern Sprite* konjac;
extern Sprite* daikon;
extern Sprite* chikuwa;
Sprite* result_render;
Sprite* font5;
Sprite* total;

void result::init()
{
	r.score = 0;
	r.judge = 0;
	r.threeoden = 0;
	r.osinagaki = 0;
	result_render= sprite_load(L"./Data/Images/result.png");
	font5 = sprite_load(L"./Data/Fonts/font5.png");
	total = sprite_load(L"./Data/Images/total.png");
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
	} while (place <= r.score);

	sprite_render(font5, 884, 440, 2.2, 2.2, 0, 160, 32, 32, 0, 0, ToRadian(-9), 0, 0, 0, 1);
	sprite_render(font5, 932, 435, 2, 2, 128, 224, 32, 32, 0, 0, ToRadian(-9), 0, 0, 0, 1);
	sprite_render(playercontroller, 260, 614, 2.5, 2.5);
	sprite_render(konjac, 360, 620);
	sprite_render(daikon, 360, 710);
	sprite_render(chikuwa, 360, 780);
	sprite_render(total, 600, 770,2,2,0,0,640,64,0,0,ToRadian(-8));
	place = 1;
	i = 1;
	do {
		sprite_render(font5, 1002 - i * 32, 700 + i * 5,2.2,2.2,32 *((r.threeoden / place) % 10),
			96,32,32,0,0,ToRadian(-8),0,0,0);
		place *= 10;
		i++;
	} while (place <= r.threeoden);
	place = 1;
	i = 1;
	do {
		sprite_render(font5, 985 - i * 32, 760 + i * 5, 2.2, 2.2, 32 * ((r.osinagaki / place) % 10),
			96, 32, 32, 0, 0, ToRadian(-8), 0, 0, 0);
		place *= 10;
		i++;
	} while (place <= r.osinagaki);
}

void result::render_delete()
{
	safe_delete(result_render);
	safe_delete(font5);
	safe_delete(total);
	o.render_delete();
	p.render_delete();
}