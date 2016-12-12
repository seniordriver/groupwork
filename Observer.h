#pragma once
#include "GameScene.h"
#include "newScene.h"
#include"ChooseScene.h"
#include"SettingScene.h"
#include "GameScene.h"
class Observer
{
public:
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	void MenuClicked();
	void BackClicked();
	
};

