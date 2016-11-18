
#include "input.h"


void Input::addName(const std::string& name, int button) {
  names_[name].push_back(button);
}

void Input::setPressed(int button) { pressed_[button] = true; }
void Input::setPushing(int button) { pushing_[button] = true; }
void Input::setRelease(int button) { release_[button] = true; }

bool Input::isPressed(const std::string& name) {
  for (const auto& num : names_[name]) {
    if (pressed_[num]) {
      return true;
    }
  }
  return false;
}

bool Input::isPushing(const std::string& name) {
  for (const auto& num : names_[name]) {
    if (pushing_[num]) {
      return true;
    }
  }
  return false;
}

bool Input::isRelease(const std::string& name) {
  for (const auto& num : names_[name]) {
    if (release_[num]) {
      return true;
    }
  }
  return false;
}

bool Input::isPressed(int button) const { return pressed_[button]; }
bool Input::isPushing(int button) const { return pushing_[button]; }
bool Input::isRelease(int button) const { return release_[button]; }

void Input::clear() {
  for (int i = 0; i < INPUT_POOL; i++) {
    pressed_[i] = false;
    pushing_[i] = false;
    release_[i] = false;
  }
}