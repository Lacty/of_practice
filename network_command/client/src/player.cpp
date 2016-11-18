
#include "player.h"


Player::Player() {
  jumpPow_.set(0, 10);

  state_.push_back(make_shared<StandingState>());
}

void Player::handleInput(Input& input) {
  shared_ptr<PlayerState> state = state_.back()->handleInput(*this, input);
  if (state) {
    if (state == PlayerState::finish) {
      // err : state stack will become nothing
      assert(state_.at(1) != nullptr);
      state_.pop_back();
    } else {
      state_.push_back(state);
    }
    
    state_.back()->entry(*this);
  }
}

void Player::update(Input& input) {
  handleInput(input);
  state_.back()->update(*this, input);
}

void Player::draw() {
  ofDrawBox(pos_, 50);
}

const ofVec2f& Player::getPos() const { return pos_; }
const ofVec2f& Player::getVel() const { return vel_; }
const ofVec2f& Player::getJumpPow() const { return jumpPow_; }

void Player::setPos(const ofVec2f& pos) { pos_.set(pos); }
void Player::setVel(const ofVec2f& vel) { vel_.set(vel); }

void Player::addState(const shared_ptr<PlayerState>& state) {
  state_.push_back(state);
}