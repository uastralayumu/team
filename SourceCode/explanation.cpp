#include "all.h"
#include "explanation.h"
#include "player.h"
#include "object.h"
#include "stage.h"
player p1;
object o1;
stage s1;
Sprite* osinagakiexplanation;

void explanation::init()
{
	s1.init();
	p1.init();
	o1.init();
	o1.explanationinit();
	osinagakiexplanation = sprite_load(L"./Data/Images/osinagakiexplanation.png");
}

void explanation::update()
{
	
	
}

void explanation::render()
{
	
	s1.render();
	p1.render();
	o1.render();
	sprite_render(
		osinagakiexplanation,150,700,
		1,1
		);
}