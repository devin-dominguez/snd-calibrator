#include "projector.h"

// Objects
ofPoint Projector::position = ofPoint(0, 0);
ofRectangle Projector::bounds = ofRectangle(
  0, 0, Projector::width, Projector::height
);

// Data
double Projector::worldWidth = 800;
double Projector::worldHeight = 600;
int Projector::width = 640;
int Projector::height = 480;
double Projector::left = 0;
double Projector::right = Projector::width;
double Projector::top = 0;
double Projector::bottom = Projector::height;
double Projector::rotation = 0;

// Lifecycle Methods
void Projector::setup() {} // TODO

void Projector::startDraw() {
  ofPushMatrix();
    ofTranslate(position);
    ofPushMatrix();
      ofTranslate(bounds.getCenter());
      ofRotate(rotation);
}

void Projector::endDraw() {
      drawMasking();
    ofPopMatrix();
  ofPopMatrix();
}

// Data Interface

void Projector::setWorldDimensions(double width, double height) {
  Projector::width = width;
  Projector::height = height;
}

void Projector::changeSize(int dLeft, int dRight, int dTop, int dBottom) {
  left = ofClamp(left + dLeft, 0, width / 2);
  right = ofClamp(right + dRight, width / 2 + 1, width);
  top = ofClamp(top + dTop, 0, height / 2);
  bottom = ofClamp(bottom + dBottom, height / 2 + 1, height);
  updateBounds();
}

void Projector::changeRotation(double dRot) {
  rotation += dRot;
}

void Projector::changePosition(ofVec2f offset) {
  position += offset;
}

void Projector::drawBounds() {
  ofPushStyle();
  ofSetRectMode(OF_RECTMODE_CENTER);

  ofNoFill();
  ofDrawRectangle(bounds);

  ofPopStyle();
}

ofPoint Projector::getCoords(ofPoint position) {
  double ratioX = bounds.width / worldWidth;
  double ratioY = bounds.height / worldHeight;
  double x = ratioX * position.x + bounds.x;
  double y = ratioY * position.y + bounds.y;

  return ofPoint(x, y);
}

double Projector::getScale(double size) {
  double ratioX = bounds.width / worldWidth;
  double ratioY = bounds.height / worldHeight;

  return size * fmax(ratioX, ratioY);
}

// Internal Methods
void Projector::drawMasking() {} // TODO

void Projector::updateBounds() {
  bounds.y = top;
  bounds.x = left;
  bounds.height = bottom - top;
  bounds.width = right - left;
}
