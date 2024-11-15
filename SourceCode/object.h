#pragma once

class object
{
public:
	void init();
	void update(int timer);
	void render();
	void render_delete();
private:
	
	int overcount;
	int centercount;
	int undercount;
	const int overnumber = 10;
	const int centernumber = 9;
	const int undernumber = 13;
	float overpositionx[10];
	float overpositiony[10];
	float centerpositionx[10];
	float centerpositiony[10];
	float underpositionx[13];
	float underpositiony[13];
	int overchange[10];
	int centerchange[10];
	int underchange[13];
};