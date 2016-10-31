
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
  ofBackground(0);
  ofEnableDepthTest();
  
  cam.setDistance(50);
  cam.setPosition(0, -50, 50);
  cam.setTarget(ofVec3f(50, 50, 0));
  
  for (int i = 0; i < Width; i++) {
    for (int j = 0; j < Height; j++) {
      vertices[j * Width + i].set(i - Width * 0.5, j - Height * 0.5, 0);
      colors[j * Width + i].set(0.5, 0.8, 1.0, 1.0);
    }
  }
  
  vbo.setVertexData(vertices, NUM_PARTICLES, GL_DYNAMIC_DRAW);
  vbo.setColorData(colors, NUM_PARTICLES, GL_DYNAMIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update() {
  //頂点の位置を更新
  for(int i = 0;i < Width;i++){
    for(int j = 0;j < Height;j++){
      float x = sin(i * 0.1 + ofGetElapsedTimef()) * 1.0;
      float y = sin(j * 0.15 + ofGetElapsedTimef()) * 10.0;
      float z = x + y;
      
      vertices[j * Width + i] = ofVec3f(i - Width/2,j - Height/2,z);
    }
  }
  
  //頂点バッファ更新
  vbo.updateVertexData(vertices, NUM_PARTICLES);
}

//--------------------------------------------------------------
void ofApp::draw() {
  cam.begin();
  
  glPointSize(0.1f);
  vbo.draw(GL_POINTS, 0, NUM_PARTICLES);
  
  cam.end();
  
  //ログ表示
  string info;
  info = "Vertex num = " + ofToString(NUM_PARTICLES,0) + "¥n";
  info += "FPS =" + ofToString(ofGetFrameRate(),2);
  ofDrawBitmapString(info, 30, 30);
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
