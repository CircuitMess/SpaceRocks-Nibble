#ifndef SPACEROCKS_SHIP_H
#define SPACEROCKS_SHIP_H
#include <Display/Sprite.h>
#include "InputComponent.h"
#include "../State.hpp"

#define shipX0  shipX + (int8_t)(pgm_read_byte(&shipTbl[0][heading]))
#define shipY0  shipY + (int8_t)(pgm_read_byte(&shipTbl[1][heading]))
#define shipX1  shipX + (int8_t)(pgm_read_byte(&shipTbl[2][heading]))
#define shipY1  shipY + (int8_t)(pgm_read_byte(&shipTbl[3][heading]))
#define shipX2  shipX + (int8_t)(pgm_read_byte(&shipTbl[4][heading]))
#define shipY2  shipY + (int8_t)(pgm_read_byte(&shipTbl[5][heading]))

class Ship
{
public:
	Ship(State *game, InputComponent *input, Sprite *canvas);
	~Ship();
	void update(uint _time);
	void draw();
	float shipX;
	float shipY;
	float velocityX;
	float velocityY;
	int16_t heading;
	bool invincibility;
	uint invincibility_time = 0;
private:
	InputComponent* input;
	Sprite* canvas;
	static constexpr uint16_t invincibility_duration = 2000000;
	State* game;
	static constexpr int8_t shipTbl[6][24] PROGMEM = {
		//HDG
		//  0   1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21  22  23
		{  +3, +3, +2, +1, -1, -2, -3, -2, -1, +1, +2, +3, +3, -3, -2, -1, +1, +2, +3, +2, +1, -1, -2, -3,},
		{  +3, +3, +3, +3, +3, +3, +3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, +3, +3, +3, +3, +3, +3,},
		{  +0, +2, +3, +3, +3, +4, +4, +4, +3, +3, +3, +2, +0, -2, -3, -3, -3, -4, -4, -4, -3, -3, -3, -2,},
		{  -4, -4, -3, -3, -3, -2, +0, +2, +3, +3, +3, +4, +4, +4, +3, +3, +3, +2, +0, -2, -3, -3, -3, -4,},
		{  -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, -3, +3, +3, +3, +3, +3, +3, +3, +3, +3, +3, +3,},
		{  +3, +2, +1, -1, -2, -3, -3, +3, +2, +1, -1, -2, -3, -2, -1, +1, +2, +3, -3, -3, -2, -1, +1, +2,},
	};
};

#endif