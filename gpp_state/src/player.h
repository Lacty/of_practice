
#pragma once
#include "ofMain.h"
#include "ofxJoystick.h"


class PlayerState;

class Player {
public:
  Player();
  
  void handleInput(ofxJoystick& input);
  void update();
  void draw();
  
  const ofVec2f& getPos() const;
  void setPos(const ofVec2f& pos);
  
  const ofVec2f& getJumpPow() const;
  
  void setColor(const ofShortColor& color);
  
private:
  shared_ptr<PlayerState> state_;
  
  ofxJoystick joy_;
  
  ofVec2f pos_;
  ofVec2f jumpPow_;
  
  ofShortColor color_;
};