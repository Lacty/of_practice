
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> StandingState::handleInput(Player& player, ofxJoystick& input) {
  if (input.isPush(2)) {
    ofLog() << "stand -> ducking";
    return make_shared<DuckingState>(player);
  }
  
  if (input.isPush(1)) {
    ofLog() << "stand -> jump";
    return make_shared<JumpingState>(player);
  }
  
  return nullptr;
}
void StandingState::update(Player& player) {}


DuckingState::DuckingState(Player& player) {
  player.setColor(ofShortColor::black);
}

shared_ptr<PlayerState> DuckingState::handleInput(Player& player, ofxJoystick& input) {
  if (input.isRelease(2)) {
    ofLog() << "ducking -> stand";
    player.setColor(ofShortColor::white);
    return make_shared<StandingState>();
  }
  
  return nullptr;
}
void DuckingState::update(Player& player) {}


JumpingState::JumpingState(Player& player) :
vel_(player.getJumpPow()) {
  player.setColor(ofShortColor::aqua);
}

shared_ptr<PlayerState> JumpingState::handleInput(Player& player, ofxJoystick& input) {
  int FLOOR = ofGetWindowHeight() * 0.7;
  if (player.getPos().y >= FLOOR) {
    player.setPos(ofVec2f(player.getPos().x, FLOOR));
    player.setColor(ofShortColor::white);
    return make_shared<StandingState>();
  }
  return nullptr;
}

void JumpingState::update(Player& player) {
  vel_.y += 0.3;
  ofVec2f newLocation = player.getPos() + vel_;
  player.setPos(newLocation);
}
