//
//  Enemy.hpp
//  myAstralWars
//
//  Created by Christopher Kang on 2/12/18.
//
#pragma once

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>

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
    
    ofImage * img;
    int backnforth;
    float deltaX;
};

#endif /* Enemy_hpp */
