
#include "ofApp.h"


enum Button {
  JUMP  = 14,
  LEFT  =  7,
  RIGHT =  5
};

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(60);

  joy_.setup(GLFW_JOYSTICK_1);
  
  // ボタンと名前を紐付け
  playerInput_.addName("Jump",  JUMP);
  playerInput_.addName("Left",  LEFT);
  playerInput_.addName("Right", RIGHT);
  
  cam_.setPosition(0, 0, 300);
  
  tcp_.setup("127.0.0.1", 88888);
  
  deltaTime   = 0;
  connectTime = 0;
}

//--------------------------------------------------------------
void ofApp::update() {
  updateInput();
  player_.update(playerInput_);
  
  if (tcp_.isConnected()) {
    {
      ofxXmlSettings xml;
      xml.addTag("Buttons");
      xml.pushTag("Buttons");
      
      int index = 0;
      
      for (int i = 0; i < joy_.getButtonNum(); i++) {
        
        string name = playerInput_.getName(i, "none");
        if (name == "none") { continue; }
        
        bool isPressed = playerInput_.isPressed(i);
        bool isPushing = playerInput_.isPushing(i);
        bool isRelease = playerInput_.isRelease(i);
        
        if (!(isPressed || isPushing || isRelease)) { continue; }
        
        
        xml.addTag("Button");
        xml.pushTag("Button", index++);
        
        if (isPressed) { xml.addValue("Pressed", name); }
        if (isPushing) { xml.addValue("Pushing", name); }
        if (isRelease) { xml.addValue("Release", name); }
        
        xml.popTag();
      }
      xml.popTag();
      
      string str;
      xml.copyXmlToString(str);
      
      tcp_.send(str);
    }
  }
  other_.update(otherInput_);
  
  playerInput_.clear();
}

//--------------------------------------------------------------
void ofApp::draw() {
  cam_.begin();
  player_.draw();
  cam_.end();
  
  reconnect();
}

void ofApp::reconnect() {
  if (!tcp_.isConnected()) {
    deltaTime = ofGetElapsedTimeMillis() - connectTime;
    if (deltaTime > 5000) {
      tcp_.setup("127.0.0.1", 88888);
      connectTime = ofGetElapsedTimeMillis();
    }
  }
  if (tcp_.isConnected()) {
    ofDrawBitmapString("status : connecting", 20, 20);
  } else {
    ofDrawBitmapString("status : disconnecting", 20, 20);
    ofDrawBitmapString("reconnect at " + ofToString(deltaTime / 1000), 20, 40);
  }
}

void ofApp::updateInput() {
  for (int i = 0; i < joy_.getButtonNum(); i++) {
    if (joy_.isPressed(i)) { playerInput_.setPressed(i); }
    if (joy_.isPushing(i)) { playerInput_.setPushing(i); }
    if (joy_.isRelease(i)) { playerInput_.setRelease(i); }
  }
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
