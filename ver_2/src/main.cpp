#include "ofMain.h"
#include "ofApp.h"

#include <iostream>

//========================================================================
int main()
{
	ofSetupOpenGL(1920 * 2, 1080, OF_FULLSCREEN);			// <-------- setup the GL context

															// this kicks off the running of my app
															// can be OF_WINDOW or OF_FULLSCREEN
															// pass in width and height too:
	std::string port;
	std::cout << "[*] port : ";
	std::cin >> port;	

	ofRunApp(new ofApp(port));

}

