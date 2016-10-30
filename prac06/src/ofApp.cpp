
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(30);
  ofSetWindowTitle("web cam test");
  
  // 接続中のどのデバイスにするか設定
  grabber.setDeviceID(0);
  
  // 解像度設定
  grabber.initGrabber(500, 500);
  
  
  // grabber.setDeviceID(0);
  // warning setDeviceID : can't set device while grabber is running.
  // grabberが起動中は設定できない
  // initの前に実行すべし
}

//--------------------------------------------------------------
void ofApp::update() {
  grabber.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
  // 画面いっぱいに描画
  grabber.draw(0, 0, ofGetWidth(), ofGetHeight());
  
  // 目が痛いのでCone出しておきますね
  ofDrawCone(ofGetWidth() * 0.5, ofGetHeight() * 0.5, 100, 150);
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
