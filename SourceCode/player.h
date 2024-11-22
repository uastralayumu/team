#pragma once

class player
{
public:
	void init();
	void update();
	void render();
	void render_delete();
	float playerpositionx;
	float playerpositiony;
private:
	int state;
	float playerscalex;
	float playerscaley;
};