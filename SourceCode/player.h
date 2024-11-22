#pragma once

class player
{
public:
	void init();
	void update();
	void render();
	void render_delete();
	void GettherX();
	float GettherY();
private:
	int state;
	
	float playerpositionx;
	float playerpositiony;
	float playerscalex;
	float playerscaley;
};