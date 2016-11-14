
#pragma once
#include "ofMain.h"
#include "ofxJoystick.h"


class Player;

class PlayerState {
public:
  virtual ~PlayerState() {};
  virtual shared_ptr<PlayerState> handleInput(Player& player, ofxJoystick& input) {};
  virtual void update(Player& player) {};
};

class StandingState : public PlayerState {
public:
  shared_ptr<PlayerState> handleInput(Player& player, ofxJoystick& input) override;
  void update(Player& player) override;
};

class DuckingState : public PlayerState {
public:
  DuckingState(Player& player);

  shared_ptr<PlayerState> handleInput(Player& player, ofxJoystick& input) override;
  void update(Player& player) override;
};

class JumpingState : public PlayerState {
private:
  ofVec2f vel_;
  
public:
  JumpingState(Player& player);
  shared_ptr<PlayerState> handleInput(Player& player, ofxJoystick& input) override;
  void update(Player& player) override;
};