#include "ofxScreenGrab.h"

//-------------
void ofxScreenGrab::setup(int width, int height, bool retina) {
    this->width = width;
    this->height = height;
    if (retina) rx = 2;
    else        rx = 1;
    tex.allocate(rx * width, rx * height, GL_RGBA);

#ifdef _WIN32
	screen_context = GetDC( NULL );
	screen_x = this->width;// GetDeviceCaps( screen_context, HORZRES ); //(fullscreen)
	screen_y = this->height;// GetDeviceCaps( screen_context, VERTRES ); //(fullscreen)
	compatible_screen_context = CreateCompatibleDC( screen_context );
	screen_bitmap = CreateCompatibleBitmap( screen_context, screen_x, screen_y );
	HGDIOBJ hOld = SelectObject( compatible_screen_context, screen_bitmap );
	BitBlt( compatible_screen_context, 0, 0, screen_x, screen_y, screen_context, 0, 0, SRCCOPY );
	SelectObject( compatible_screen_context, hOld );

	info;
	info.biSize = sizeof( BITMAPINFOHEADER );
	info.biPlanes = 1;
	info.biBitCount = 32;
	info.biWidth = screen_x;
	info.biHeight = -screen_y;
	info.biCompression = BI_RGB;
	info.biSizeImage = 0;

	screenPixels = new RGBQUAD[ screen_x * screen_y ];

	pPixels = new unsigned char[ screen_x * screen_y * 4 ]();

#endif
}

//-------------
void ofxScreenGrab::grabScreen(int x, int y) {
    unsigned char * data = pixelsBelowWindow(x, y, width, height);
#ifndef _WIN32
    for (int i = 0; i < rx*rx*width*height; i++){
		unsigned char r1 = data[i*4];
		data[i*4]   = data[i*4+1];
		data[i*4+1] = data[i*4+2];
		data[i*4+2] = data[i*4+3];
		data[i*4+3] = r1;
	}	
	
#endif // !_WIN32
	if (data!= NULL) tex.loadData(data, rx*width, rx*height, GL_RGBA);
}

//-------------
void ofxScreenGrab::draw(int x, int y, int w, int h) {
    tex.draw(x, y, w, h);
}
#ifdef _WIN32
unsigned char * ofxScreenGrab::pixelsBelowWindow( int xi, int yi, int wi, int hi )
{
	//update
	screen_context = GetDC( NULL );
	screen_x = this->width;// GetDeviceCaps( screen_context, HORZRES ); //(fullscreen)
	screen_y = this->height;// GetDeviceCaps( screen_context, VERTRES ); //(fullscreen)
	compatible_screen_context = CreateCompatibleDC( screen_context );
	screen_bitmap = CreateCompatibleBitmap( screen_context, screen_x, screen_y );
	HGDIOBJ hOld = SelectObject( compatible_screen_context, screen_bitmap );
	BitBlt( compatible_screen_context, 0, 0, screen_x, screen_y, screen_context, 0, 0, SRCCOPY );
	SelectObject( compatible_screen_context, hOld );

	GetDIBits( compatible_screen_context, screen_bitmap, 0, screen_y, screenPixels, ( BITMAPINFO* ) &info, DIB_RGB_COLORS );
	ReleaseDC( NULL, screen_context );
	DeleteDC( compatible_screen_context );

	// getimage
	for( int i = 0; i < rx*rx*width*height; i++ ) {
		RGBQUAD p = screenPixels[ i ];
		pPixels[ i * 4 ] = (unsigned char ) ( p.rgbRed );
		pPixels[ i * 4 + 1 ] = ( unsigned char ) ( p.rgbGreen );
		pPixels[ i * 4 + 2 ] = ( unsigned char ) ( p.rgbBlue );
		pPixels[ i * 4 + 3] = ( unsigned char ) ( 255 );
	}
	return pPixels;
}
#endif