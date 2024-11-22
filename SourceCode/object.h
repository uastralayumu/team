#pragma once

class object
{
public:
	void init();
	void update(int timer);
	void render();
	void render_delete();
	//explantion‚Ì‚½‚ß‚Ìinit
	void explanationinit();

	float overpositionx[9];
	float overpositiony[9];
	float centerpositionx[9];
	float centerpositiony[9];
	float underpositionx[13];
	float underpositiony[13];
	int overchange[9];
	int centerchange[9];
	int underchange[13];
private:
	int odentimer1,odentimer2,odentimer3;
	int overcount;
	int centercount;
	int undercount;
	const int overnumber = 9;
	const int centernumber = 9;
	const int undernumber = 13;
};