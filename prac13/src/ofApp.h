
#pragma once
#include "ofMain.h"
#include "ofxGui.h"

#include <vector>


class Particle {
public:
  ofVec2f      pos;
  ofVec2f      vel;
  ofFloatColor color;
  
  void update(const float vel_rate,
              const float alpha_rate) {
    pos     += vel * vel_rate;
    color.a -= alpha_rate;
  }
  
  void draw() {
    ofSetColor(color);
    
    glVertexPointer(2, GL_FLOAT, 0, pos.getPtr());
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glDrawArrays(GL_POINTS, 0, 1);
    
    glDisableClientState(GL_VERTEX_ARRAY);
  }
  
  bool shouldKill() const {
    return color.a <= 0;
  }
};

class ofApp : public ofBaseApp {
private:
  vector<Particle> particle;
  
  ofxPanel gui;
  
  ofxIntSlider   mode;
  ofxFloatSlider point_size;
  ofxIntSlider   create_per_frame;
  ofxFloatSlider max_vel;
  ofxFloatSlider vel_rate;
  ofxFloatSlider alpha_rate;
  ofxColorSlider_<float> create_color;

  ofVec2f last_frame_mouse;

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
