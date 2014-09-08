#include "ofxScreenGrab.h"

//-------------
void ofxScreenGrab::setup(int width, int height, bool retina) {
    this->width = width;
    this->height = height;
    if (retina) rx = 2;
    else        rx = 1;
    tex.allocate(rx * width, rx * height, GL_RGBA);
}

//-------------
void ofxScreenGrab::grabScreen(int x, int y) {
    unsigned char * data = pixelsBelowWindow(x, y, width, height);
    for (int i = 0; i < rx*rx*width*height; i++){
		unsigned char r1 = data[i*4];
		data[i*4]   = data[i*4+1];
		data[i*4+1] = data[i*4+2];
		data[i*4+2] = data[i*4+3];
		data[i*4+3] = r1;
	}	
	if (data!= NULL) tex.loadData(data, rx*width, rx*height, GL_RGBA);
}

//-------------
void ofxScreenGrab::draw(int x, int y, int w, int h) {
    tex.draw(x, y, w, h);
}