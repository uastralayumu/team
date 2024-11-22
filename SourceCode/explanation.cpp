#include "all.h"
#include "explanation.h"
#include "player.h"
#include "object.h"
#include "stage.h"

extern player p;
extern object o;
stage s1;
Sprite* osinagakiexplanation;
Sprite* timerexplanation;

void explanation::init()
{
	s1.init();
	p.init();
	o.init();
	o.explanationinit();
	osinagakiexplanation = sprite_load(L"./Data/Images/osinagakiexplanation.png");
	timerexplanation = sprite_load(L"./Data/Images/timerexplanation.png");
}

void explanation::update()
{
	
	
}

void explanation::render()
{
	
	s1.render();
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
}