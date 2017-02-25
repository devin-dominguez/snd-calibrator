#pragma once

#include "ofMain.h"


class Projector {
  public:
    static void setup(); // TODO
    static void startDraw();
    static void endDraw();

    static void drawBounds();

    static void setWorldDimensions(double width, double height);

    static void changeSize(int dLeft, int dRight, int dTop, int dBottom);
    static void changeRotation(double dRot);
    static void changePosition(ofVec2f offset);

    static ofPoint getCoords(ofPoint position);
    static double getScale(double size);

  private:
    // Objects
    static ofPoint position;
    static ofRectangle bounds;
    // Methods
    static void updateBounds();
    static void drawMasking(); //TODO
    // Data
    static int width;
    static int height;
    static double worldWidth;
    static double worldHeight;
    static double left;
    static double right;
    static double top;
    static double bottom;
    static double rotation;
};
