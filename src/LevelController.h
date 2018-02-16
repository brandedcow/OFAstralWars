#pragma once
#ifndef LEVELCONTROLLER_HPP
#define LEVELCONTROLLER_HPP
#include "ofMain.h"

class LevelController {
public:
	float start_time;
	float interval_time;

	void setup(float e);
	bool should_spawn();
};
#endif