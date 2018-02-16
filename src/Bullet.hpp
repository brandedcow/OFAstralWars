//
//  Bullet.hpp
//  myAstralWars
//
//  Created by Christopher Kang on 2/12/18.
//
#pragma once

#ifndef Bullet_hpp
#define Bullet_hpp

#include <stdio.h>

#include "ofMain.h"

class Bullet {
public:
    ofPoint pos;
    float speed;
    float width;
    bool from_player;
    
    void setup(bool f_p, ofPoint p, float s, ofImage * bullet_image);
    void update();
    void draw();
    
    ofImage * img;
};

#endif /* Bullet_hpp */
