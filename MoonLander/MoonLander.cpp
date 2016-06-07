#include "MoonLander.h"

MoonLander::MoonLander()
{
	engineForce = 9;
	mass = 1;
	fuelmass = 2;
	fullmass = mass + fuelmass;
	velocity = 0;
	acceleration.set(0, (9 / fullmass )/ Tools::scale,0);
	pos = 0;
	xPlusEngineOn = false;
	xMinusEngineOn = false;
	zPlusEngineOn = false;
	zMinusEngineOn = false;
	engineOn = false;
	sideEngineA = 0.5 / Tools::scale;



}

void MoonLander::position(Vector3f currpos)
{
	pos = currpos;
}
void MoonLander::refuel()
{
	fuelmass = 2;
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
float MoonLander::fuelLeft()
{
	return fuelmass;
}
void MoonLander::calcPosition()
{
	if (fuelmass >= 0)
	{
	for (int i = 0; i < 5; i++)
	{
		if (engine[i] == true)
		{
			fuelmass -= 0.0005;
			fullmass = mass + fuelmass;
			acceleration.y = (9 / fullmass) / Tools::scale;
		}
	}

		if (engineOn)
		{
			velocity.y += Tools::refreshFreq * acceleration.y;
		}
		if (xPlusEngineOn)
		{

			if (acceleration.x <= sideEngineA)
			{
				acceleration.x += 0.4;
			}
			velocity.x += Tools::refreshFreq * acceleration.x / Tools::scale;
		}
		if (xMinusEngineOn)
		{
			if (acceleration.x > 0)
				acceleration.x = 0;
			if (acceleration.x >= -sideEngineA)
			{
				acceleration.x -= 0.4;
			}
			velocity.x += Tools::refreshFreq * acceleration.x / Tools::scale;
		}
		if (zPlusEngineOn)
		{

			if (acceleration.z <= sideEngineA)
			{
				acceleration.z += 0.4;
			}
			velocity.z += Tools::refreshFreq * acceleration.z / Tools::scale;

		}
		if (zMinusEngineOn)
		{
			if (acceleration.z >= -sideEngineA)
			{
				acceleration.z -= 0.5;
			}
			velocity.z += Tools::refreshFreq * acceleration.z / Tools::scale;
		}
	}
	velocity.y += Tools::refreshFreq * Tools::moonA / Tools::scale;

	pos.x += Tools::refreshFreq * velocity.x;
	pos.y += Tools::refreshFreq * (velocity.y + Tools::refreshFreq * Tools::moonA/Tools::scale / 2);
	pos.z += Tools::refreshFreq * velocity.z;
	if (pos.y <= 0.0f)
	{
		pos.y = 0.0f;
		acceleration.set(0, 3.00f / Tools::scale, 0);
		velocity = 0;
	}
}
void MoonLander::checkEngines(bool *engine)
{
	this->engine = engine;
	engineOn = engine[0];
	xPlusEngineOn = engine[1];
	xMinusEngineOn = engine[2];
	zPlusEngineOn = engine[3];
	zMinusEngineOn = engine[4];
}