#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ObjectDefine.h"
#include "MusicControl.h"
using namespace std;

class StickMan:public Sprite
{
public:
	static StickMan *GetInstance();

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
	//Sprite* stickMan;
};
