#include "AsteroidPool.h"
void AsteroidPool::create(float x, float y, float xVel, float yVel, AsteroidType _type)
{
	for(uint8_t i = 0; i < POOL_SIZE; i++)
	{
		if(!asteroids[i].inUse())
		{
			asteroids[i].init(x, y, xVel, yVel, _type);
			return;
		}
	}
}
void AsteroidPool::update(Sprite* canvas)
{
	for(uint8_t i = 0; i < POOL_SIZE; i++)
	{
		asteroids[i].update(canvas);
	}
}
void AsteroidPool::draw(Sprite* canvas)
{
	for(uint8_t i = 0; i < POOL_SIZE; i++)
	{
		asteroids[i].draw(canvas);
	}
}