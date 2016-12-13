#include "StickMan.h"
#pragma once


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

void StickMan::onKeyUp(){
	m_Instance->stopAllActions();
	//m_Instance->runAction(RepeatForever::create(GameScene::jump()));
}



//Sprite* StickMan::GetStickMan() {
	//return stickMan;
//}

StickMan* StickMan::m_Instance = NULL;
