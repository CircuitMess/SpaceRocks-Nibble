#include "Bullet.h"

Bullet::Bullet() : framesLeft(0)
{
}

Bullet::~Bullet()
{
}
bool Bullet::inUse()
{
	return framesLeft > 0;
}
void Bullet::init(float _x, float _y, float _xVel, float _yVel, uint lifetime)
{
	x=_x;
	y=_y;
	xVel = _xVel;
	yVel = _yVel;
	framesLeft = lifetime;
}
void Bullet::update(Sprite* canvas)
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
void Bullet::draw(Sprite* canvas)
{
	if(!inUse() > 0) return;
	canvas->fillRect(x, y, 2, 2, TFT_WHITE);
}
void Bullet::hit()
{
	framesLeft = 0;
}