#include "MoonLander.h"

MoonLander::MoonLander()
{
	velocity = 0;
	acceleration.set(0, 3.00f / Tools::scale,0);
	pos = 0;
	xPlusEngineOn = false;
	xMinusEngineOn = false;
	zPlusEngineOn = false;
	zMinusEngineOn = false;
	engineOn = false;
	sideEngineA = 0.05 / Tools::scale;

}
void MoonLander::position(Vector3f currpos)
{
	pos = currpos;
}
void MoonLander::v(Vector3f currvel)
{
	velocity = currvel;
}
void MoonLander::a(Vector3f curracc)
{
	acceleration = curracc;
}
Vector3f MoonLander::position()
{
	return pos;
}
Vector3f MoonLander::v()
{
	return velocity;
}
Vector3f MoonLander::a()
{
	return acceleration;
}
void MoonLander::calcPosition()
{
	if (pos.y <= -70.0f)
	{
		pos.y = -70.0f;
		acceleration.set(0, 3.00f / Tools::scale, 0);
		velocity = 0.0f;
	}
	if (engineOn) 
	{
		velocity.y += Tools::refreshFreq * acceleration.y;
	}
	if (xPlusEngineOn)
	{
		if (acceleration.x < 0)
			acceleration.x = 0;
		if (acceleration.x <= sideEngineA)
		{
			acceleration.x +=  0.2;
		}
	}
	if (xMinusEngineOn) 
	{
		if (acceleration.x > 0)
			acceleration.x = 0;
		if (acceleration.x >= -sideEngineA)
		{
			acceleration.x -= 0.2;
		}
	}
	if (zPlusEngineOn)
	{
		if (acceleration.z < 0)
			acceleration.z = 0;
		if (acceleration.z <= sideEngineA)
		{
			acceleration.z += 0.2;
		}
	}
	if (zMinusEngineOn) 
	{
		if (acceleration.z > 0)
			acceleration.z = 0;
		if (acceleration.z >= -sideEngineA)
		{
			acceleration.z -= 0.2;
		}
	}
	velocity.x += Tools::refreshFreq * acceleration.x / Tools::scale;
	velocity.y += Tools::refreshFreq * Tools::moonA / Tools::scale;
	velocity.z += Tools::refreshFreq * acceleration.z / Tools::scale;
	pos.x += Tools::refreshFreq * velocity.x;
	pos.y += Tools::refreshFreq * (velocity.y + Tools::refreshFreq * Tools::moonA/Tools::scale / 2);
	pos.z += Tools::refreshFreq * velocity.z;
}
void MoonLander::checkEngines(bool *engine)
{
	engineOn = engine[0];
	xPlusEngineOn = engine[1];
	xMinusEngineOn = engine[2];
	zPlusEngineOn = engine[3];
	zMinusEngineOn = engine[4];
}