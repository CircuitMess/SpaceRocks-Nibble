#include "Asteroid.h"
#include "../bitmaps/spacerocks_asteroid1.hpp"
#include "../bitmaps/spacerocks_asteroid2.hpp"
#include "../bitmaps/spacerocks_asteroid3.hpp"
#include "../bitmaps/spacerocks_rock1.hpp"
#include "../bitmaps/spacerocks_rock2.hpp"
#include "../bitmaps/spacerocks_rock3.hpp"
#include "../bitmaps/spacerocks_pebble1.hpp"
#include "../bitmaps/spacerocks_pebble2.hpp"
#include "../bitmaps/spacerocks_pebble3.hpp"
const uint16_t *SpaceRocks::Asteroid::bitmaps[3][3] = {
	{spacerocks_asteroid1, spacerocks_asteroid2, spacerocks_asteroid3},
	{spacerocks_rock1, spacerocks_rock2, spacerocks_rock3},
	{spacerocks_pebble1, spacerocks_pebble2, spacerocks_pebble3}
};
constexpr uint8_t SpaceRocks::Asteroid::bitmapSizes[3];
constexpr uint8_t SpaceRocks::Asteroid::hitboxWidth[3];
SpaceRocks::Asteroid::Asteroid() : type(AsteroidType::destroyed)
{
}

SpaceRocks::Asteroid::~Asteroid()
{
}

bool SpaceRocks::Asteroid::inUse()
{
	return !(type == AsteroidType::destroyed);
}

void SpaceRocks::Asteroid::init(float _x, float _y, float _xVel, float _yVel, AsteroidType _type, uint8_t _look)
{
	x=_x;
	y=_y;
	xVel = _xVel;
	yVel = _yVel;
	type = _type;
	look = _look;
}
void SpaceRocks::Asteroid::update(Sprite* canvas)
{
	if(!inUse()) return;

	//out-of-bounds handling
	uint8_t asteroidWidth = 5 - uint8_t(type);
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

}
void SpaceRocks::Asteroid::draw(Sprite* canvas)
{
	if(!inUse()) return;
	canvas->drawIcon(bitmaps[uint8_t(type)][look], x, y, bitmapSizes[uint8_t(type)], bitmapSizes[uint8_t(type)], 1, TFT_WHITE);

	//hitbox drawing
	// canvas->fillRect(x, y, bitmapSizes[uint8_t(type)], bitmapSizes[uint8_t(type)], TFT_RED);
}
uint8_t SpaceRocks::Asteroid::getWidth()
{
	if(!inUse()) return 0;
	return bitmapSizes[uint8_t(type)];
}
void SpaceRocks::Asteroid::destroyed()
{
	type = AsteroidType::destroyed;
}