#include "SpaceRocks.h"
#include "bitmaps/icon.hpp"
#include "TitleState.h"

GameInfo Game::info = {"SpaceRocks", "Shoot the asteroids and survive!", icon};

SpaceRocks::SpaceRocks(Display& display) : Game(display), display(&display), canvas(display.getBaseSprite())
{
	randomSeed(micros()*millis());
	state = new TitleState();
}

void SpaceRocks::draw()
{
	state->draw();
}
void SpaceRocks::update(uint _time)
{
	state->update(_time);
	draw();
	display->commit();
}
void SpaceRocks::start()
{

}
void SpaceRocks::stop()
{
	delete state;
}

