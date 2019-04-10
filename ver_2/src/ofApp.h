#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Coin.hpp"

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();


	void osc208();

	ofxOscReceiver receiver;

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofFile myTextFile;
	int completeCounter = -1;

	bool word_writing = false;
	int c_endIndex = -1;
	int c_index = 0;
	bool test = false;

	float bang;
	int mbangsw;
	int abb;
	int abbco;

	ofImage background;
	ofImage message_top;
	ofImage message_bottom[2];
	ofImage table;
	ofImage box, box_bottom;
	ofImage coins[6];
	Coin coin;

	int count;
	int isChanged;
	const int CHANGETIME = 100;

	int bottom_count;
	int BottomChange;
	const int BOTTOM_CHANGETIME = 700;

};
