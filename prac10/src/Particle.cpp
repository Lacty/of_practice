
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


void Particle::update() {
  if (enableGravity) {
    gravityVelocity.y += gravity;
    velocity += gravityVelocity;
  }
  position += velocity;
}

void Particle::draw() {
  ofSetColor(color);
  ofDrawCircle(position, size);
}