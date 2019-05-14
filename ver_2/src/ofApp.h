#pragma once

#include "ofMain.h"
#include "ofxOsc.h"
#include "Coin.hpp"
#include "Serial.hpp"

class ofApp : public ofBaseApp
{
private:
	SerialApp m_serial;

	time_t m_rawtime;

	void callback(int byte) {
		coin.onTagged();
		// Log the check-time in the ~/bin/data/log.txt
		time(&m_rawtime);
		myTextFile.open("log.txt", ofFile::Append);
		myTextFile << ctime(&m_rawtime);
		myTextFile.close();
	}

public:
	ofApp(std::string const& port) : m_serial(port, 9600) {
		m_serial.set_callback([this](int byte){ callback(byte); });
	}

	void setup();
	void update();
	void draw();

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
