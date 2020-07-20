#ifndef GAME_INFO
#define GAME_INFO
#include <Arduino.h>
#include <Display/Display.h>
#include "src/bitmaps/icon.hpp"
#include "src/SpaceRocks.h"
class Context;
struct GameInfo {
	const char* title;
	const char* description;
	const uint16_t* icon;
	Context* (*launch)(Display& display);
};
#endif
const GameInfo SnakeInfo {
		"SpaceRocks",
		"Shoot the asteroids to survive!",
		icon,
		[](Display& display) -> Context* { return new SpaceRocks(display); }
};