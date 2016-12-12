#include "Observer.h"
#include "GameScene.h"
#include "newScene.h"
#include"ChooseScene.h"
#include"SettingScene.h"



{
<<<<<<< HEAD
	//Stickman_control();
=======
	Stickman_control(/*EventKeyboard::KeyCode keyCode, Event* event*/);  //gamescene.cpp line172
	newScene(/*EventKeyboard::KeyCode keyCode, Event* event*/);           //Newscene.cpp  line 69
>>>>>>> origin/master
}

{
<<<<<<< HEAD
	//scene_reset();// control the scene
	
}

void Observer::MenuClicked()
{
	//if(clicked){}
}
void Observer::BackClicked()
{
	//if(clicked){}
=======
	scene_reset();// control the scene
}

void Observer::Clicked()
{
	menuCloseCallback(/*Ref* pSender*/);                                 //gamescene.cpp line 212
	togglemenu(/*Object* psender*/);                                     //gamescene.cpp line 218

>>>>>>> origin/master
}

