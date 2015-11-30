#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
  
    visual01.setup();
    
    guiGroup.setName("controls");
    guiGroup.add(visual01.visualParams);
    
    gui.setup(guiGroup);
    
    gui.add(volume.set("volume", 0.6, 0.0, 1.0));
    gui.add(speed.set("speed", 1.0, -0.3, 3.0));
    
    beat.loadSound("sound.mp3");
    beat.setLoop(true);
    beat.play();
    
    ofEnableSmoothing();
    ofSetFrameRate(80);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    beat.setVolume(volume);
    beat.setSpeed(speed);
    
    visual01.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.draw();
    
  
    visual01.draw();
   
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
