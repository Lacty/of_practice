
#pragma once
#include "ofxScene.h"


class FirstScene : public ofxScene {
public:
  void setup();
  void update();
  void draw();
  
  void willFadeIn();
  void willDraw();
  void willFadeOut();
  void willExit();
};