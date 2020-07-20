#include "SpaceRocks.h"
#include "bitmaps/icon.hpp"
#include "TitleState.h"
#include "GameState.h"
#include "GameOverState.h"
#include "PauseState.h"

GameInfo Game::info = {"SpaceRocks", "Shoot the asteroids and survive!", icon};

SpaceRocks::SpaceRocks(Display& display) : Game(display), display(&display), canvas(display.getBaseSprite()), score(0)
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
void SpaceRocks::gameOver()
{
	delete state;
	state = new GameOverState(canvas);
	state->start(*this);
}
void SpaceRocks::enterHighscore()
{

}
void SpaceRocks::pauseGame()
{
	state->stop();
	pausedGameState = state;
	state = new PauseState(canvas);
	state->start(*this);
}
void SpaceRocks::resumeGame()
{
	delete state;
	state = pausedGameState;
	state->start(*this);
}
void SpaceRocks::quitGame()
{
	delete state;
	state = new TitleState(canvas);
	state->start(*this);
}
void SpaceRocks::openHighscores()
{

}