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
	const int overnumber = 7;
	const int centernumber = 7;
	const int undernumber = 9;
	float overpositionx[9];
	float overpositiony[9];
	float centerpositionx[9];
	float centerpositiony[9];
	float underpositionx[9];
	float underpositiony[9];
	int overchange[9];
	int centerchange[9];
	int underchange[9];
};