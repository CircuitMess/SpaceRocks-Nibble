#include "AsteroidPool.h"
void SpaceRocks::AsteroidPool::create(float x, float y, float xVel, float yVel, AsteroidType _type, uint8_t look)
{
	for(uint8_t i = 0; i < POOL_SIZE; i++)
	{
		if(!asteroids[i].inUse())
		{
			asteroids[i].init(x, y, xVel, yVel, _type, look);
			return;
		}
	}
}
void SpaceRocks::AsteroidPool::update(Sprite* canvas)
{
	for(uint8_t i = 0; i < POOL_SIZE; i++)
	{
		asteroids[i].update(canvas);
	}
}
void SpaceRocks::AsteroidPool::draw(Sprite* canvas)
{
	for(uint8_t i = 0; i < POOL_SIZE; i++)
	{
		asteroids[i].draw(canvas);
	}
}
void SpaceRocks::AsteroidPool::broken(uint8_t index)
{
	if(!asteroids[index].inUse()) return;
	if(asteroids[index].type != AsteroidType::pebble)
	{
		create(asteroids[index].x, asteroids[index].y, random(-10, 10) * 0.05, random(-10, 10) * 0.05,
			AsteroidType(uint8_t(asteroids[index].type) + 1), random(0,3));
		create(asteroids[index].x, asteroids[index].y, random(-10, 10) * 0.05, random(-10, 10) * 0.05,
			AsteroidType(uint8_t(asteroids[index].type) + 1), random(0,3));
	}
	asteroids[index].destroyed();
}