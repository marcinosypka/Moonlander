#pragma once
#include "Tools.h"
#include "Vector3f.h"


class MoonLander {

public:
	MoonLander();

	Vector3f position();
	void     position(Vector3f currpos);
	Vector3f v();
	void	 v(Vector3f currvel);
	Vector3f a();
	void	 a(Vector3f curracc);
	void checkEngines(bool *engine);
	void calcPosition();
	Vector3f pos;
private:
	bool engineOn;
	bool xPlusEngineOn;
	bool xMinusEngineOn;
	bool zPlusEngineOn;
	bool zMinusEngineOn;
	Vector3f acceleration;
	Vector3f velocity;
	double sideEngineA;
	
	double mass;


};