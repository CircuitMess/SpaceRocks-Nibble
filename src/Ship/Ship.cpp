#include "Ship.h"

constexpr int8_t SpaceRocks::Ship::shipTbl[6][24];
constexpr uint SpaceRocks::Ship::invincibility_duration;
constexpr float SpaceRocks::Ship::headingTable[24][2];

SpaceRocks::Ship::Ship(State *game, InputComponent *_input, Sprite *canvas) :
		game(game), input(_input), canvas(canvas)
{
	heading = 0;
	shipX = 0;
	shipY = 0;
	velocityX = 0;
	velocityY = 0;
	invincibility = 0;
	invincibility_time = 0;
}
void SpaceRocks::Ship::start()
{
	if(input != nullptr) input->start(*this);
}
void SpaceRocks::Ship::stop()
{
	if(input != nullptr) input->stop();
}
SpaceRocks::Ship::~Ship()
{
	delete input;
}
void SpaceRocks::Ship::update(uint _time)
{
	if(input != nullptr) input->update(_time, *this);
	bullets.update(canvas);

	//invincibility handling
	if(invincibility){
		invincibility_time+=_time;
		if(invincibility_time >= invincibility_duration){
			invincibility = 0;
			invincibility_time = 0;
		}
	}

	//rotation handling
	if (heading > 23){
		heading -= 24;
	}
	if (heading < 0){
		heading += 24;
	}

	//velocity limiting and handling

	//stopping gradually
	if (velocityY > 0)velocityY -= 0.01;
	if (velocityY < 0)velocityY += 0.01;

	if (velocityX > 0)velocityX -= 0.01;
	if (velocityX < 0)velocityX += 0.01;

	//stop completely if going slow enough
	if (velocityX <= 0.01 && velocityX >= -0.01) velocityX = 0;
	if (velocityY <= 0.01 && velocityY >= -0.01) velocityY = 0;

	//max speed reached?
	if (velocityY > 2)velocityY = 2;
	if (velocityY < -2)velocityY = -2;

	if (velocityX > 2)velocityX = 2;
	if (velocityX < -2)velocityX = -2;

	shipX += velocityX;
	shipY += velocityY;

	//out-of-bounds handling
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
}
void SpaceRocks::Ship::draw()
{
	
	if(!invincibility || (invincibility && invincibility_time%250000 >= 100000))
	{
		canvas->fillTriangle(shipX0*2, shipY0*2, shipX1*2, shipY1*2, shipX2*2, shipY2*2, TFT_LIGHTGREY);
		canvas->drawTriangle(shipX0*2, shipY0*2, shipX1*2, shipY1*2, shipX2*2, shipY2*2, TFT_LIGHTGREY);
		//drawTriangle(shipX0*2, shipY0*2, shipX1*2, shipY1*2, shipX2*2, shipY2*2, TFT_DARKGREY);
		canvas->fillTriangle(shipX0, shipY0, shipX1, shipY1, shipX2, shipY2, TFT_NAVY);

		//"hitbox" drawing
		// canvas->drawFastHLine(shipX - 4, shipY, 8, TFT_RED);
		// canvas->drawFastVLine(shipX, shipY - 4, 8, TFT_RED);
		
	}
	bullets.draw(canvas);
}
void SpaceRocks::Ship::shoot()
{
	bullets.create(shipX1, shipY1, headingTable[heading][0]*20, headingTable[heading][1]*20, 30);
}
void SpaceRocks::Ship::destroyed()
{
	invincibility = 1;
	invincibility_time = 0;
	shipX = canvas->width()/2;
	shipY = canvas->height()/2;
	velocityX = 0;
	velocityY = 0;
}
SpaceRocks::ShipCoordinates SpaceRocks::Ship::getCoordinates()
{
	ShipCoordinates coords;
	coords.x1 = shipX0;
	coords.y1 = shipY0;
	coords.x2 = shipX1;
	coords.y2 = shipY1;
	coords.x3 = shipX2;
	coords.y3 = shipX2;
	return coords;
}