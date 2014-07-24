#include "ofxScreenGrab.h"

//-------------
void ofxScreenGrab::setup(int width, int height) {
    this->width = width;
    this->height = height;
    tex.allocate(width, height, GL_RGBA);
}

//-------------
void ofxScreenGrab::grabScreen(int x, int y) {
	unsigned char * data = pixelsBelowWindow(x, y, width, height);
    for (int i = 0; i < width*height; i++){
		unsigned char r1 = data[i*4];
		data[i*4]   = data[i*4+1];
		data[i*4+1] = data[i*4+2];
		data[i*4+2] = data[i*4+3];
		data[i*4+3] = r1;
	}	
	if (data!= NULL) tex.loadData(data, width, height, GL_RGBA);
}

//-------------
void ofxScreenGrab::draw(int x, int y) {
    tex.draw(x, y);
}