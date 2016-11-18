
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  tcp_.setup(88888);
}

//--------------------------------------------------------------
void ofApp::update() {
  for (unsigned int i = 0; i < tcp_.getLastID(); i++) {
    if (tcp_.isClientConnected(i)) {
      string str = tcp_.receive(i);
      tcp_.send(i, str);
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (unsigned int i = 0; i < tcp_.getLastID(); i++) {
    if (tcp_.isClientConnected(i)) {
      ofDrawBitmapString("connect id " + ofToString(i), 20, 20);
    }
  }
}

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
