#include "PlayerInputComponent.h"
#include "Input/Input.h"
#include "../../ByteBoy.hpp"
#include "Ship.h"
constexpr float PlayerInputComponent::headingTable[24][2];
PlayerInputComponent* PlayerInputComponent::instance = nullptr;
PlayerInputComponent::PlayerInputComponent()
{
	instance = this;
}
void PlayerInputComponent::start(Ship& _ship)
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
		instance->ship->shoot();
	});
}
void PlayerInputComponent::update(uint _time, Ship& ship){}

void PlayerInputComponent::stop()
{
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_LEFT, 0, nullptr);
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_RIGHT, 0, nullptr);
	Input::getInstance()->setButtonHeldRepeatCallback(BTN_UP, 0, nullptr);
	Input::getInstance()->removeBtnPressCallback(BTN_UP);
}