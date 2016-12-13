#include "Observer.h"
#include "GameScene.h"
#include "newScene.h"
#include"ChooseScene.h"
#include"SettingScene.h"



void Observer::onKeyPressed()
{
	Stickman_control(/*EventKeyboard::KeyCode keyCode, Event* event*/);  //gamescene.cpp line172
	newScene(/*EventKeyboard::KeyCode keyCode, Event* event*/);           //Newscene.cpp  line 69
}

void Observer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) //gamescene.cpp line202
{
	scene_reset();// control the scene
}

void Observer::Clicked()
{
	menuCloseCallback(/*Ref* pSender*/);                                 //gamescene.cpp line 212
	togglemenu(/*Object* psender*/);                                     //gamescene.cpp line 218

}

