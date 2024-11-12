#pragma once

class object
{
public:
	void init();
	void update(int timer);
	void render();
	void render_delete();
private:
	int count;
	float positionx[6];
	float positiony[6];
};