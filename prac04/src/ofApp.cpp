
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  ofEnableDepthTest();
  ofEnableLighting();
  
  pointLight.enable();
  pointLight.setPosition(0, 0, 500);
  
  pointLight.setAmbientColor( ofFloatColor(0.1, 0.1, 0.5));
  pointLight.setDiffuseColor( ofFloatColor(0.2, 0.2, 1.0));
  pointLight.setSpecularColor( ofFloatColor(1.0, 1.0, 1.0));
  
  box.set(60);
  box.setPosition(ofGetWindowWidth() * .20, ofGetWindowHeight() * .5, 0);
  
  icoSphere.setRadius(50);
  icoSphere.setPosition(ofGetWindowWidth() * .80, ofGetWindowHeight() * .5, 0);
  
  cylinder.set(40, 80);
  cylinder.setPosition(ofGetWindowWidth() * .5, ofGetWindowHeight() * .5, 0);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  box.rotate(ofGetLastFrameTime() * 25, ofVec3f(1, 1, 0));
  box.drawWireframe();
  
  icoSphere.rotate(ofGetLastFrameTime() * 25, ofVec3f(1, 1, 0));
  icoSphere.draw();
  icoSphere.drawNormals(5);
  
  cylinder.rotate(ofGetLastFrameTime() * 25, ofVec3f(1, 1, 0));
  cylinder.draw();
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
