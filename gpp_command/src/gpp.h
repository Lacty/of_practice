
#pragma once
#include "ofMain.h"
#include "ofxJoystick.h"


class GameActor {
public:
  void jump()    { ofLog() << "jump";     }
  void fireGun() { ofLog() << "fire gun"; }
};

class Command {
public:
  virtual ~Command() {}
  virtual void execute(GameActor& actor) = 0;
};

class JumpCommand : public Command {
public:
  void execute(GameActor& actor) override {
    actor.jump();
  }
};

class FireGunCommand : public Command {
public:
  void execute(GameActor& actor) override {
    actor.fireGun();
  }
};

class NoneCommand : public Command {
public:
  void execute(GameActor& actor) override {}
};

class InputHandler {
public:
  InputHandler() :
  none_(new NoneCommand) {
    joy_.setup(GLFW_JOYSTICK_1);
  }

  void setButtonX(shared_ptr<Command> com) { buttonX_ = com; }
  void setButtonY(shared_ptr<Command> com) { buttonY_ = com; }

  shared_ptr<Command> handleInput() {
    joy_.update();
    if (joy_.isPush(0)) { return buttonX_; }
    if (joy_.isPush(1)) { return buttonY_; }
    return none_;
  }

private:
  ofxJoystick joy_;

  shared_ptr<Command> buttonX_;
  shared_ptr<Command> buttonY_;
  shared_ptr<Command> none_;
};