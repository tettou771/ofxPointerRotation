#pragma once
#include "ofMain.h"

class ofxPointerRotation {
public:
    ofxPointerRotation();
    ~ofxPointerRotation();
    
    void setup(const float & _easingFactor = 0.1);
    void update(const ofVec2f & next);
    void reset();

    float getRotation();
    void setEasingFactor(const float & _f);
    float getEasingFactor();
    
private:
    float rotation;
    float easingFactor;
    ofVec2f past, current;
};
