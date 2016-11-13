
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  image_.load("image.png");
  
  int w = image_.getWidth();
  int h = image_.getHeight();
  
  for (int i = 0; i < w; i++){
    for (int j = 0; j < h; j++){
      auto color = image_.getColor(i, j);
      image_.setColor(i, j, color);
    }
  }
  
  image_.save("i1.png");
}

//--------------------------------------------------------------
void ofApp::update() {}

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
