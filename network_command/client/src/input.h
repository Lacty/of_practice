
#pragma once
#include "ofMain.h"


constexpr int INPUT_POOL = 20;

class Input {
private:
  bool pressed_[INPUT_POOL];
  bool pushing_[INPUT_POOL];
  bool release_[INPUT_POOL];
  
  unordered_map<string, vector<int>> names_;

public:
  
  // link the name to the button
  void addName(const string& name, int button);
  
  // de = default
  const string& getName(int button, const string& de) const {
    for (const auto& v : names_) {
      for (auto i : v.second) {
        if (i == button) {
          return v.first;
        }
      }
    }
    return de;
  }
  
  void setPressed(int button);
  void setPushing(int button);
  void setRelease(int button);
  
  void setPressed(const string& name) {
    for (auto& i : names_[name]) {
      setPressed(i);
    }
  }
  void setPushing(const string& name) {
    for (auto& i : names_[name]) {
      setPushing(i);
    }
  }
  void setRelease(const string& name) {
    for (auto& i : names_[name]) {
      setRelease(i);
    }
  }
  
  bool isPressed(const string& name);
  bool isPushing(const string& name);
  bool isRelease(const string& name);
  
  bool isPressed(int button) const;
  bool isPushing(int button) const;
  bool isRelease(int button) const;
  
  void clear();
};