
#pragma once
#include "ofMain.h"


enum Window {
  Width  = 200,
  Height = 100
};

const int NUM_PARTICLES = Width * Height;

class ofApp : public ofBaseApp {
private:
  // Vbo (Vertex Buffer Object)
  // OpenGL内に頂点バッファを作っておいて
  // GPUに処理させることによりCPUの負担を減らし高速化を図る
  ofVbo vbo;
  
  // 頂点の位置
  ofVec3f vertices[NUM_PARTICLES];
  
  // 頂点色
  ofFloatColor colors[NUM_PARTICLES];
  
  
  ofEasyCam cam;

public:
  void setup();
  void update();
  void draw();
  
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y );
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
  
};
