
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  font.load("aerial.ttf", 24);
}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  stringstream ss;
  ss << "FPS > " << ofToString(ofGetFrameRate(), 0) << " <" << endl;
  ofDrawBitmapString(ss.str(), 20, 20);
  
  // ofToString(T val, int precision);
  // precision 制度
  // 0で整数、1で小数点一位までに変換
  
  // 小さな書体ではofDrawBitmapStringが遅い可能性がある
  // TrueTypeFontを使用して回避すると良い
  // doc参照 http://openframeworks.cc/documentation/graphics/ofGraphics/#show_ofDrawBitmapString
  
  
  font.drawString(ofToString(ofGetSeconds() ,0) + "/sec", 20, 50);
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
