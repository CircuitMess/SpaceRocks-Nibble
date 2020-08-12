#ifndef SPACEROCKS_SHOWHIGHSCORESTATE_H
#define SPACEROCKS_SHOWHIGHSCORESTATE_H

#include "State.hpp"

namespace SpaceRocks
{

class ShowHighscoreState : public State
{
public:
	ShowHighscoreState(Sprite *sprite);
	void update(uint _time, SpaceRocks& game) override;
	void draw() override;
	void start(SpaceRocks& _game) override;
	void stop() override;
private:
	static ShowHighscoreState *instance;

};

};

#endif