#include "SpaceRocks.h"
#include "bitmaps/icon.hpp"
#include "TitleState.h"

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
	// life = 3;
	// resetSim();
	// resetField();
	// // addOscillator(shoot);
	// addTrack(collide);
	// // addTrack(hit);
	// simState = ProgState::Simulation;
	// titleMusic->stop();
	// removeTrack(titleMusic);
	// addTrack(bgmusic);
	// if(mp.mediaVolume == 0)
	// 	bgmusic->setVolume(0);
	// else
	// 	bgmusic->setVolume(map(mp.mediaVolume, 0, 14, 100, 300));
	// bgmusic->setRepeat(1);
	// bgmusic->rewind();
	// bgmusic->play();
}
void SpaceRocks::openHighscores()
{

}
