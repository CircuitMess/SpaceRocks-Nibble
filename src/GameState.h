#ifndef SPACEROCKS_GAMESTATE_H
#define SPACEROCKS_GAMESTATE_H

#include "State.hpp"
#include "Ship/Ship.h"

class GameState : public State
{
public:
	GameState(Sprite* sprite);
	~GameState();
	void update(uint _time, SpaceRocks& game) override;
	void draw() override;
	void start(SpaceRocks& game) override;

	uint8_t life;
	uint32_t score;
	uint8_t level;
	uint16_t asteroidTime;
private:
	static const char *titleMenu[3] PROGMEM;
	Ship* ship;
	uint8_t titleCursor;
	bool blinkState;
	uint blinkMicros;
	static GameState* instance;
};


#endif