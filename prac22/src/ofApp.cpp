
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  mainCam_.setFov(60);
  mainCam_.setFarClip(1000);
  mainCam_.setNearClip(5);
  
  subCam_.setFov(60);
  subCam_.setFarClip(1000);
  subCam_.setNearClip(5);
  
  gui_.setup();
  
  gui_.add(mainCamPos_.setup("Main Camera Position", ofVec3f(0, 0, 150), ofVec3f(-300, -300, -300), ofVec3f(300, 300, 300)));
  gui_.add(subCamPos_.setup("Sub Camera Position", ofVec3f(0, 0, 150), ofVec3f(-300, -300, -300), ofVec3f(300, 300, 300)));
  gui_.add(framePos_.setup("Frame Position", ofVec2f(0, 0), ofVec2f(0, 0), ofVec2f(500, 500)));
  gui_.add(frameSize_.setup("Frame Szie", ofVec2f(ofGetWindowWidth() * 0.3, ofGetWindowHeight() * 0.3), ofVec2f(0, 0), ofVec2f(ofGetWindowWidth(), ofGetWindowHeight())));
  
  ofLog() << "viewport w :" << ofGetViewportWidth();
  ofLog() << "viewport h :" << ofGetViewportHeight();
}

//--------------------------------------------------------------
void ofApp::update() {
  mainCam_.setPosition(mainCamPos_);
  subCam_.setPosition(subCamPos_);
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofBackground(200, 200, 200);
  { // mainの描画
    mainCam_.begin();
    ofDrawBox(50);
    mainCam_.end();
  }
  
  glViewport(framePos_->x, ofGetWindowHeight() - frameSize_->y - framePos_->y, frameSize_->x, frameSize_->y);
  
  { // subカメラの描画
    subCam_.begin();
    ofDrawBox(50);
    subCam_.end();
  }
  
  glViewport(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
  ofNoFill();
  ofDrawRectangle(framePos_->x, framePos_->y, frameSize_->x, frameSize_->y);
  gui_.draw();
  ofFill();
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
