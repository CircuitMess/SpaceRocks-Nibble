#ifndef SPACEROCKS_BULLETPOOL_H
#define SPACEROCKS_BULLETPOOL_H
#include <Arduino.h>
#include <Display/Sprite.h>
#include "Asteroid.h"
class AsteroidPool
{
public:
	void create(float x, float y, float xVel, float yVel, AsteroidType _type);
	void update(Sprite* canvas);
	void draw(Sprite* canvas);
private:
	static const int POOL_SIZE = 8;
	Asteroid asteroids[POOL_SIZE];

};


#endif