
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  //player1_.setup(GLFW_JOYSTICK_1);
  //player2_.setup(GLFW_JOYSTICK_2);
  
  //glfwSetJoystickCallback(joystickCB);
}

//--------------------------------------------------------------
void ofApp::update() {
  //player1_.update();
  
  //ofLog() << "player1 left axis X : " << player1_.getAxis(0);
  //ofLog() << "player1 left axis Y : " << player1_.getAxis(1);
  
  ofLog() << "joy 0 : " << glfwJoystickPresent(0);
  ofLog() << "joy 1 : " << glfwJoystickPresent(1);
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
