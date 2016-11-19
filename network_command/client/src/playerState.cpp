
#include "playerState.h"
#include "player.h"


shared_ptr<PlayerState> PlayerState::finish = make_shared<PlayerState>();

shared_ptr<PlayerState> StandingState::handleInput(Player& player, Input& input) {
  
  // to Jump
  if (input.isPressed("Jump")) {
    //ofLog() << "standing -> jumping";
    player.addState(make_shared<MovingState>());
    return make_shared<JumpingState>();
  }
  
  // to Move
  if (input.isPressed("Left")) {
    //ofLog() << "standing -> moving";
    return make_shared<MovingState>();
  }
  if (input.isPressed("Right")) {
    //ofLog() << "standing -> moving";
    return make_shared<MovingState>();
  }
  
  return nullptr;
}
void StandingState::update(Player& player, Input& input) {}
void StandingState::entry(Player& player) {}


shared_ptr<PlayerState> MovingState::handleInput(Player& player, Input& input) {
  // check for pushing any move button
  if (!input.isPushing("Left") &&
      !input.isPushing("Right"))
  {
    //ofLog() << "moving -> back to previous";
    return PlayerState::finish;
  }
  
  if (input.isPressed("Jump")) {
    //ofLog() << "moving -> jumping";
    return make_shared<JumpingState>();
  }
  
  return nullptr;
}
void MovingState::update(Player& player, Input& input) {
  if (input.isPushing("Left")) {
    ofVec2f newLocation = player.getPos();
    newLocation.x -= 1;
    player.setPos(newLocation);
  }
  
  if (input.isPushing("Right")) {
    ofVec2f newLocation = player.getPos();
    newLocation.x += 1;
    player.setPos(newLocation);
  }
}
void MovingState::entry(Player& player) {}


const int FLOOR = 0;
shared_ptr<PlayerState> JumpingState::handleInput(Player& player, Input& input) {
  if (player.getPos().y <= FLOOR) {
    //ofLog() << "jumping -> back to previous";
    return PlayerState::finish;
  }
  
  return nullptr;
}
void JumpingState::update(Player& player, Input& input) {
  MovingState::update(player, input);
  
  ofVec2f newVel = player.getVel();
  
  newVel.y -= 0.8;
  ofVec2f newLocation = player.getPos() + newVel;
  if (newLocation.y <= FLOOR) {
    newLocation.y = FLOOR;
    newVel.y -= newVel.y;
  }
  player.setPos(newLocation);
  player.setVel(newVel);
}
void JumpingState::entry(Player& player) {
  ofVec2f newVel = player.getVel() + player.getJumpPow();
  player.setVel(newVel);
}