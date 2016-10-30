
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  sphere.setRadius(100);
}

//--------------------------------------------------------------
void ofApp::update() {
  // 改行入れなくて改行されるようだ
  ofLog() << "mouseX = " << mouseX;
  ofLog() << "mouseY = " << mouseY;
  
  pos.x += (mouseX - pos.x) * 0.1f;
  pos.y += (mouseY - pos.y) * 0.1f;
}

//--------------------------------------------------------------
void ofApp::draw() {
  sphere.setPosition(pos);
  sphere.draw();
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
void ofApp::mousePressed(int x, int y, int button) {
  pos = ofVec2f(ofRandom(ofGetWidth()),
                ofRandom(ofGetHeight()));
}

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
