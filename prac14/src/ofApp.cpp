
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {}

//--------------------------------------------------------------
void ofApp::update() {
  const unsigned char* button = glfwGetJoystickButtons(GLFW_JOYSTICK_1, &count);
  for (int i = 0; i < count; i++) {
    if (GLFW_PRESS == button[0]) {
      cout << "button 0 press" << endl;
    }
    if (GLFW_PRESS == button[1]) {
      cout << "button 1 press" << endl;
    }
    if (GLFW_PRESS == button[2]) {
      cout << "button 2 press" << endl;
    }
    if (GLFW_PRESS == button[3]) {
      cout << "button 3 press" << endl;
    }
    if (GLFW_PRESS == button[4]) {
      cout << "button 4 press" << endl;
    }
  }
  
  //cout << glfwGetJoystickAxes(GLFW_JOYSTICK_1, &count);
  //cout << "JoyStick present :" << glfwJoystickPresent(GLFW_JOYSTICK_1) << endl;
  //ofLog() << "count = " << count << endl;
}

//--------------------------------------------------------------
void ofApp::draw() {}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
