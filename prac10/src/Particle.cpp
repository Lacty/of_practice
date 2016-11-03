
#include "Particle.h"


Particle* Particle::setPosition(const ofVec3f& pos) {
  position.set(pos);
  return this;
}

Particle* Particle::setVelocity(const ofVec3f& vel) {
  velocity.set(vel);
  return this;
}

Particle* Particle::setColor(const ofColor& color) {
  this->color.set(color);
  return this;
}

Particle* Particle::setSize(const float size) {
  this->size = size;
  return this;
}

Particle* Particle::setGravity(const bool enable, const float g) {
  this->enableGravity = enable;
  this->gravity = g;
  return this;
}


void Particle::update(bool bound, float left, float right, float top, float bottom) {
  if (enableGravity) {
    //gravityVelocity.y += gravity;
    velocity.y += gravity;
  }
  if (bound) {
    if (position.x > right) {
      position.x = right;
      velocity.x *= -0.9f;
    }
    if (position.x < left) {
      position.x = left;
      velocity.x *= -0.9f;
    }
    if (position.y > bottom) {
      position.y = bottom;
      velocity.y *= -0.9f;
    }
    if (position.y < top) {
      position.y = top;
      velocity.y *= -0.9;
    }
  }
  position += velocity;
}

void Particle::draw() {
  ofSetColor(color);
  ofDrawCircle(position, size);
}