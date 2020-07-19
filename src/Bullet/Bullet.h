#ifndef SPACEROCKS_BULLET_H
#define SPACEROCKS_BULLET_H
#include <Display/Sprite.h>
class Bullet
{

public:
	Bullet();
	~Bullet();
	void init(float _x, float _y, float _xVel, float _yVel, uint lifetime);
	void update(Sprite* canvas);
	void draw(Sprite* canvas);
	bool inUse();
	void hit();
	float x, y;
private:
	uint framesLeft;
	float xVel, yVel;
};



#endif