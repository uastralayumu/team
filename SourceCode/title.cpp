#include "title.h"
#include "all.h"

Sprite* title1;
title::title()
{

}

title::~title()
{

}

void title::init()
{
	title1 = sprite_load(L"./Data/Images/title.png");
}

void title::update()
{
	
}

void title::render()
{
	sprite_render(title1, 0, 0);
}