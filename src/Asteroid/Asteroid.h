#ifndef SPACEROCKS_ASTEROID_H
#define SPACEROCKS_ASTEROID_H

#include <Arduino.h>
#include <Display/Sprite.h>


enum AsteroidType
{
	asteroid,
	rock,
	pebble,
	destroyed = -1
};

class Asteroid
{
public:
	Asteroid();
	~Asteroid();
	void init(float _x, float _y, float _xVel, float _yVel, AsteroidType _type);
	void update(Sprite* canvas);
	void draw(Sprite* canvas);
	bool inUse();

private:
	float x, y;
	float xVel, yVel;
	AsteroidType type;
	uint8_t look;
	static const uint16_t *bitmaps[3][3];
	static constexpr uint8_t bitmapSizes[3] = {24, 16, 10};
};

#endif