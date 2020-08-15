#include "EraseHighscoreState.h"
#include "bitmaps/spacerocks_gameover.hpp"
#include <Input/Input.h>
#include "SpaceRocks.h"
#include "Highscore/Highscore.h"
#include "bitmaps/spacerocks_backdrop.hpp"

SpaceRocks::EraseHighscoreState *SpaceRocks::EraseHighscoreState::instance = nullptr;

SpaceRocks::EraseHighscoreState::EraseHighscoreState(Sprite *sprite) : State(sprite)
{
	instance = this;
	blinkState = 0;
	blinkTime = 0;
}
void SpaceRocks::EraseHighscoreState::start(SpaceRocks& _game)
{
	game = &_game;
	Input::getInstance()->setBtnPressCallback(BTN_B, [](){
		instance->game->openHighscores();

	});
	Input::getInstance()->setBtnPressCallback(BTN_A, [](){
		Highscore.clear();
		instance->game->returnToTitle();

	});
}
void SpaceRocks::EraseHighscoreState::stop()
{
	Input::getInstance()->removeBtnPressCallback(BTN_A);
	Input::getInstance()->removeBtnPressCallback(BTN_B);
}
void SpaceRocks::EraseHighscoreState::draw()
{
	display->drawIcon(spacerocks_backdrop, 0, 0, 128, 128);
	display->setTextFont(2);
	display->setTextColor(TFT_WHITE);
	display->setCursor(4, 5);
	display->printCenter("ARE YOU SURE?");
	display->setCursor(4, 25);
	display->printCenter("This cannot");
	display->setCursor(4, 41);
	display->printCenter("be reverted!");

	display->setCursor(10, 102);
	display->print("B:");
	display->setCursor(48, 102);
	display->print("Cancel");

	display->setCursor(10, 81);
	display->print("A:");

	if (blinkState){
		display->drawRect((display->width() - 60)/2 + 5, 80, 30*2, 9*2, TFT_RED);
		display->setTextColor(TFT_RED);
		display->setCursor(46, 81);
		display->print("DELETE");
	}
	else {
		display->fillRect((display->width() - 60)/2 + 5, 80, 30*2, 9*2, TFT_RED);
		display->setTextColor(TFT_WHITE);
		display->setCursor(46, 81);
		display->print("DELETE");
	}
}

void SpaceRocks::EraseHighscoreState::update(uint _time, SpaceRocks& game)
{
	blinkTime+=_time;
	if(blinkTime >= 350000)
	{
		blinkTime = 0;
		blinkState = !blinkState;
	}
}
