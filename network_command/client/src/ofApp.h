
#pragma once
#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "ofxTCPClient.h"
#include "ofxJoystick.h"

#include "player.h"
#include "input.h"


class ofApp : public ofBaseApp {
private:
  Player player_;
  Input playerInput_;
  
  Player other_;
  Input otherInput_;

  ofxXmlSettings xml_;
  ofxJoystick joy_;
  
  ofCamera cam_;
  
  ofxTCPClient tcp_;
  int deltaTime;
  int connectTime;
  
  void reconnect();
  void updateInput();

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
