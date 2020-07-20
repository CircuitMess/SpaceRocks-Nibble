#include "GameOverState.h"
#include "bitmaps/gameover.hpp"
#include <Input/Input.h>
#include "SpaceRocks.h"

GameOverState *GameOverState::instance = nullptr;

GameOverState::GameOverState(Sprite* sprite) : State(sprite)
{
	instance = this;
	linesDrawn = 0;
}
void GameOverState::start(SpaceRocks& _game)
{
	game = &_game;
	
}
GameOverState::~GameOverState()
{
	Input::getInstance()->removeBtnPressCallback(BTN_A);
	Input::getInstance()->removeBtnPressCallback(BTN_B);
}
void GameOverState::draw()
{
	if(linesDrawn < 32)
	{
		for (int i = 0; i < linesDrawn*4; i+=4)
		{
			display->drawFastHLine(0, i, display->width(), TFT_DARKGREY);
			display->drawFastHLine(0, i+1, display->width(), TFT_DARKGREY);
		}
	}
	else
	{
		// display->drawMonochromeIcon(gameover, 11, 16, 107, 98, 1, TFT_DARKGREY);
		// display->drawMonochromeIcon(gameover, 9, 14, 107, 98, 1, TFT_BLACK);
	}
}
void GameOverState::drawBitmap(int16_t x, int16_t y, const byte *bitmap, uint16_t color, uint8_t scale) {
	uint16_t w = *(bitmap++);
	uint16_t h = *(bitmap++);
	display->drawMonochromeIcon(bitmap, x, y, w, h, scale, color);
}
void GameOverState::update(uint _time, SpaceRocks& game)
{
	if(linesDrawn < 32){
		linesDrawn++;
		if(linesDrawn >= 32){
			Input::getInstance()->setBtnPressCallback(BTN_A, [](){
				instance->game->quitGame();
			});
			Input::getInstance()->setBtnPressCallback(BTN_B, [](){
				instance->game->quitGame();
			});
		}
	}
	
}
