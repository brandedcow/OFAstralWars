#include "ofApp.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    game_state = "start";
    score = 0;
    
    max_enemy_amplitude = 3.0;
    max_enemy_shoot_interval = 1.5;
    
    player_image.load("images/player.png");
    enemy_image.load("images/enemy.png");
    enemy_bullet_image.load("images/enemy_bullet.png");
    player_bullet_image.load("images/player_bullet.png");
    
    player_bullet_sound.load("sounds/player_bullet.mp3");
    
    player_start.set(256, 650);
    player_1.setup(&player_image, player_start);
    
    start_screen.load("images/start_screen.png");
    end_screen.load("images/end_screen.png");
    score_font.load("fonts/steelworks_vintage.otf", 48);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if (game_state == "start") {
        
    } else if (game_state == "game") {
        player_1.update();
        limitPlayer(&player_1.pos);
        update_bullets();
        
        for (int i = 0; i < enemies.size(); i+=1) {
            enemies[i].update();
            if (enemies[i].time_to_shoot()) {
                Bullet b;
                b.setup(false, enemies[i].pos, enemies[i].speed, &enemy_bullet_image);
                bullets.push_back(b);
            }
        }
        
        if (level_controller.should_spawn() == true) {
            Enemy e;
            e.setup(max_enemy_amplitude, max_enemy_shoot_interval, &enemy_image);
            enemies.push_back(e);
        }
    } else if (game_state == "end") {
        
    }
               
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (game_state == "start") {
        start_screen.draw(0,0);
    } else if (game_state == "game") {
        ofBackground(0, 0, 0);
        
        
        for (int i = 0; i < enemies.size(); i+=1) {
            enemies[i].draw();
        }
        for(int i = 0; i< bullets.size(); i+=1) {
            bullets[i].draw();
        }
        
        player_1.draw();
        
        draw_score();
        draw_lives();
    } else if (game_state == "end") {
        end_screen.draw(0,0);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (game_state == "game") {
        if (key == OF_KEY_LEFT)
            player_1.is_left_pressed = true;
        if (key == OF_KEY_RIGHT)
            player_1.is_right_pressed = true;
        if (key == OF_KEY_UP)
            player_1.is_up_pressed = true;
        if (key == OF_KEY_DOWN)
            player_1.is_down_pressed = true;
        if (key == ' ') {
            Bullet b;
            b.setup(true, player_1.pos, player_1.speed, &player_bullet_image);
            bullets.push_back(b);
            player_bullet_sound.play();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (game_state == "start" && key == ' ') {
        game_state = "game";
        level_controller.setup(ofGetElapsedTimeMillis());
    } else if (game_state == "game") {
        if (key == OF_KEY_LEFT)
            player_1.is_left_pressed = false;
        if (key == OF_KEY_RIGHT)
            player_1.is_right_pressed = false;
        if (key == OF_KEY_UP)
            player_1.is_up_pressed = false;
        if (key == OF_KEY_DOWN)
            player_1.is_down_pressed = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::update_bullets() {
    for (int i = 0; i < bullets.size(); i+=1) {
        bullets[i].update();
        if (bullets[i].pos.y - bullets[i].width/2 < 0 || bullets[i].pos.y + bullets[i].width/2 > ofGetHeight()) {
            bullets.erase(bullets.begin() + i);
        }
    }
    check_bullet_collisions();
}

void ofApp::limitPlayer(ofPoint * point) {
    
    if (0 > point->x) {
        point->x = 0;
    }
    if (point->x > ofGetWindowWidth()) {
        point->x = ofGetWindowWidth();
    }
    if (0 > point->y) {
        point->y = 0;
    }
    if(point->y > ofGetWindowHeight()) {
        point->y = ofGetWindowHeight();
    }
}

void ofApp::check_bullet_collisions() {
    for (int i = 0; i < bullets.size(); i++) {
        if (bullets[i].from_player) {
            for (int e = enemies.size()-1; e >= 0; e--) {
                if (ofDist(bullets[i].pos.x, bullets[i].pos.y, enemies[e].pos.x, enemies[e].pos.y) < (enemies[e].width + bullets[i].width)/2) {
                    enemies.erase(enemies.begin()+e);
                    bullets.erase(bullets.begin()+i);
                    score+=10;
                }
            }
        } else {
            if (ofDist(bullets[i].pos.x, bullets[i].pos.y, player_1.pos.x, player_1.pos.y) < (bullets[i].width+player_1.width)/2) {
                bullets.erase(bullets.begin()+i);
                player_1.lives--;
                
                if (player_1.lives <= 0) {
                    game_state = "end";
                }
            }
        }
    }
}

void ofApp::draw_lives() {
    for (int i = 0; i < player_1.lives; i++) {
        player_image.draw(ofGetWidth() - (i * player_image.getWidth()) - 100, 30);
    }
}

void ofApp::draw_score() {
    if (game_state == "game") {
        score_font.drawString(ofToString(score), 30, 72);
    } else if (game_state == "end") {
        float w = score_font.stringWidth(ofToString(score));
        score_font.drawString(ofToString(score), ofGetWidth()/2 - w/2, ofGetHeight()/2 + 100);
    }
}

void ofApp::reset_game() {
    
}
