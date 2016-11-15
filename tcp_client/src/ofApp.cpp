
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(30);

  tcp_.setup("127.0.0.1", 88888);
  
  deltaTime   = 0;
  connectTime = 0;
}

//--------------------------------------------------------------
void ofApp::update() {
  if (!tcp_.isConnected()) {
    deltaTime = ofGetElapsedTimeMillis() - connectTime;
    if (deltaTime > 5000) {
      tcp_.setup("127.0.0.1", 88888);
      connectTime = ofGetElapsedTimeMillis();
    }
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  if (tcp_.isConnected()) {
    ofDrawBitmapString("status : connecting", 20, 20);
  } else {
    ofDrawBitmapString("status : disconnecting", 20, 20);
    ofDrawBitmapString("reconnect at " + ofToString(deltaTime / 1000), 20, 40);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {
  if (tcp_.isConnected()) {
    xml_.clear();
    xml_.setValue("posX", x);
    xml_.setValue("posY", y);
    string msg;
    xml_.copyXmlToString(msg);
    tcp_.send(msg);
  }
}

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
