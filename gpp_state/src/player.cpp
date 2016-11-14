
#include "player.h"
#include "playerState.h"


Player::Player() {
  joy_.setup(GLFW_JOYSTICK_1);
  state_ = make_shared<StandingState>();
  pos_.set(ofGetWindowWidth() * 0.5f, ofGetWindowHeight() * 0.7f);
  jumpPow_.set(0, -10);
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
  ofSetColor(color_);
  ofDrawBox(pos_, 50);
}

const ofVec2f& Player::getPos() const {
  return pos_;
}

void Player::setPos(const ofVec2f& pos) {
  pos_.set(pos);
}

const ofVec2f& Player::getJumpPow() const {
  return jumpPow_;
}

void Player::setColor(const ofShortColor& color) {
  color_ = color;
}