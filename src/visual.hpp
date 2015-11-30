//
//  visual.hpp
//  finalSketch
//
//  Created by Iris Qu on 11/27/15.
//
//

#ifndef visual_hpp
#define visual_hpp

#include "ofMain.h"


class Particle {
public:
    void setup();
    void update();
    void draw();
    
    Particle();
    
    ofParameterGroup visualParams;
    
    ofParameter<float> release;
    
   
    ofParameter<float> sensitivity;
    
    ofParameter<float> rotateX;
    ofParameter<float> rotateY;
    ofParameter<float> rotateZ;
    
    float * fftSmooth;
    int bands;
    float rotationX = 0.0;
    float rotationY = 0.0;
    float rotationZ = 0.0;
    
    vector<ofPoint> pos;
    vector<ofPoint> vel;
    
    
    float *frequencies;
    ofPoint emitterCenter;
    int numParticles = 256;
    
    
    
};

#endif /* visual_hpp */
