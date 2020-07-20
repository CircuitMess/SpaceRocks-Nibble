#include "Asteroid.h"
#include "../bitmaps/asteroid1.hpp"
#include "../bitmaps/asteroid2.hpp"
#include "../bitmaps/asteroid3.hpp"
#include "../bitmaps/rock1.hpp"
#include "../bitmaps/rock2.hpp"
#include "../bitmaps/rock3.hpp"
#include "../bitmaps/pebble1.hpp"
#include "../bitmaps/pebble2.hpp"
#include "../bitmaps/pebble3.hpp"
const uint16_t *Asteroid::bitmaps[3][3] = {
	{asteroid1, asteroid2, asteroid3},
	{rock1, rock2, rock3},
	{pebble1, pebble2, pebble3}
};
constexpr uint8_t Asteroid::bitmapSizes[3];
constexpr uint8_t Asteroid::hitboxWidth[3];
Asteroid::Asteroid() : type(AsteroidType::destroyed)
{
}

Asteroid::~Asteroid()
{
}

bool Asteroid::inUse()
{
	return !(type == AsteroidType::destroyed);
}

void Asteroid::init(float _x, float _y, float _xVel, float _yVel, AsteroidType _type, uint8_t _look)
{
	x=_x;
	y=_y;
	xVel = _xVel;
	yVel = _yVel;
	type = _type;
	look = _look;
}
void Asteroid::update(Sprite* canvas)
{
	if(!inUse()) return;



	//out-of-bounds handling
	uint8_t asteroidWidth = 5 - uint8_t(type);
	Serial.println(asteroidWidth);

	if (int(x) < asteroidWidth){
		x = canvas->width() - 3*asteroidWidth;
	}
	if (int(x) > canvas->width() - 2*asteroidWidth){
		x = asteroidWidth;
	}
	if (int(y) < asteroidWidth){
		y = canvas->height() - 3*asteroidWidth;
	}
	if (int(y) > canvas->height() - 2*asteroidWidth){
		y = asteroidWidth;
	}

	x+=xVel;
	y+=yVel;

	Serial.printf("x: %.4f, y: %.4f\n", x, y);
}
void Asteroid::draw(Sprite* canvas)
{
	if(!inUse()) return;
	canvas->drawIcon(bitmaps[uint8_t(type)][look], x, y, bitmapSizes[uint8_t(type)], bitmapSizes[uint8_t(type)], 1, TFT_WHITE);

	//hitbox drawing
	// canvas->fillRect(x, y, bitmapSizes[uint8_t(type)], bitmapSizes[uint8_t(type)], TFT_RED);
}
uint8_t Asteroid::getWidth()
{
	if(!inUse()) return 0;
	return bitmapSizes[uint8_t(type)];
}
void Asteroid::destroyed()
{
	type = AsteroidType::destroyed;
}