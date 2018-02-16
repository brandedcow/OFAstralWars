#pragma once
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "ofMain.h"

class Enemy {
public:
	ofPoint pos;
	float speed;
	float amplitude;
	float width;

	float start_shoot;
	float shoot_interval;

	void setup(float max_enemy_amplitude, float max_enemy_shoot_interval, ofImage * enemy_image);
	void update();
	void draw();
	bool time_to_shoot();

	ofImage* img;

	// Default constructor
	//Enemy(ofImage img) { this->img = &img; }
};
#endif