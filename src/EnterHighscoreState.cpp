#include "EnterHighscoreState.h"
#include "bitmaps/spacerocks_gameover.hpp"
#include <Input/Input.h>
#include "SpaceRocks.h"
#include "Highscore/Highscore.h"
#include "bitmaps/spacerocks_backdrop.hpp"

SpaceRocks::EnterHighscoreState *SpaceRocks::EnterHighscoreState::instance = nullptr;

SpaceRocks::EnterHighscoreState::EnterHighscoreState(Sprite *sprite) : State(sprite)
{
	instance = this;
	charCursor = 0;
	cursorTime = 0;
	hiscoreTime = 0;
	cursorBlink = 1;
	hiscoreBlink = 0;
	name = new char[4];
	strncpy(name, "AAA\0", sizeof(name));
}
void SpaceRocks::EnterHighscoreState::start(SpaceRocks& _game)
{
	game = &_game;
	Input::getInstance()->setBtnPressCallback(BTN_UP,[](){
		instance->cursorBlink = 1;
		instance->cursorTime = millis();
		instance->name[instance->charCursor]++;
		// A-Z 0-9 :-? !-/ ' '
		if (instance->name[instance->charCursor] == '0') instance->name[instance->charCursor] = ' ';
		if (instance->name[instance->charCursor] == '!') instance->name[instance->charCursor] = 'A';
		if (instance->name[instance->charCursor] == '[') instance->name[instance->charCursor] = '0';
		if (instance->name[instance->charCursor] == '@') instance->name[instance->charCursor] = '!';
	});
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_UP, 200, [](uint){
		instance->cursorBlink = 1;
		instance->cursorTime = millis();
		instance->name[instance->charCursor]++;
		// A-Z 0-9 :-? !-/ ' '
		if (instance->name[instance->charCursor] == '0') instance->name[instance->charCursor] = ' ';
		if (instance->name[instance->charCursor] == '!') instance->name[instance->charCursor] = 'A';
		if (instance->name[instance->charCursor] == '[') instance->name[instance->charCursor] = '0';
		if (instance->name[instance->charCursor] == '@') instance->name[instance->charCursor] = '!';
	});
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_DOWN, 200, [](uint){
		instance->cursorBlink = 1;
		instance->cursorTime = millis();
		instance->name[instance->charCursor]--;
		if (instance->name[instance->charCursor] == ' ') instance->name[instance->charCursor] = '?';
		if (instance->name[instance->charCursor] == '/') instance->name[instance->charCursor] = 'Z';
		if (instance->name[instance->charCursor] == 31)  instance->name[instance->charCursor] = '/';
		if (instance->name[instance->charCursor] == '@') instance->name[instance->charCursor] = ' ';
	});
	Input::getInstance()->setBtnPressCallback(BTN_DOWN, [](){
		instance->cursorBlink = 1;
		instance->cursorTime = millis();
		instance->name[instance->charCursor]--;
		if (instance->name[instance->charCursor] == ' ') instance->name[instance->charCursor] = '?';
		if (instance->name[instance->charCursor] == '/') instance->name[instance->charCursor] = 'Z';
		if (instance->name[instance->charCursor] == 31)  instance->name[instance->charCursor] = '/';
		if (instance->name[instance->charCursor] == '@') instance->name[instance->charCursor] = ' ';
	});
	Input::getInstance()->setBtnPressCallback(BTN_LEFT, [](){
		if(instance->charCursor > 0){
			instance->charCursor--;
			instance->cursorBlink = 1;
			instance->cursorTime = millis();
		}
	});
	Input::getInstance()->setBtnPressCallback(BTN_RIGHT, [](){
		if(instance->charCursor < 2){
			instance->charCursor++;
			instance->cursorBlink = 1;
			instance->cursorTime = millis();
		}
	});
	Input::getInstance()->setBtnPressCallback(BTN_A, [](){
		instance->charCursor++;
		instance->cursorBlink = 1;
		instance->cursorTime = millis();
	});
}
void SpaceRocks::EnterHighscoreState::stop()
{
	Input::getInstance()->removeBtnPressCallback(BTN_A);
	Input::getInstance()->removeBtnPressCallback(BTN_RIGHT);
	Input::getInstance()->removeBtnPressCallback(BTN_LEFT);
	Input::getInstance()->removeBtnPressCallback(BTN_DOWN);
	Input::getInstance()->removeBtnPressCallback(BTN_UP);
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_UP, 0, nullptr);
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_DOWN, 0, nullptr);
}
void SpaceRocks::EnterHighscoreState::draw()
{
	display->drawIcon(spacerocks_backdrop, 0, 0, 128, 128);
	display->setCursor(16, 8);
	display->setTextFont(2);
	display->setTextColor(TFT_WHITE);
	display->setTextSize(1);
	display->printCenter("ENTER NAME");
	display->setCursor(20, 80);
	
	if(hiscoreBlink && game->score > Highscore.get(0).score){
		display->printCenter("NEW HIGH!");
	}
	else{
		display->printf("SCORE: %04d", game->score);
	}

	display->setCursor(40, 40);
	display->print(name[0]);
	display->setCursor(55, 40);
	display->print(name[1]);
	display->setCursor(70, 40);
	display->print(name[2]);
	// display->drawRect(30, 38, 100, 20, TFT_WHITE);
	if(cursorBlink){
		display->drawFastHLine(38 + 15*charCursor, 56, 12, TFT_WHITE);
	}
}

void SpaceRocks::EnterHighscoreState::update(uint _time, SpaceRocks& game)
{
	hiscoreTime+=_time;
	if(hiscoreTime >= 1000000)
	{
		hiscoreTime = 0;
		hiscoreBlink = !hiscoreBlink;
	}
	cursorTime+=_time;
	if(cursorTime >= 350000)
	{
		cursorTime = 0;
		cursorBlink = !cursorBlink;
	}
	if(charCursor >= 3)
	{
		Score newScore;
		strcpy(newScore.name, name);
		newScore.score = game.score;
		Highscore.add(newScore);
		game.openHighscores();
	}
}
