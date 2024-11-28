#include "all.h"
#include "explanation.h"
#include "player.h"
#include "object.h"
#include "stage.h"

extern player p;
extern object o;
extern stage s;
Sprite* osinagakiexplanation;
Sprite* timerexplanation;
Sprite* coment1;
Sprite* coment2;
Sprite* coment3;

void explanation::init()
{
	s.init();
	p.init();
	o.init();
	o.explanationinit();
	osinagakiexplanation = sprite_load(L"./Data/Images/osinagakiexplanation.png");
	timerexplanation = sprite_load(L"./Data/Images/timerexplanation.png");
	coment1 = sprite_load(L"./Data/Images/coment1.png");
	coment2 = sprite_load(L"./Data/Images/coment2.png");
	coment3 = sprite_load(L"./Data/Images/coment3.png");

}

void explanation::render()
{
	
	s.render();
	p.render();
	o.render();
	sprite_render(
		osinagakiexplanation,
		150,700,
		1,1
		);
	sprite_render(
		timerexplanation,
		40, 30);
	sprite_render(
		coment1,
		1400,300
	);
	sprite_render(
		coment2,
		960, 650
	);
	sprite_render(
		coment3,
		1600, 0
	);
}

void explanation::render_delete()
{
	safe_delete(osinagakiexplanation);
	safe_delete(timerexplanation);
	safe_delete(coment1);
	safe_delete(coment2);
	safe_delete(coment3);
}