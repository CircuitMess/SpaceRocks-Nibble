#ifndef SPACEROCKS_BULLETPOOL_H
#define SPACEROCKS_BULLETPOOL_H
#include <Arduino.h>
#include <Display/Sprite.h>
#include "Bullet.h"
class BulletPool
{
public:
	void create(float x, float y, float xVel, float yVel, uint lifetime);
	void update(Sprite* canvas);
	void draw(Sprite* canvas);
private:
	static const int POOL_SIZE = 8;
	Bullet bullets[POOL_SIZE];

};


#endif