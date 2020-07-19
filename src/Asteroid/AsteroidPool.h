#ifndef SPACEROCKS_ASTEROIDPOOL_H
#define SPACEROCKS_ASTEROIDPOOL_H
#include <Arduino.h>
#include <Display/Sprite.h>
#include "Asteroid.h"
class AsteroidPool
{
public:
	void create(float x, float y, float xVel, float yVel, AsteroidType _type, uint8_t look);
	void update(Sprite* canvas);
	void draw(Sprite* canvas);
	void broken(uint8_t index);
	static const int POOL_SIZE = 100;
	Asteroid asteroids[POOL_SIZE];
};


#endif