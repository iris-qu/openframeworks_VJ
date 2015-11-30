//
//  visual.cpp
//  finalSketch
//
//  Created by Iris Qu on 11/27/15.
//
//


#include "ofApp.h"


ofPoint getVelocity(float length, float angle) {
    ofPoint p;
    p.x = length * cos(angle);
    p.y = length * sin(angle);
    return p;
}

Particle::Particle() {
    emitterCenter = ofPoint (ofGetWidth() / 2, ofGetHeight() / 2);
}

void Particle::setup() {
    
    
    visualParams.add(release.set("release", 0.5, 0.0, 1.0));
    
      visualParams.add(rotateX.set("rotateX", 1.0, -1.0, 1.0));
    visualParams.add(rotateY.set("rotateY", -1.0, -1.0, 1.0));
    visualParams.add(rotateZ.set("rotateZ", 1.0, -1.0, 1.0));
    
    visualParams.add(sensitivity.set("sensitivity", 800, 100, 1000));

    
    
    frequencies = new float[numParticles];
    for (int i=0; i<numParticles; i++) {
        frequencies[i] = 0;
    }
    
    fftSmooth = new float [8192];
    for(int i=0; i<8192; i++) {
        fftSmooth[i] = 0;
    }
    bands = 128;
    
    
    for (int i=0; i<numParticles; i++) {
        ofPoint pnt, p;
        float angle = i * (M_TWO_PI / numParticles);
        pnt.x = cos(angle) * 200;
        pnt.y = sin(angle) * 200;
        p.x = 0;
        p.y = 0;
        
        pos.push_back(emitterCenter + pnt);
        vel.push_back(p);
    }
    
    
}

void Particle::update(){
    
    rotationX= rotationX + rotateX;
    rotationY= rotationY + rotateY;
    rotationZ= rotationZ + rotateZ;
    
    float curFreqRange = 0;
    int curParticle = 0;
    
    
    
    float * value = ofSoundGetSpectrum(bands);
    for(int i=0; i<bands; i++){
        fftSmooth[i] *= release;
        if(fftSmooth[i] < value[i]){
            fftSmooth[i] = value[i];
        }
        
        vel[i] = getVelocity(sensitivity * fftSmooth[i], 60);
        frequencies[i] = fftSmooth[i]*0.94f;
        int size = -fftSmooth[i]*60;
       
    }
    
    
}

void Particle::draw(){
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    ofSetColor(ofRandom(100, 255), ofRandom(100, 255), ofRandom(100, 255), 255);
    
    for (int i=0; i<numParticles; i++) {
        
        
        
        for (int i=0; i<numParticles; i++) {
            
            

            float size = ofMap(frequencies[i], 0, 1, 0.5, frequencies[i]);
            float hue = ofMap(frequencies[i], 0, 1, 100, 300);
            
            ofRotateX(rotationX);
            ofRotateY(rotationY);
            ofRotateZ(rotationZ);
            
            ofCircle(pos[i] + vel[i], size);
        }
 
    }
    
 }