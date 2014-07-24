#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    /* setup a grab window, same size as the app */
    grabber.setup(ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    /* grab screen starting at (0, 0) */
    grabber.grabScreen(0, 0);
}

//------------------------------------------------- -------------
void ofApp::draw(){
    grabber.draw(0, 0);
    
    /* or you can get the texture directly */
    ofTexture tex = grabber.getTextureReference();
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
