#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"
#include "ofxXmlSettings.h"
#include "ofxJSON.h"

class GCDepth {
  public:
    void setup();
    void update();

    void setParameter(string param, double value);
    Json::Value getParams();

    double getDepthAt(double x, double y); // TODO
    ofPixels& getDisplayPixels();
    ofPixels& getPixels();

    void resetSettings();
    void loadSettings(); // TODO
    void saveSettings(); // TODO

  private:
    // Objects
    ofxKinect kinect;
    ofxCvGrayscaleImage displayPixels;
    ofRectangle bounds;
    ofxXmlSettings settings;
    ofParameterGroup parameters;
    // Methods
    void updateBounds();
    void applySettings();
    void syncSettings();
    Json::Value paramsToJson(ofParameterGroup paramGroup);
    // Data
    static int width;
    static int height;
    ofParameter<int> left;
    ofParameter<int> right;
    ofParameter<int> top;
    ofParameter<int> bottom;
    ofParameter<double> rotation;
    ofParameter<double> nearClip;
    ofParameter<double> farClip;

};

