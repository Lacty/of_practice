
#include "player.h"
#include "playerState.h"


Player::Player() {
  joy_.setup(GLFW_JOYSTICK_1);
  state_ = make_shared<StandingState>();
}

void Player::handleInput(ofxJoystick& input) {
  shared_ptr<PlayerState> state = state_->handleInput(*this, input);
  if (state) {
    state_.swap(state);
  }
}

void Player::update() {
  joy_.update();
  handleInput(joy_);
  state_->update(*this);
}

void Player::draw() {
  ofDrawBox(pos_, 50);
}

const ofVec2f& Player::getPos() const { return pos_; }