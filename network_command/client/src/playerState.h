
#pragma once
#include "input.h"


class Player;

class PlayerState {
public:
  virtual ~PlayerState() {};
  
  virtual shared_ptr<PlayerState> handleInput(Player& player, Input& input) {};
  
  virtual void update(Player& player, Input& input) {};
  virtual void entry(Player& player) {};
  
  static shared_ptr<PlayerState> finish;
};

class StandingState : public PlayerState {
public:
  shared_ptr<PlayerState> handleInput(Player& player, Input& input) override;
  void update(Player& player, Input& input) override;
  void entry(Player& player) override;
};

class MovingState : public PlayerState {
public:
  shared_ptr<PlayerState> handleInput(Player& player, Input& input) override;
  void update(Player& player, Input& input) override;
  void entry(Player& player) override;
};

class JumpingState : public MovingState {
public:
  shared_ptr<PlayerState> handleInput(Player& player, Input& input) override;
  void update(Player& player, Input& input) override;
  void entry(Player& player) override;
};