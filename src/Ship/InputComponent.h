#ifndef SPACEROCKS_SHIP_INPUT_H
#define SPACEROCKS_SHIP_INPUT_H

class Ship;
class InputComponent
{
public:
	virtual ~InputComponent() {}
	virtual void start(Ship& ship) = 0;
	virtual void update(uint _time, Ship& ship) = 0;
};

#endif