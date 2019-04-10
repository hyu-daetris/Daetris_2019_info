#include "ofApp.h"
#include <iostream>

time_t rawtime;
/// Created by Jeong 2019.03.01

void ofApp::osc208()
{
	bang = 0;
	while ( receiver.hasWaitingMessages() )
	{

		ofxOscMessage m;
		receiver.getNextMessage(&m);

		for ( int i = 0; i < m.getNumArgs(); i++ )
		{
			if ( m.getArgType(i) == OFXOSC_TYPE_FLOAT )
			{
				bang = m.getArgAsFloat(0);
			}
		}
	}

	if ( mbangsw == 1 )
	{
		bang = 1;
	}

	if ( abb == 1 )
	{
		abbco += 1;
		if ( abbco > 200 )
		{
			abb = 0; abbco = 0;
		}
	}

}

//--------------------------------------------------------------
void ofApp::setup()
{

	background.load("images/BACKGROUND.png");
	background.rotate90(3);

	message_top.load("images/MESSAGE_TOP.png");
	message_top.rotate90(3);
	
	for ( int i = 0; i < 2; i++ )
	{
		message_bottom[i].load("images/MESSAGE_BOTTOM" + std::to_string(i + 1) + ".png");
		message_bottom[i].rotate90(3);
	}
	
	box.load("images/BOX.png");
	box.rotate90(3);
	box_bottom.load("images/BOX_BOTTOM.png");
	box_bottom.rotate90(3);
	table.load("images/TABLE.png");
	table.rotate90(3);

	for ( int i = 0; i < 6; i++ )
	{
		coins[i].load("images/COINS_" + std::to_string(i + 1) + ".png");
		coins[i].rotate90(3);
	}
	coin.setup();


	isChanged = 0;
	count = CHANGETIME;
	BottomChange = 0;
	bottom_count = BOTTOM_CHANGETIME;

}

//--------------------------------------------------------------
void ofApp::update()
{
	osc208();

	if ( bang != 0 && abb == 0 && completeCounter == -1 )
	{
		abb = 1;
		if ( word_writing )return;
		if ( c_index <= c_endIndex )return;
		test = true;

		coin.onTagged();
		// Log the check-time in the ~/bin/data/log.txt
		time(&rawtime);
		myTextFile.open("log.txt", ofFile::Append);
		myTextFile << ctime(&rawtime);
		myTextFile.close();


	}

	///change background coins------------
	count--;
	if ( !count )
	{
		isChanged++;
		count = CHANGETIME;
		if ( isChanged >= 6 )
		{
			isChanged = 0;
		}
	}
	///change bottom message-----------------
	bottom_count--;
	if ( !bottom_count )
	{
		BottomChange++;
		bottom_count = BOTTOM_CHANGETIME;
		if ( BottomChange >= 2 )
		{
			BottomChange = 0;
		}
	}
	//-----------------------------------------------
	coin.update();

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofPushMatrix();
	//ofTranslate(-1920, 0);

	background.draw(0, 0, 1920, 1080);

	background.draw(1920, 0, 1920, 1080);
	table.draw(0, 0, 1920, 1080);
	box.draw(0, 0, 1920, 1080);

	coin.draw();
	message_top.draw(0, 0, 1920, 1080);
	coins[isChanged].draw(1920, 0, 1920, 1080);

	box_bottom.draw(0, 0, 1920, 1080);
	message_bottom[BottomChange].draw(1920, 0, 1920, 1080);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
	mbangsw = 1;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
	mbangsw = 0;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
