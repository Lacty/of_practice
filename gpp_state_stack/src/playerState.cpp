
#include "playerState.h"
#include "player.h"

shared_ptr<PlayerState> PlayerState::finish = make_shared<PlayerState>();

shared_ptr<PlayerState> StandingState::handleInput(Player& player, ofxJoystick& input) {
  if (input.isPressed(0)) {
    ofLog() << "standing -> jumping";
    return make_shared<JumpingState>();
  }
  
  return nullptr;
}
void StandingState::update(Player& player) {}
void StandingState::entry(Player& player) {}


shared_ptr<PlayerState> MovingState::handleInput(Player& player, ofxJoystick& input) {}
void MovingState::update(Player& player) {}
void MovingState::entry(Player& player) {}


shared_ptr<PlayerState> JumpingState::handleInput(Player& player, ofxJoystick& input) {
  if (input.isRelease(0)) {
    ofLog() << "jumping -> standing";
    return PlayerState::finish;
  }

  return nullptr;
}
void JumpingState::update(Player& player) {}
void JumpingState::entry(Player& player) {}