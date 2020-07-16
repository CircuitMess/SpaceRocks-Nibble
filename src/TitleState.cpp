#include "TitleState.h"
#include "Ship/PlayerInputComponent.h"
#include "bitmaps/backdrop.hpp"
#include "bitmaps/title.hpp"
TitleState::TitleState()
{
	ship = new Ship(game, new PlayerInputComponent(), display);
	ship->velocityX = 1;
	ship->shipY = 49;
	ship->invincibility = 0;
}

TitleState::~TitleState()
{
	delete ship;
}

void TitleState::update(uint _time)
{
	ship->update(_time);
}
void TitleState::draw()
{
	display->drawIcon(backdrop, 0,0,128,128);
	display->drawIcon(title, 5,5,118,60);
	ship->draw();
}
