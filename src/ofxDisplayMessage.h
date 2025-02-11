#pragma once
#include "ofMain.h"

class ofxDisplayMessage
{
private:
	ofxDisplayMessage();
	~ofxDisplayMessage();

public:
	void draw(ofEventArgs &e);

	// static methods
	static void loadFont(string _path, float _size);
	static void setMessage(string _message);
	static void clearMessage();
	static void setDuration(float _duration);
	static float getDuration();
	static void setPos(ofVec2f _pos);
	static void setPos(float _x, float _y);
	static ofVec2f getPos();
	static void setColor(ofColor _color);
	static ofColor getColor();
	static void setBackgroundColor(ofColor _color);
	static ofColor getBackgroundColor();
	static void setShowing(bool _showing);
	static bool getSwhoing();
	static void toggleShowing();
	static void setLogEnabled(bool _enabled);
	static bool getLogEnabled();

private:
	bool initialized;
	bool showing;
	bool logEnabled;
	ofColor color, bgColor;
	ofVec2f pos;
	ofVec2f drawPos;
    ofVec2f drawSize;
	ofMutex mutex;

	string message;
	float messageDuration; // sec
	float pastSetMessageTimef;
	ofTrueTypeFont font;

	// static member
	static ofxDisplayMessage* singleton;
	static void singletonGenerate();
    
    // helper method
    // get string width with '\n'
    float getMessageStringWidth();
};

