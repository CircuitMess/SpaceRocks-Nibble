#ifndef SPACEROCKS_TITLESTATE_H
#define SPACEROCKS_TITLESTATE_H

#include "State.hpp"
#include "Ship/Ship.h"

class TitleState : public State
{
public:
	TitleState(Sprite* sprite);
	~TitleState();
	void update(uint _time, SpaceRocks& game) override;
	void draw() override;
	void start(SpaceRocks& game) override;
private:
	static const char *titleMenu[3] PROGMEM;
	Ship* ship;
	uint8_t titleCursor;
	bool blinkState;
	uint blinkMicros;
	static TitleState* instance;
};


#endif