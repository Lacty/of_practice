
#pragma once
#include "ofMain.h"


class Joystick {
private:
  bool isConnect_;

  int    id_;
  string name_;

  int buttonNum_;
  int axisNum_;
  
  set<int> push_;
  set<int> press_;
  set<int> release_;
  
  vector<float> axis_;
  
  void updateState() {
    isConnect_ = (glfwJoystickPresent(id_) == GL_TRUE);
    if (!isConnect_) {
      name_ = glfwGetJoystickName(id_);
    }
  }
  
  void updateAxis() {
    static const float* axis = glfwGetJoystickAxes(id_, &axisNum_);
    axis_ = vector<float>(&axis[0], &axis[axisNum_]);
  }
  
  void updateButton() {
    push_.clear();
    release_.clear();
  
    static const unsigned char* button = glfwGetJoystickButtons(id_, &buttonNum_);
    
    for (int i = 0; i < buttonNum_; i++) {
      switch(button[i]) {
        case GLFW_PRESS : {
          if (press_.find(i) == press_.end()) {
            push_.emplace(i);
          }
          press_.emplace(i);
          break;
        }
        case GLFW_RELEASE : {
          if (press_.find(i) != press_.end()) {
            release_.emplace(i);
            press_.erase(press_.find(i));
          }
          break;
        }
      }
    }
  }

public:
  Joystick() = default;

  explicit Joystick(int JoyId) {
    setup(JoyId);
  }
  
  void setup(int JoyId) {
    id_   = JoyId;
  
    updateState();
    if (!isConnect_) {
      ofLog() << "Joypad [" << id_ << "] : disconnected";
      return;
    }
    
    name_ = glfwGetJoystickName(id_);
    glfwGetJoystickButtons(id_, &buttonNum_);
    glfwGetJoystickAxes(id_, &axisNum_);

    ofLog() << "JoyPad connected : " << name_;
    ofLog() << "Button Num : " << buttonNum_;
    ofLog() << "Axis Num : " << axisNum_ << endl;
  }
  
  int getId() const {
    return id_;
  }
  
  const string& getName() const {
    return name_;
  }
  
  int getButtonNum() const {
    return buttonNum_;
  }
  
  int getAxisNum() const {
    return axisNum_;
  }
  
  void update() {
    updateState();
    updateAxis();
    updateButton();
  }
  
  bool isConnect() const {
    return isConnect_;
  }
  
  float getAxis(int num) const {
    if (!isConnect_) return 0;
    if (num > axisNum_) return 0;
    return axis_[num];
  }
  
  bool isPush(int button) const {
    if (push_.find(button) == push_.end()) {
      return false;
    }
    return true;
  }
  
  bool isPress(int button) const {
    if (press_.find(button) == press_.end()) {
      return false;
    }
    return true;
  }
  
  bool isRelease(int button) const {
    if (release_.find(button) == release_.end()) {
      return false;
    }
    return true;
  }
};

class ofApp : public ofBaseApp {
private:
  Joystick joy_;

public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y );
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  
};
