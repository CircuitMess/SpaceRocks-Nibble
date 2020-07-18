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
	life = 3;
	score = 0;
	level = 0;
	asteroidTime = 0;
	dead = 0;
	deadTime = 0;
	
	asteroids.create(float(random(10, 119)), float(random(10, 119)), random(-10, 10) * 0.05, random(-10, 10) * 0.05, AsteroidType::asteroid, random(0,3));
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
	//death animation handling
	if(dead)
	{
		deadTime+=_time;
		if(deadTime / 200000 >= 7)
		{
			gameOver();
		}
		return;
	}

	ship->update(_time);
	asteroids.update(display);

	//collision check
	for(int i = 0; i < asteroids.POOL_SIZE; i++)
	{
		//continue if blank asteroid or ship is invincible
		if(!asteroids.asteroids[i].inUse() || ship->invincibility) continue;

		//check overlap - TODO: actual triangle-rectangle intersection
		if(ship->shipX > asteroids.asteroids[i].x && ship->shipX < asteroids.asteroids[i].x + asteroids.asteroids[i].getWidth() && 
		ship->shipY > asteroids.asteroids[i].y && ship->shipY < asteroids.asteroids[i].y + asteroids.asteroids[i].getWidth())
		{
			if(life > 0)
			{
				ship->destroyed();
				life--;
			}
			else
			{
				dead = 1;
				deadTime = 0;
			}
		}
	}
}
void GameState::draw()
{
	display->drawIcon(backdrop, 0,0,128,128);
	if(dead)
	{
		uint8_t passes = (deadTime / 200000) * 2;
		display->drawLine(ship->shipX, ship->shipY + passes, ship->shipX, ship->shipY + passes + 3, TFT_WHITE);
		display->drawLine(ship->shipX, ship->shipY - passes, ship->shipX, ship->shipY - passes - 3, TFT_WHITE);
		display->drawLine(ship->shipX + passes, ship->shipY, ship->shipX + passes + 3, ship->shipY, TFT_WHITE);
		display->drawLine(ship->shipX - passes, ship->shipY, ship->shipX - passes - 3, ship->shipY, TFT_WHITE);
		display->drawLine(ship->shipX + passes, ship->shipY + passes, ship->shipX + passes + 2, ship->shipY + passes + 2, TFT_WHITE);
		display->drawLine(ship->shipX - passes, ship->shipY - passes, ship->shipX - passes - 2, ship->shipY - passes - 2, TFT_WHITE);
		display->drawLine(ship->shipX + passes, ship->shipY - passes, ship->shipX + passes + 2, ship->shipY - passes - 2, TFT_WHITE);
		display->drawLine(ship->shipX - passes, ship->shipY + passes, ship->shipX - passes - 2, ship->shipY + passes + 2, TFT_WHITE);
	}
	asteroids.draw(display);
	ship->draw();
}
void GameState::gameOver()
{

}