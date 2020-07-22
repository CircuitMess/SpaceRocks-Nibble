#include "GameOverState.h"
#include "bitmaps/spacerocks_gameover.hpp"
#include <Input/Input.h>
#include "SpaceRocks.h"

SpaceRocks::GameOverState *SpaceRocks::GameOverState::instance = nullptr;

SpaceRocks::GameOverState::GameOverState(Sprite* sprite) : State(sprite)
{
	instance = this;
	linesDrawn = 0;
}
void SpaceRocks::GameOverState::start(SpaceRocks& _game)
{
	game = &_game;
	
}
SpaceRocks::GameOverState::~GameOverState()
{
	Input::getInstance()->removeBtnPressCallback(BTN_A);
	Input::getInstance()->removeBtnPressCallback(BTN_B);
}
void SpaceRocks::GameOverState::draw()
{
	if(linesDrawn < 32)
	{
		for (int i = 0; i <= linesDrawn*4; i+=4)
		{
			display->drawFastHLine(0, i, display->width(), TFT_DARKGREY);
			display->drawFastHLine(0, i+1, display->width(), TFT_DARKGREY);
		}
	}
	else
	{
		display->drawMonochromeIcon(spacerocks_gameover, 11, 16, 107, 98, 1, TFT_DARKGREY);
		display->drawMonochromeIcon(spacerocks_gameover, 9, 14, 107, 98, 1, TFT_BLACK);
	}
}
void SpaceRocks::GameOverState::drawBitmap(int16_t x, int16_t y, const byte *bitmap, uint16_t color, uint8_t scale) {
	uint16_t w = *(bitmap++);
	uint16_t h = *(bitmap++);
	display->drawMonochromeIcon(bitmap, x, y, w, h, scale, color);
}
void SpaceRocks::GameOverState::update(uint _time, SpaceRocks& game)
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
