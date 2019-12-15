#include "ofxDisplayMessage.h"

ofxDisplayMessage* ofxDisplayMessage::singleton;

ofxDisplayMessage::ofxDisplayMessage() {
	messageDuration = 5;
	ofAddListener(ofEvents().draw, this, &ofxDisplayMessage::draw);
	initialized = true;
	logEnabled = true;
    showing = true;
	color = ofColor::gray;
	pos.set(ofGetWidth() / 2, ofGetHeight() / 2);
}


ofxDisplayMessage::~ofxDisplayMessage() {
}

void ofxDisplayMessage::draw(ofEventArgs& e) {
	if (showing && ofGetElapsedTimef() - pastSetMessageTimef < messageDuration) {
		ofSetColor(color);
		if (font.isLoaded()) {
			font.drawString(message, drawPos.x, drawPos.y);
		}
		else {
			ofDrawBitmapString(message, drawPos);
		}
	}
}

void ofxDisplayMessage::loadFont(string _path, float _size) {
	singletonGenerate();
	singleton->font.load(_path, _size);
}

void ofxDisplayMessage::setMessage(string _message) {
	singletonGenerate();
	singleton->mutex.lock();
	singleton->message = _message;
	singleton->mutex.unlock();
	if (singleton->logEnabled) {
		ofLog() << "ofxDisplayMessage: " << _message;
	}
	singleton->pastSetMessageTimef = ofGetElapsedTimef();

	// calc position
	float width, height, lineHeight;
	if (singleton->font.isLoaded()) {
		width = singleton->font.stringWidth(singleton->message);
		height = singleton->font.stringHeight(singleton->message);
		lineHeight = singleton->font.getSize();
	}
	else {
		auto lines = ofSplitString(singleton->message, "\n");
		int maxLineLength = 0;
		for (auto& line : lines) {
			maxLineLength = MAX(maxLineLength, line.length());
		}
		width = maxLineLength * 8;
		lineHeight = 10;
		height = 13.5 * lines.size();
	}
	singleton->drawPos = singleton->pos - ofVec2f(width / 2, height / 2 - lineHeight);
}

void ofxDisplayMessage::clearMessage() {
	setMessage("");
}

void ofxDisplayMessage::setDuration(float _duration) {
	singletonGenerate();
	singleton->messageDuration = MAX(0, _duration);
}

float ofxDisplayMessage::getDuration() {
	singletonGenerate();
	return singleton->messageDuration;
}

void ofxDisplayMessage::setPos(ofVec2f _pos) {
	singletonGenerate();
	singleton->drawPos += _pos - singleton->pos;
	singleton->pos.set(_pos);
}

void ofxDisplayMessage::setPos(float _x, float _y) {
	setPos(ofVec2f(_x, _y));
}

ofVec2f ofxDisplayMessage::getPos() {
	singletonGenerate();
	return singleton->pos;
}

void ofxDisplayMessage::setColor(ofColor _color) {
	singletonGenerate();
	singleton->color.set(_color);
}

ofColor ofxDisplayMessage::getColor() {
	singletonGenerate();
	return singleton->color;
}

void ofxDisplayMessage::setShowing(bool _showing) {
	singletonGenerate();
	singleton->showing = _showing;
}

bool ofxDisplayMessage::getSwhoing() {
	singletonGenerate();
	return singleton->showing;
}

void ofxDisplayMessage::toggleShowing() {
	singletonGenerate();
	singleton->showing = !singleton->showing;
}

void ofxDisplayMessage::setLogEnabled(bool _enabled) {
	singletonGenerate();
	singleton->logEnabled = _enabled;
}

bool ofxDisplayMessage::getLogEnabled() {
	singletonGenerate();
	return singleton->logEnabled;
}

void ofxDisplayMessage::singletonGenerate() {
	if (singleton == nullptr) {
		singleton = new ofxDisplayMessage();
	}
}
