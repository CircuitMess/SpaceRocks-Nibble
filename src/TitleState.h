#ifndef SPACEROCKS_TITLESTATE_H
#define SPACEROCKS_TITLESTATE_H

#include "State.hpp"
#include "Ship/Ship.h"

class TitleState : public State
{
public:
	TitleState();
	~TitleState();
	void update(uint _time) override;
	void draw() override;
	
private:
	Ship* ship;
};


#endif