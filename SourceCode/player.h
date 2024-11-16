#pragma once

class player
{
public:
	void init();
	void update();
	void render();
	void render_delete();
private:
	int state;
	float playerpositionx;
	float playerpositiony;
	float playerscalex;
	float playerscaley;
};