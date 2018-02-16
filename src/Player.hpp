//
//  Player.hpp
//  myAstralWars
//
//  Created by Christopher Kang on 2/12/18.
//
#pragma once

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>

#include "ofMain.h"

class Player {
public:
    ofPoint pos;
    float width, height, speed;
    int lives;
    
    bool is_left_pressed, is_right_pressed, is_down_pressed, is_up_pressed;
    
    void setup(ofImage * _img, ofPoint _pos);
    void update();
    void draw();
    void shoot();
    
    void calculate_movement();
    
    bool check_canshoot();
    
    ofImage * img;
};


#endif /* Player_hpp */
