#include "Ship.h"

constexpr int8_t Ship::shipTbl[6][24];
constexpr uint16_t Ship::invincibility_duration;
constexpr float Ship::headingTable[24][2];

Ship::Ship(State *game, InputComponent *_input, Sprite *canvas) : game(game), input(_input), canvas(canvas)
{
	heading = 0;
	shipX = 65;
	shipY = 10;
	velocityX = 0;
	velocityY = 0;
	invincibility = 0;
	input->start(*this);
}
Ship::~Ship()
{
	delete input;
}
void Ship::update(uint _time)
{
	if(invincibility){
		invincibility_time+=_time;
		if(invincibility_time >= invincibility_duration){
			invincibility = 0;
			invincibility_time = 0;
		}
	}
	input->update(_time, *this);

	if (heading > 23){
		heading -= 24;
	}
	if (heading < 0){
		heading += 24;
	}
	shipX += velocityX;
	shipY += velocityY;
	if (shipX < 5){
		shipX = canvas->width() - 5;
	}
	if (shipX > canvas->width() - 5){
		shipX = 5;
	}
	if (shipY < 4){
		shipY = canvas->height() - 4;
	}
	if (shipY > canvas->height() - 4){
		shipY = 4;
	}
	bullets.update(canvas);
}
void Ship::draw()
{
	if(!invincibility || (invincibility && invincibility_time%250 >= 100))
	{
		canvas->fillTriangle(shipX0*2, shipY0*2, shipX1*2, shipY1*2, shipX2*2, shipY2*2, TFT_LIGHTGREY);
		canvas->drawTriangle(shipX0*2, shipY0*2, shipX1*2, shipY1*2, shipX2*2, shipY2*2, TFT_LIGHTGREY);
		//drawTriangle(shipX0*2, shipY0*2, shipX1*2, shipY1*2, shipX2*2, shipY2*2, TFT_DARKGREY);
		canvas->fillTriangle(shipX0, shipY0, shipX1, shipY1, shipX2, shipY2, TFT_NAVY);
	}
	bullets.draw(canvas);
}
void Ship::shoot()
{
	bullets.create(shipX1, shipY1, headingTable[heading][0]*20, headingTable[heading][1]*20, 40);
}