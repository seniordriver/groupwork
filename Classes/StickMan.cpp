#include "StickMan.h"

StickMan::StickMan() {
	stickMan = Sprite::create("stick man2.png");
}

StickMan* StickMan::GetInstance() {
	if (m_Instance == NULL)
	{
		m_Instance = new StickMan();
	}
	return m_Instance;
}

Sprite* StickMan::GetStickMan() {
	return stickMan;
}

StickMan *StickMan::m_Instance = NULL;