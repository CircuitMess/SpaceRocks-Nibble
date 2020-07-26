#ifndef SPACEROCKS_PAUSESTATE_H
#define SPACEROCKS_PAUSESTATE_H

#include "State.hpp"
#include "Ship/Ship.h"
#include "Asteroid/AsteroidPool.h"

namespace SpaceRocks
{

class PauseState : public State
{
public:
	PauseState(Sprite* sprite);
	void update(uint _time, SpaceRocks& game) override;
	void draw() override;
	void start(SpaceRocks& game) override;
	void stop() override;
private:
	static PauseState* instance;
};

};

#endif