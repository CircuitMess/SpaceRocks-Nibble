#include "SpaceRocks.h"
#include "State.hpp"
#include "TitleState.h"
#include "GameState.h"
#include "GameOverState.h"
#include "PauseState.h"
#include "EnterHighscoreState.h"
#include "Highscore/Highscore.h"
#include "ShowHighscoreState.h"
#include "EraseHighscoreState.h"

SpaceRocks::SpaceRocks::SpaceRocks(Display& display) : Context(display), display(&display), canvas(display.getBaseSprite()), score(0)
{
	randomSeed(micros()*millis());
	state = new TitleState(canvas);
}

void SpaceRocks::SpaceRocks::draw()
{
	state->draw();
}
void SpaceRocks::SpaceRocks::loop(uint _time)
{
	state->update(_time, *this);
	draw();
	display->commit();
}
void SpaceRocks::SpaceRocks::start()
{
	runningContext = this;
	Highscore.begin();
	state->start(*this);
	LoopManager::addListener(this);
}
void SpaceRocks::SpaceRocks::stop()
{
	state->stop();
	LoopManager::removeListener(this);
}
void SpaceRocks::SpaceRocks::pack()
{
	state->stop();
	delete state;

	if(pausedGameState != nullptr){
		pausedGameState->stop();
		delete pausedGameState;
	}

	exitingGame = true;
}
void SpaceRocks::SpaceRocks::newGame()
{
	state->stop();
	delete state;
	state = new GameState(canvas);
	state->start(*this);
}
void SpaceRocks::SpaceRocks::gameOver()
{
	state->stop();
	delete state;
	state = new GameOverState(canvas);
	state->start(*this);
}
void SpaceRocks::SpaceRocks::enterHighscore()
{
	state->stop();
	delete state;
	state = new EnterHighscoreState(canvas);
	state->start(*this);
}
void SpaceRocks::SpaceRocks::pauseGame()
{
	state->stop();
	pausedGameState = state;
	state = new PauseState(canvas);
	state->start(*this);
}
void SpaceRocks::SpaceRocks::resumeGame()
{
	state->stop();
	delete state;
	state = pausedGameState;
	pausedGameState = nullptr;
	state->start(*this);
}
void SpaceRocks::SpaceRocks::returnToTitle()
{
	if(pausedGameState != nullptr){
		delete pausedGameState;
		pausedGameState = nullptr;
	}

	state->stop();
	delete state;
	state = new TitleState(canvas);
	state->start(*this);
}
void SpaceRocks::SpaceRocks::openHighscores()
{
	state->stop();
	delete state;
	state = new ShowHighscoreState(canvas);
	state->start(*this);
}
void SpaceRocks::SpaceRocks::deleteHighscores()
{
	state->stop();
	delete state;
	state = new EraseHighscoreState(canvas);
	state->start(*this);
}