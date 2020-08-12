#ifndef SPACEROCKS_ENTERHIGHSCORESTATE_H
#define SPACEROCKS_ENTERHIGHSCORESTATE_H

#include "State.hpp"

namespace SpaceRocks
{

class EnterHighscoreState : public State
{
public:
	EnterHighscoreState(Sprite *sprite);
	~EnterHighscoreState();
	void update(uint _time, SpaceRocks& game) override;
	void draw() override;
	void start(SpaceRocks& _game) override;
	void stop() override;
private:
	static EnterHighscoreState *instance;

	char* name;
	uint8_t charCursor;
	bool cursorBlink;
	bool hiscoreBlink;
	uint cursorTime;
	uint hiscoreTime;
};

};

#endif