
#pragma once

#include "ofMain.h"


class Particle {
private:
  ofVec3f position;
  ofVec3f velocity;
  
  ofColor color;
  
  float size;
  float gravity;
  
  bool enableGravity;
  ofVec3f gravityVelocity;
  
public:
  Particle() :
    size(0.0f),
    gravity(0.0f),
    enableGravity(false)
  {}
  
  Particle* setPosition(const ofVec3f& pos);
  Particle* setVelocity(const ofVec3f& vel);
  Particle* setColor(const ofColor& color);
  Particle* setSize(const float size);
  Particle* setGravity(const bool enable, const float g);
  
  void update(bool bound, float left, float right, float top, float bottom);
  void draw();
};