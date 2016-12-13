#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ObjectDefine.h"
#include "MusicControl.h"
<<<<<<< HEAD
#pragma once

using namespace std;

class StickMan: public Sprite
=======
using namespace std;

class StickMan:public Sprite
>>>>>>> bd3235fd8f9d43035a7f0c84e656a8b77640f750
{
public:
	static StickMan *GetInstance();

<<<<<<< HEAD
	static void DestoryInstance();
	
	static void onKeyUp();
	//static void onKeyDown();
	//Sprite* GetStickMan();
private:
	
	//~StickMan() { DestoryInstance(); }
	static StickMan* m_Instance;
=======
	static void DestoryInstance() {
		if (m_Instance != NULL) {
			delete m_Instance;
			m_Instance = NULL;
		}
	}

	//Sprite* GetStickMan();
private:
	StickMan();
	~StickMan() { DestoryInstance(); }
	static StickMan *m_Instance;
>>>>>>> bd3235fd8f9d43035a7f0c84e656a8b77640f750
	//Sprite* stickMan;
};
