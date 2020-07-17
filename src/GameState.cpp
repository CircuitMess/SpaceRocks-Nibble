#include "GameState.h"
#include "Ship/PlayerInputComponent.h"
#include "bitmaps/backdrop.hpp"
#include <Input/Input.h>
#include "SpaceRocks.h"
const char *GameState::titleMenu[3] = {"Start", "Hiscores", "Quit"};
GameState* GameState::instance = nullptr;
GameState::GameState(Sprite* sprite) : State(sprite)
{
	instance = this;
	ship = new Ship(this, new PlayerInputComponent(), display);
	ship->shipX = display->width()/2;
	ship->shipY = display->height()/2;
	ship->invincibility = 0;
	life = 3;
	score = 0;
	level = 0;
	asteroidTime = 0;
}

GameState::~GameState()
{
	delete ship;
}

void GameState::start(SpaceRocks& _game)
{
	game = &_game;
	Input::getInstance()->setBtnPressCallback(BTN_B, [](){
		instance->game->pauseGame();
	});
}
void GameState::update(uint _time, SpaceRocks& game)
{
	ship->update(_time);
}
void GameState::draw()
{
	display->drawIcon(backdrop, 0,0,128,128);
	ship->draw();
}