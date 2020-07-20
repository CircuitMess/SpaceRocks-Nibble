#ifndef SPACEROCKS_SHIP_PLAYERINPUT_H
#define SPACEROCKS_SHIP_PLAYERINPUT_H
#include <Arduino.h>
#include "InputComponent.h"
#include <avr/pgmspace.h>

class PlayerInputComponent : public InputComponent
{
public:
	PlayerInputComponent();
	~PlayerInputComponent(){}
	void update(uint _time, Ship& ship) override;
	void start(Ship& ship) override;
	void stop() override;
private:
	Ship* ship;
	static PlayerInputComponent* instance;
	static constexpr float headingTable[24][2] PROGMEM = {
		{ +0.00, -0.20}, { +0.05, -0.19},
		{ +0.10, -0.17}, { +0.14, -0.14},
		{ +0.17, -0.10}, { +0.19, -0.05},
		{ +0.20, +0.00}, { +0.19, +0.05},
		{ +0.17, +0.10}, { +0.14, +0.14},
		{ +0.10, +0.17}, { +0.05, +0.19},
		{ +0.00, +0.20}, { -0.05, +0.19},
		{ -0.10, +0.17}, { -0.14, +0.14},
		{ -0.17, +0.10}, { -0.19, +0.05},
		{ -0.20, +0.00}, { -0.19, -0.05},
		{ -0.17, -0.10}, { -0.14, -0.14},
		{ -0.10, -0.17}, { -0.05, -0.19}
	};
};

#endif