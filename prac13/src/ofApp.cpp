
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  ofSetFrameRate(60);
  
  gui.setup();
  
  gui.add(mode.setup("Mode", 0, 0, 1));
  gui.add(point_size.setup("Point Size", 3, 0, 20));
  gui.add(create_per_frame.setup("Per Frame", 1, 0, 5));
  gui.add(max_vel.setup("Max Velocity", 1, 0, 5));
  gui.add(vel_rate.setup("Velocity Rate", 0.9, 0, 1));
  gui.add(alpha_rate.setup("Alpha Rate", 0.01, 0, 0.1));
  gui.add(create_color.setup("Color",
                             ofFloatColor(1, 1, 1, 1),
                             ofFloatColor(0, 0, 0, 0),
                             ofFloatColor(1, 1, 1, 1)));
}

//--------------------------------------------------------------
void ofApp::update() {
  for (auto& part : particle) {
    part.update(vel_rate, alpha_rate);
  }
  
  float vel_x = (mouseX - last_frame_mouse.x) * 0.1;
  float vel_y = (mouseY - last_frame_mouse.y) * 0.1;
  
  int i;
  for (i = 0; i < create_per_frame; i++) {
    switch(mode) {
      case 0: {
        particle.push_back({ofVec2f(mouseX, mouseY),
                            ofVec2f(ofRandom(-max_vel, max_vel) + vel_x,
                                    ofRandom(-max_vel, max_vel) + vel_y),
                            create_color});
      } break;
      
      case 1: {
        particle.push_back({ofVec2f(ofGetWidth() * 0.7f, ofGetHeight() * 0.5f),
                            ofVec2f(ofRandom(-max_vel, max_vel),
                                    ofRandom(-max_vel, max_vel)),
                            create_color});
      }
    }
  }
  
  last_frame_mouse.set(mouseX, mouseY);
}

//--------------------------------------------------------------
void ofApp::draw() {
  glPointSize(point_size);
  
  for (auto& part : particle) {
    part.draw();
  }
  
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
void ofApp::mousePressed(int x, int y, int button) {
  particle.clear();
}

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
