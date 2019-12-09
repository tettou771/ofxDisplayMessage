# ofxDisplayMessage

## Overview

This is an addon for openFrameworks.
I made it to show attention message on window easily.

## Requirement

ofxDisplayMessage doesn't depend other addons.

## Tested system

- Windows 10 + VS2017 +  of0.10.1 .

I think compatible almost all versions, because it's simple addon.

## Usage

1. Add this addon.
1. Include `ofxTextFlow.h`.
1. Put the static method `ofxDisplayMessage::setMessage("My text")`  when you need.

It's gonna delete old message when over the max num (default: 30 lines).

You can use some method to change appearance.
For example.

```cpp
// set position
// message align with text boundingbox center
ofxDisplayMessage::setPos(500, 1000);

// set text color
// default value is ofColor::gray
ofxDisplayMessage::setColor(ofColor(0, 0, 0));

// set font
// draw with ofTrueTypeFont if loaded
ofxDisplayMessage::loadFont("arial.ttf", 30);

// change display duration (sec)
// default value is 5.0
ofxDisplayMessage::setDuration(10);
```

