#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxJSON.h"

class ColorTracker {
  public:
    void setup();
    void update(ofPixels* source);

    vector<ofPoint> getPoints();

    void setParameter(string param, double value);
    Json::Value getParams();

    double getDepthAt(double x, double y); // TODO
    ofPixels& getDisplayPixels();

    void resetSettings();
    void loadSettings();
    void saveSettings();

  private:
    // Objects
    ofPixels* source;
    ofxCvColorImage tempImage;
    ofxCvGrayscaleImage monoImage;
    ofxXmlSettings settings;
    ofParameterGroup parameters;
    ofxCvContourFinder blobTracker;
    // Methods
    void applySettings();
    void syncSettings();
    Json::Value paramsToJson(ofParameterGroup paramGroup);
    // Data
    ofParameter<int> blobMinSize;
    ofParameter<int> blobMaxSize;
    ofParameter<int> numBlobs;
    ofParameter<int> colorBottom;
    ofParameter<int> colorTop;



};

