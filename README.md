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
ofxDisplayMessage
```

