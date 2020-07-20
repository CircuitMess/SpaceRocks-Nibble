#ifndef SPACEROCKS_PAUSESTATE_H
#define SPACEROCKS_PAUSESTATE_H

#include "State.hpp"
#include "Ship/Ship.h"
#include "Asteroid/AsteroidPool.h"
class PauseState : public State
{
public:
	PauseState(Sprite* sprite);
	~PauseState();
	void update(uint _time, SpaceRocks& game) override;
	void draw() override;
	void start(SpaceRocks& game) override;
private:
	static PauseState* instance;
};


#endif