
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> StandingState::handleInput(Player& player, ofxJoystick& input) {
  if (input.isPush(2)) {
    ofLog() << "stand -> ducking";
    return make_shared<DuckingState>();
  }
  
  if (input.isPush(1)) {
    ofLog() << "stand -> jump";
    return make_shared<JumpingState>();
  }
  
  return nullptr;
}
void StandingState::update(Player& player) {}


shared_ptr<PlayerState> DuckingState::handleInput(Player& player, ofxJoystick& input) {
  if (input.isRelease(2)) {
    ofLog() << "ducking -> stand";
    return make_shared<StandingState>();
  }
  
  return nullptr;
}
void DuckingState::update(Player& player) {}


shared_ptr<PlayerState> JumpingState::handleInput(Player& player, ofxJoystick& input) {
  return nullptr;
}
void JumpingState::update(Player& player) {}
