#include "SpaceRocks.h"
#include "bitmaps/icon.hpp"
#include "TitleState.h"
#include "GameState.h"

GameInfo Game::info = {"SpaceRocks", "Shoot the asteroids and survive!", icon};

SpaceRocks::SpaceRocks(Display& display) : Game(display), display(&display), canvas(display.getBaseSprite())
{
	randomSeed(micros()*millis());
	state = new TitleState(canvas);
	state->start(*this);
}

void SpaceRocks::draw()
{
	state->draw();
}
void SpaceRocks::update(uint _time)
{
	state->update(_time, *this);
	draw();
	display->commit();
}
void SpaceRocks::start()
{
	UpdateManager::addListener(this);
}
void SpaceRocks::stop()
{
	delete state;
}
void SpaceRocks::newGame()
{
	delete state;
	state = new GameState(canvas);
	state->start(*this);
}
void SpaceRocks::openHighscores()
{

}
void SpaceRocks::pauseGame()
{

}
