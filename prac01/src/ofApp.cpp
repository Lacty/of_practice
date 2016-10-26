#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofDrawCone(100, 100, 0, 50, 100);
  ofDrawBox(300, 100, 0, 80, 80, 80);
  ofDrawPlane(ofGetWindowWidth() / 2, 100, 70, 70);
  ofDrawCircle(ofGetWindowWidth() - 300, 100, 50);
  ofDrawSphere(ofGetWindowWidth() - 100, 100, 50);
  ofDrawEllipse(100, 500, 100, 70);
  ofDrawCylinder(300, 500, 50, 100);
  ofDrawIcoSphere(ofGetWindowWidth() / 2, 500, 0, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
