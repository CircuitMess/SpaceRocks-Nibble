#include "DemoInputComponent.h"
#include "Input/Input.h"
#include "../../ByteBoy.hpp"
#include "Ship.h"

void DemoInputComponent::start(Ship& ship){}
void DemoInputComponent::update(uint _time, Ship& ship)
{
	rotateTimer+=_time;
	if(rotateTimer >= 300000){
		bool turn = (random(0, 2) == 1);
		if (turn){
			ship.heading++;
		}else{
			ship.heading--;
		}
	}
}
