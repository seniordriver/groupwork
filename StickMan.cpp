#include "StickMan.h"
USING_NS_CC;

StickMan* StickMan::GetInstance() {
	if (m_Instance == NULL)
	{
		 m_Instance = (StickMan*)Sprite::create("stick man2.png");
		//new StickMan();
	}
	return m_Instance;
}
void StickMan::DestoryInstance(){
	if (m_Instance != NULL) {
		delete m_Instance;
		m_Instance = NULL;
	}
}

//void StickMan::onKeyUp(){
	
	//m_Instance->stopAllActions();
	//m_Instance->runAction(RepeatForever::create(GameScene::jump()));
//}



Sprite* StickMan::GetStickMan() {
	stickMan = (Sprite*)m_Instance;
	return stickMan;
}

StickMan* StickMan::m_Instance = 0;