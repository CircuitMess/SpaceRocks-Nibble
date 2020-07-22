#ifndef SPACEROCKS_GAMESTATE_H
#define SPACEROCKS_GAMESTATE_H

#include "State.hpp"
#include "Ship/Ship.h"
#include "Asteroid/AsteroidPool.h"

namespace SpaceRocks
{

class GameState : public State
{
public:
	GameState(Sprite* sprite);
	~GameState();
	void update(uint _time, SpaceRocks& game) override;
	void draw() override;
	void start(SpaceRocks& game) override;
	void stop() override;
	bool rectRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);
	void newLevel();

	
	uint8_t life;
	uint32_t score;
	uint8_t level;
	uint16_t asteroidTime;
private:
	static const char *titleMenu[3] PROGMEM;
	Ship* ship;
	Ship* UIship;
	AsteroidPool asteroids;
	uint8_t titleCursor;
	bool blinkState;
	uint blinkMicros;
	static GameState* instance;
	bool dead;
	uint deadTime;
	uint levelChangeTime;


};

};

#endif