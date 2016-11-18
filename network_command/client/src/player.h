
#pragma once
#include "ofMain.h"
#include "input.h"
#include "playerState.h"


class Player {
private:
  ofVec2f pos_;
  ofVec2f jumpPow_;
  ofVec2f vel_;
  
  deque<shared_ptr<PlayerState>> state_;
  
  void handleInput(Input& input);
  
public:
  Player();
  
  void update(Input& input);
  void draw();
  
  const ofVec2f& getPos() const;
  const ofVec2f& getVel() const;
  const ofVec2f& getJumpPow() const;
  
  void setPos(const ofVec2f& pos);
  void setVel(const ofVec2f& vel);
  
  void addState(const shared_ptr<PlayerState>& state);
};