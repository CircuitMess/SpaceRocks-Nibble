#ifndef SPACEROCKS_ERASEHIGHSCORESTATE_H
#define SPACEROCKS_ERASEHIGHSCORESTATE_H

#include "State.hpp"

namespace SpaceRocks
{

class EraseHighscoreState : public State
{
public:
	EraseHighscoreState(Sprite *sprite);
	void update(uint _time, SpaceRocks& game) override;
	void draw() override;
	void start(SpaceRocks& _game) override;
	void stop() override;
private:
	static EraseHighscoreState *instance;
	uint blinkTime;
	bool blinkState;
};

};

#endif