#include "all.h"
#include "explanation.h"
#include "player.h"
#include "object.h"
#include "stage.h"
player p1;
object o1;
stage s1;

void explanation::init()
{
	p1.init();
	o1.init();
	s1.init();
}

void explanation::update()
{
	
	
}

void explanation::render()
{
	GameLib::setBlendMode(Blender::BS_ALPHA);
	s1.render();
	p1.render();
	o1.render();
	
}