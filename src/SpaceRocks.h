#ifndef SPACEROCKS_H
#define SPACEROCKS_H

#include <Arduino.h>
#include <CircuitOS.h>
#include <Input/Input.h>
#include <Update/UpdateManager.h>
#include <gpio.h>
#include <avr/pgmspace.h>
#include <Support/Context.h>
#include "../Nibble.hpp"
#include <UI/Image.h>
#include <Display/Sprite.h>
#include "State.hpp"

class SpaceRocks : public Context, public UpdateListener
{
public:
	SpaceRocks(Display& Display);
	void draw() override;
	void start() override;
	void update(uint _time) override;
	void stop() override;

	void newGame();
	void enterHighscore();
	void openHighscores();
	void pauseGame();
	void gameOver();
	void resumeGame();
	void quitGame();
	uint score;
private:
	State *state;
	State *pausedGameState;
	Display *display;
	Sprite *canvas;
};



#endif