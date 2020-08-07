#include "PlayerInputComponent.h"
#include "Input/Input.h"
#include "../../Nibble.hpp"
#include "Ship.h"
#include <Audio/Piezo.h>
constexpr float SpaceRocks::PlayerInputComponent::headingTable[24][2];
SpaceRocks::PlayerInputComponent* SpaceRocks::PlayerInputComponent::instance = nullptr;
SpaceRocks::PlayerInputComponent::PlayerInputComponent()
{
	instance = this;
}
void SpaceRocks::PlayerInputComponent::start(Ship& _ship)
{
	ship = &_ship;
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_LEFT, 10, [](uint){
		instance->ship->heading--;
	});
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_RIGHT, 10, [](uint){
		instance->ship->heading++;
	});
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_UP, 10, [](uint){
		instance->ship->velocityX += headingTable[instance->ship->heading][0];
		instance->ship->velocityY += headingTable[instance->ship->heading][1];
	});
	Input::getInstance()->setBtnPressCallback(BTN_A, [](){
		Piezo.tone(400, 50);
		instance->ship->shoot();
	});
}
void SpaceRocks::PlayerInputComponent::update(uint _time, Ship& ship){}

void SpaceRocks::PlayerInputComponent::stop()
{
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_LEFT, 0, nullptr);
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_RIGHT, 0, nullptr);
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_UP, 0, nullptr);
	Input::getInstance()->removeBtnPressCallback(BTN_UP);
}