#ifndef SPACEROCKS_H
#define SPACEROCKS_H

#include <Arduino.h>
#include <CircuitOS.h>
#include <Input/Input.h>
#include <Update/UpdateManager.h>
#include <gpio.h>
#include <avr/pgmspace.h>
#include <Support/Context.h>
#include "../ByteBoy.hpp"
#include <UI/Image.h>
#include <Display/Sprite.h>
#include "State.hpp"

class SpaceRocks : public Game, public UpdateListener
{
public:
	SpaceRocks(Display& Display);
	void draw() override;
	void start() override;
	void update(uint _time) override;
	void stop() override;

	void newGame();
	void openHighscores();
private:
	State *state;
	Display *display;
	Sprite *canvas;
};



#endif