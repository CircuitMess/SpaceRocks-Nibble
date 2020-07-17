#ifndef BLOCKTRIS_GAMESTATE_H
#define BLOCKTRIS_GAMESTATE_H
#include <Display/Sprite.h>
#include "../ByteBoy.hpp"
class SpaceRocks;
class State
{
public:
	State(Sprite* sprite) : display(sprite) {}
	virtual ~State();
	virtual void start(SpaceRocks& game) = 0;
	virtual void update(uint _time, SpaceRocks& game) = 0;
	virtual void draw() = 0;
protected:
	Sprite* display;
	SpaceRocks* game;
};


#endif