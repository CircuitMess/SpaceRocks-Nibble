#include "TitleState.h"
#include "Ship/DemoInputComponent.h"
#include "bitmaps/backdrop.hpp"
#include "bitmaps/title.hpp"
#include "bitmaps/arrowLeft.hpp"
#include "bitmaps/arrowRight.hpp"
#include <Input/Input.h>
#include "SpaceRocks.h"
const char *TitleState::titleMenu[3] = {"Start", "Hiscores", "Quit"};
TitleState* TitleState::instance = nullptr;
TitleState::TitleState(Sprite* sprite) : State(sprite)
{
	instance = this;
	ship = new Ship(this, new DemoInputComponent(), display);
	ship->velocityX = 1;
	ship->shipY = 85;
	ship->invincibility = 0;
	titleCursor = 0;
	blinkState = 0;
	blinkMicros = 0;
}

TitleState::~TitleState()
{
	delete ship;
}

void TitleState::start(SpaceRocks& _game)
{
	game = &_game;
	Input::getInstance()->setBtnPressCallback(BTN_LEFT, [](){
		if(instance->titleCursor > 0){
			instance->titleCursor--;
		}
	});
	Input::getInstance()->setBtnPressCallback(BTN_RIGHT, [](){
		if(instance->titleCursor < 2){
			instance->titleCursor++;
		}
	});
	Input::getInstance()->setBtnPressCallback(BTN_A, [](){
		switch (instance->titleCursor)
		{
			case 0:
				instance->game->newGame();
				break;
			
			case 1:
				instance->game->openHighscores();
				break;
			case 2:
				instance->game->pop();
				break;
		}
	});
}
void TitleState::update(uint _time, SpaceRocks& game)
{
	//begin homescreen
	
	// if (millis()-shootMillis >= 150 && (bulletCount < 8)) {
	// 	shootMillis = millis();
	// 	bullet[bulletCount][1] = (short)(round)(pgm_read_float(&heading[HDG][0]) * 20);
	// 	bullet[bulletCount][3] = (short)(round)(pgm_read_float(&heading[HDG][1]) * 20);
	// 	bullet[bulletCount][0] = shipX1;
	// 	bullet[bulletCount][2] = shipY1;
	// 	bullet[bulletCount][4] = 100;
	// 	bulletCount = bulletCount + 1;
	// }
	// if(millis() - blinkMillis > 200)
	// {
	// 	blinkMillis = millis();
	// 	blinkState = !blinkState;
	// }
	// trajectory();
	blinkMicros+=_time;
	if(blinkMicros > 200000)
	{
		blinkState = !blinkState;
		blinkMicros = 0;
	}
	ship->update(_time);
}
void TitleState::draw()
{
	display->drawIcon(backdrop, 0,0,128,128);
	display->drawIcon(title, 5,5,118,60, 1, TFT_WHITE);
	ship->draw();

	display->setCursor(118, 110);
	display->setTextFont(2);
	display->setTextSize(1);
	display->setTextColor(TFT_WHITE);
	display->drawRect(18, 110, 92, 18, TFT_WHITE);
	display->drawRect(17, 109, 94, 20, TFT_WHITE);

	display->setCursor(18*2, 110);
	display->printCenter(titleMenu[titleCursor]);
	if(blinkState)
	{
		if (titleCursor == 0)
		{
			display->drawIcon(arrowLeft, 4, 112, 4, 7, 2, TFT_BLACK);
			display->drawIcon(arrowRight, 118, 112, 4, 7, 2, TFT_BLACK);
		}
		else if (titleCursor == 2)
		{
			display->drawIcon(arrowLeft, 2, 112, 4, 7, 2, TFT_BLACK);
			display->drawIcon(arrowRight, 116, 112, 4, 7, 2, TFT_BLACK);
		}
		else
		{
			display->drawIcon(arrowLeft, 2, 112, 4, 7, 2, TFT_BLACK);
			display->drawIcon(arrowRight, 118, 112, 4, 7, 2, TFT_BLACK);
		}
	}
	else
	{
		display->drawIcon(arrowLeft, 4, 112, 4, 7, 2, TFT_BLACK);
		display->drawIcon(arrowRight, 116, 112, 4, 7, 2, TFT_BLACK);
	}
}
