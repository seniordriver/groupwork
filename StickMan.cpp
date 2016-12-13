#include "StickMan.h"
<<<<<<< HEAD
#pragma once

=======

StickMan::StickMan() {
	Sprite::create("stick man2.png");
}
>>>>>>> bd3235fd8f9d43035a7f0c84e656a8b77640f750

StickMan* StickMan::GetInstance() {
	if (m_Instance == NULL)
	{
<<<<<<< HEAD
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
=======
		m_Instance = new StickMan();
	}
	return m_Instance;
}

Sprite* StickMan::GetStickMan() {
	//return stickMan;
	return 0;
}

StickMan *StickMan::m_Instance = NULL;
>>>>>>> bd3235fd8f9d43035a7f0c84e656a8b77640f750
