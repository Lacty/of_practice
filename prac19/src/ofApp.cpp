
#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup() {
  sceneManager_.addScene(ofPtr<ofxScene>(new FirstScene));
  sceneManager_.addScene(ofPtr<ofxScene>(new SecondScene));
  sceneManager_.run();
}

//--------------------------------------------------------------
void ofApp::update() {
  sceneManager_.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  sceneManager_.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  sceneManager_.changeScene();
}

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
