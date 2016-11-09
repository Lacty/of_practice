
#pragma once
#include "ofMain.h"

#include <list>


class JoyPad {
private:
  int    id_;
  string name_;

  int buttonNum_;
  int axisNum_;
  
  set<int> push_;
  set<int> press_;
  set<int> release_;
  
  vector<float> axis_;

public:
  JoyPad() = default;

  explicit JoyPad(int JoyId) {
    setup(JoyId);
  }
  
  void setup(int JoyId) {
    id_   = JoyId;
    name_ = glfwGetJoystickName(id_);
    glfwGetJoystickButtons(id_, &buttonNum_);
    glfwGetJoystickAxes(id_, &axisNum_);
    
    ofLog() << "JoyPad connected : " << name_;
    ofLog() << "Button Num : " << buttonNum_;
    ofLog() << "Axis Num : " << axisNum_ << endl;
  }
  
  void update() {
    const float* axis = glfwGetJoystickAxes(id_, &axisNum_);
    axis_ = vector<float>(&axis[0], &axis[axisNum_]);
  }
  
  float getAxis(int num) const {
    if (num > axisNum_) return 0;
    return axis_[num];
  }
};

class ofApp : public ofBaseApp {
private:
  JoyPad player1_;
  JoyPad player2_;

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
