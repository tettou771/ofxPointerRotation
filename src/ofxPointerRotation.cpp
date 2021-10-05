#include "ofxPointerRotation.h"

ofxPointerRotation::ofxPointerRotation() {
    // set default value
    easingFactor = 0.1;

    // initialize rotation parametor
    reset();
}

ofxPointerRotation::~ofxPointerRotation() {
    
}

void ofxPointerRotation::setup(const float & _easingFactor) {
    setEasingFactor(_easingFactor);
}

void ofxPointerRotation::update(const ofVec2f & next) {
    // if same position, rotation is zero
    if (current == past) {
        rotation = 0;
    }
    // rotation is nonzero if 3 points (next, current and past) makes triangle
    else {
        // vec
        ofVec3f a = current - past;
        ofVec3f b = next - current;
        
        // angle
        float theta = a.angleRad(b);
        ofVec3f crossed = a.getCrossed(b);
        
        // triangle surface < 0 -> theta is minus
        // +/- means direction of rotation
        if (crossed.z < 0) theta = -theta;
        else if (crossed.z == 0) theta = 0;
        
        rotation += (theta - rotation) * easingFactor;
    }
    
    past = current;
    current = next;
}

void ofxPointerRotation::reset() {
    // reset rotation
    past = current = ofVec2f();
    rotation = 0;
}

float ofxPointerRotation::getRotation() {
    return rotation;
}

void ofxPointerRotation::setEasingFactor(const float & f) {
    easingFactor = f;
}

float ofxPointerRotation::getEasingFactor() {
    return easingFactor;
}
