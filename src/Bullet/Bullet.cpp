#include "Bullet.h"

SpaceRocks::Bullet::Bullet() : framesLeft(0)
{
}

SpaceRocks::Bullet::~Bullet()
{
}
bool SpaceRocks::Bullet::inUse()
{
	return framesLeft > 0;
}
void SpaceRocks::Bullet::init(float _x, float _y, float _xVel, float _yVel, uint lifetime)
{
	x=_x;
	y=_y;
	xVel = _xVel;
	yVel = _yVel;
	framesLeft = lifetime;
}
void SpaceRocks::Bullet::update(Sprite* canvas)
{
	if(!inUse() > 0) return;
	framesLeft--;
	x+=xVel;
	y+=yVel;
	if (x < -5) x = x + canvas->width()+10;
	if (x > canvas->width()+5) x = x - canvas->width()-10;
	if (y < -5) y = y + canvas->height()+10;
	if (y > canvas->height()+5) y = y - canvas->height()-10;
}
void SpaceRocks::Bullet::draw(Sprite* canvas)
{
	if(!inUse() > 0) return;
	canvas->fillRect(x, y, 2, 2, TFT_WHITE);
}
void SpaceRocks::Bullet::hit()
{
	framesLeft = 0;
}