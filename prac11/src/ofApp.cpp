
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  ofSetCircleResolution(32);
}

//--------------------------------------------------------------
void ofApp::update() {
  for (auto& part : particles) {
    if (part.pos.x < 0) {
      part.pos.x = 0;
      part.vel.x *= -1;
    }
    if (part.pos.x > 460) {
      part.pos.x = 460;
      part.vel.x *= -1;
    }
    if (part.pos.y < 0) {
      part.pos.y = 0;
      part.vel.y *= -1;
    }
    if (part.pos.y > 300) {
      part.pos.y = 300;
      part.vel.y *= -1;
    }
    
    part.pos += part.vel;
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  vector<ofVec2f> parts(particles.size());
  for (int i = 0; i < parts.size(); i++) {
    parts[i] = particles[i].pos;
  }

  center.average(&parts[0], parts.size());
  
  for (auto& particle : particles) {
    ofDrawCircle(particle.pos, 5);
    ofDrawLine(particle.pos, center);
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
void ofApp::mousePressed(int x, int y, int button) {
  float speed = 2;
  particles.push_back({{static_cast<float>(x), static_cast<float>(y)},
                       {ofRandom(-speed, speed), ofRandom(-speed, speed)}});
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
