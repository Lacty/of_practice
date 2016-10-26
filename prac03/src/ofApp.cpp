#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofEnableDepthTest();
  //ofSetSmoothLighting(true);
  
  pointLight.setDiffuseColor( ofFloatColor( 0.85f, 0.85f, 0.85f));
  pointLight.setSpecularColor( ofFloatColor( 1.0f, 1.0f, 1.0f));
  
  material.setShininess( 120);
  material.setSpecularColor( ofFloatColor( 255, 255, 255, 255));
  
  ofSetSphereResolution( 24);
  
  
  pointLight.setPosition( 0, 0, 400);
}

//--------------------------------------------------------------
void ofApp::update(){
  angle += ofGetElapsedTimef();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofEnableLighting();
  pointLight.enable();
  
  ofPushMatrix();
  ofTranslate( ofGetWindowSize() / 2);
  
  material.begin();
  ofDrawCone( 0, 0, 0, 50, 120);
  material.end();
  
  ofPopMatrix();
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
