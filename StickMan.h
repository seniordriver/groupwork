#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ObjectDefine.h"
#include "MusicControl.h"
#pragma once

using namespace std;

class StickMan: public Sprite
{
public:
	static StickMan *GetInstance();

	static void DestoryInstance();
	
	static void onKeyUp();
	//static void onKeyDown();
	//Sprite* GetStickMan();
private:
	
	//~StickMan() { DestoryInstance(); }
	static StickMan* m_Instance;
	//Sprite* stickMan;
};
