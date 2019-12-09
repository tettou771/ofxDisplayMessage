#pragma once
#include "ofMain.h"

// 何かしらのメッセージを画面下に表示するクラス
// 一定時間後に消える

class ofxDisplayMessage
{
private:
	ofxDisplayMessage();
	~ofxDisplayMessage();

public:
	// singleton menber
	void draw(ofEventArgs &e);

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
	static void setShowing(bool _showing);
	static bool getSwhoing();
	static void toggleShowing();
	static void setLogEnabled(bool _enabled);
	static bool getLogEnabled();

private:
	static ofxDisplayMessage *singleton;
	static void singletonGenerate();

	bool initialized;
	bool showing;
	bool logEnabled;
	ofColor color;
	ofVec2f pos;
	ofVec2f drawPos;
	ofMutex mutex;

	string message;
	float messageDuration; // sec
	float pastSetMessageTimef;
	ofTrueTypeFont font;
};

