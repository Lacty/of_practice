
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
  
private:
  shared_ptr<PlayerState> state_;
  
  ofxJoystick joy_;
  
  ofVec2f pos_;
};