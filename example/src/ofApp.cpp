#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	// set text color
	// default value is ofColor::gray
	ofxDisplayMessage::setColor(ofColor(0, 0, 0));
	
	// set font
	// draw with ofTrueTypeFont if loaded
	//ofxDisplayMessage::loadFont("arial.ttf", 30);

	// change display duration (sec)
	// default value is 5.0
	ofxDisplayMessage::setDuration(10);
}

//--------------------------------------------------------------
void ofApp::update() {
	// nothing to do
}

//--------------------------------------------------------------
void ofApp::draw() {
	// nothing to show
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key) {
	case OF_KEY_BACKSPACE:
		// delete a character
		message = message.substr(0, message.length() - 1);
		break;

	case OF_KEY_RETURN:
		// line end
		message += '\n';
		break;

	default:
		message += key;
		break;
	}
	ofxDisplayMessage::setMessage(message);
}

void ofApp::mousePressed(int x, int y, int button) {
	ofxDisplayMessage::setPos(x, y);
	ofxDisplayMessage::setMessage("mouse pressed (" + ofToString(x) + ", " + ofToString(y) + ")");
	message = "";
}

void ofApp::windowResized(ofResizeEventArgs& resize) {
	ofxDisplayMessage::setPos(resize.width / 2, resize.height / 2);
	ofxDisplayMessage::setMessage("window resized (" + ofToString(resize.width) + ", " + ofToString(resize.height) + ")");
	message = "";
}
