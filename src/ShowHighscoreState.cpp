#include "ShowHighscoreState.h"
#include "bitmaps/spacerocks_gameover.hpp"
#include <Input/Input.h>
#include "SpaceRocks.h"
#include "Highscore/Highscore.h"
#include "bitmaps/spacerocks_backdrop.hpp"

SpaceRocks::ShowHighscoreState *SpaceRocks::ShowHighscoreState::instance = nullptr;

SpaceRocks::ShowHighscoreState::ShowHighscoreState(Sprite *sprite) : State(sprite)
{
	instance = this;
}
void SpaceRocks::ShowHighscoreState::start(SpaceRocks& _game)
{
	game = &_game;
	Input::getInstance()->setBtnPressCallback(BTN_UP, [](){
		instance->game->deleteHighscores();
	});
	Input::getInstance()->setBtnPressCallback(BTN_A, [](){
		instance->game->returnToTitle();
	});
	Input::getInstance()->setBtnPressCallback(BTN_B, [](){
		instance->game->returnToTitle();
	});
}
void SpaceRocks::ShowHighscoreState::stop()
{
	Input::getInstance()->removeBtnPressCallback(BTN_UP);
	Input::getInstance()->removeBtnPressCallback(BTN_A);
	Input::getInstance()->removeBtnPressCallback(BTN_B);
}
void SpaceRocks::ShowHighscoreState::draw()
{
	display->drawIcon(spacerocks_backdrop, 0, 0, 128, 128);
	display->setCursor(32, -2);
	display->setTextSize(1);
	display->setTextFont(2);
	display->setTextColor(TFT_WHITE);
	display->printCenter("HIGHSCORES");
	display->setCursor(3, 110);
	for (int i = 1; i < 6;i++)
	{
		display->setCursor(6, i * 20);
		if(i <= Highscore.count())
		{
			Serial.printf("%d.   %.3s    %04d\n", i, Highscore.get(i - 1).name, Highscore.get(i - 1).score);
			Serial.println();
			display->printf("%d.   %.3s    %04d", i, Highscore.get(i - 1).name, Highscore.get(i - 1).score);
		}
		else
		{
			display->printf("%d.    ---   ----", i);
		}
	}
	Serial.println("---------------");
	display->setCursor(2, 115);
	display->print("Press UP to erase");
}

void SpaceRocks::ShowHighscoreState::update(uint _time, SpaceRocks& game)
{
}
