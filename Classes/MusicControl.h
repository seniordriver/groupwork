#ifndef _MusicControl_H_
#define _MusicControl_H_

#include "cocos2d.h"
#include "ObjectDefine.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;


class MusicControl:public Node
{
public:
	static void playBackgroundMusic();
	static void changeisStop();
	static bool getisStop();
	static void changemusic(int a);
private:
	static bool isStop;
	static int music;
};

#endif