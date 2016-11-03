
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  ofSetCircleResolution(32);
}

//--------------------------------------------------------------
void ofApp::update() {
  for (auto& part : particles) {
    part.update();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  for (auto& part : particles) {
    part.draw();
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
  create(x, y);
}

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


void ofApp::create(int x, int y) {
  Particle part;
  part.setPosition(ofVec3f(x, y, 0))
  ->setSize(2 + ofRandom(5))
  ->setColor(ofColor(100 + ofRandom(155), 100 + ofRandom(155), 100 + ofRandom(155)))
  ->setGravity(true, 0.08f)
  ->setVelocity(ofVec3f(ofRandom(-5, 5), ofRandom(-5, 5), 0));
  particles.push_back(part);
}