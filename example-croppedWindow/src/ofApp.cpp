#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    bool retina = true;
    grabber.setup(800, 600, retina);
}

//--------------------------------------------------------------
void ofApp::update(){
    grabber.update();
}

//------------------------------------------------- -------------
void ofApp::draw(){
    if (grabber.isDebug()) {
        grabber.drawDebug();
    } else {
        grabber.draw(0, 0);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key==' ') {
        grabber.toggleDebug();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    grabber.mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    grabber.mouseDragged(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    grabber.mousePressed(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    grabber.mouseReleased(x, y);
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
