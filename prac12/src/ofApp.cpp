
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(30);

  gui.setup();
  
  gui.add(scale.setup("Scale", 1.0f, 0.0f, 3.0f));
  gui.add(pos.setup("Position", ofVec3f(ofGetWidth() * 0.5f,
                                        ofGetHeight() * 0.9,
                                        0),
                                ofVec3f(-500, -500, -500),
                                ofVec3f(500, 500, 500)));
  gui.add(rot.setup("Rotate", ofVec3f(0, 0, 0),
                              ofVec3f(-180, -180, -180),
                              ofVec3f(180, 180, 180)));

  model.loadModel("Hutya/Hutyakiti_hatOFF_lowVer.fbx");
}

//--------------------------------------------------------------
void ofApp::update() {
  model.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofEnableDepthTest();
  ofPoint p;
  ofPushMatrix();
    ofTranslate(pos);
    ofRotateX(rot->x);
    ofRotateY(rot->y);
    ofRotateZ(rot->z);
    ofScale(ofVec3f(scale, scale, scale));
    model.drawFaces();
  ofPopMatrix();
  
  ofDisableDepthTest();
  
  gui.draw();
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
