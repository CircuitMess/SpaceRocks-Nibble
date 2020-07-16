#ifndef BLOCKTRIS_GAMESTATE_H
#define BLOCKTRIS_GAMESTATE_H
#include <Display/Sprite.h>
#include "../ByteBoy.hpp"
class State
{
public:
	virtual ~State(){}
	virtual void update(uint);
	virtual void draw();
protected:
	Sprite* display;
	Game* game;
};


#endif