
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  gui.setup();
  
  gui.add(size.setup("Size", 50, 0, 200));
  gui.add(pos.setup("Position", ofVec2f(ofGetWidth() * 0.5f + 50, ofGetHeight() * 0.5f),
                                ofVec2f(0, 0),                          // min
                                ofVec2f(ofGetWidth(), ofGetHeight()))); //max
  gui.add(color.setup("Color", ofColor(100, 255, 50),
                               ofColor(0, 0, 0),
                               ofColor(255, 255, 255)));
  gui.add(label.setup("fps", ""));
}

//--------------------------------------------------------------
void ofApp::update() {
  label = ofToString(ofGetFrameRate(), 1);
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofBackgroundGradient(ofColor::white, ofColor::darkGray);

  //ofSetColor(color);
  //ofDrawBox(pos->x, pos->y, 0, size);
  
  //gui.draw();
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
