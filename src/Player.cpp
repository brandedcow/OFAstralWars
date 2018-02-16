//
//  Player.cpp
//  myAstralWars
//
//  Created by Christopher Kang on 2/12/18.
//

#include "Player.hpp"
#include "ofApp.h"

//--------------------------------------------------------------
void Player::setup(ofImage * _img, ofPoint _pos){
    img = _img;
    height = img->getHeight();
    width = img->getWidth();
    pos.set(_pos);
    speed = 2;
    lives = 5;
}

//--------------------------------------------------------------
void Player::update(){
    if (is_up_pressed)
        pos.y -= speed;
    if (is_down_pressed)
        pos.y += speed;
    if (is_left_pressed)
        pos.x -= speed;
    if (is_right_pressed)
        pos.x += speed;
    
}

//--------------------------------------------------------------
void Player::draw(){
    img->draw(pos.x - width/2,pos.y - height/2);
}

//--------------------------------------------------------------
void Player::shoot(){
}
