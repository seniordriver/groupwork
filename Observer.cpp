#include "Observer.h"
#include "GameScene.h"


void Observer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)                               //GameScene.cpp line 172
	{
	case(EventKeyboard::KeyCode::KEY_UP_ARROW):
		stickman_jump();                           //control the stickman .Prepare to define 
		break;
	case(EventKeyboard::KeyCode::KEY_DOWN_ARROW):
		stickman_slide();
		break;
	case(EventKeyboard::KeyCode::KEY_ESCAPE):
		stickman_reset();
		break;
	}

	switch (keyCode)                               //newScene.cpp line 69  
	{                                              //control the scene(??)
	case(EventKeyboard::KeyCode::KEY_ESCAPE):
		//Director::getInstance()->replaceScene(GameScene::createScene());
		//Director::getInstance()->resume();
		break;
	case(EventKeyboard::KeyCode::KEY_BACKSPACE):
		//Director::getInstance()->replaceScene(WelcomeScene::createScene());
		//Director::getInstance()->resume();
		break;
	}

}


void Observer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)//GameScene.cpp line 202
{
	scene_reset();// control the scene.Prepare to define
}

void Observer::MenuClicked()
{
	if(clicked){}
}
void Observer::BackClicked()
{
	if(clicked){}
}
