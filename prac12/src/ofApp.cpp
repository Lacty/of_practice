
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(30);
  ofEnableDepthTest();

  model.loadModel("Hutya/Hutyakiti_hatOFF_lowVer.fbx");
  model.setPosition(ofGetWidth() * 0.5, (float)ofGetHeight() * 0.9 , 0);
  
  //model.setLoopStateForAllAnimations(OF_LOOP_NORMAL);
  //model.playAllAnimations();
  
  model.enableTextures();
}

//--------------------------------------------------------------
void ofApp::update() {
  model.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  model.drawFaces();
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
