#include "ofApp.h"

#include "projector.h"

void ofApp::setup() {
  ofSetFrameRate(60);
  ofSetLogLevel(OF_LOG_ERROR);
  //ofSetLogLevel(OF_LOG_VERBOSE);
  depthCamera.setup();
  rgbCamera.setup();
  colorTracker.setup();
  Projector::setWorldDimensions(800, 600);
  calibrationServer.setup(&rgbCamera, &depthCamera, &colorTracker);
}

void ofApp::update() {
  depthCamera.update();
  rgbCamera.update();
  colorTracker.update(&rgbCamera.getPixels());
  calibrationServer.update();
}

void ofApp::draw() {
  Projector::startDraw();
  // DRAW STUFF HERE
  Projector::drawBounds();
  Projector::endDraw();
}
