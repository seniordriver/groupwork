#pragma once
#include "GameScene.h"
#include "newScene.h"
#include"ChooseScene.h"
#include"SettingScene.h"

class Observer
{
public:
	void onKeyPressed();
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	void Clicked();
	void Stickman_control(EventKeyboard::KeyCode keyCode, Event* event)
	{
		auto move = MoveBy::create(0.4, Vec2(0, -200));
		if (!checksprite(back))
		{
			switch (keyCode)
			{
			case(EventKeyboard::KeyCode::KEY_UP_ARROW):
				show->stopAllActions();
				show->runAction(RepeatForever::create(jump()));
				back->runAction(Sequence::create(move, move->reverse(), nullptr));
				for (int i = 0; i < sprite.size(); i++)
				{
					sprite.at(i)->runAction(Sequence::create(move->clone()->clone(), move->clone()->clone()->reverse(), nullptr));
				}
				break;
			case(EventKeyboard::KeyCode::KEY_DOWN_ARROW):
				show->stopAllActions();
				show->runAction(Repeat::create(slide(), 4));
				break;
			case(EventKeyboard::KeyCode::KEY_ESCAPE):
				CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
				Director::getInstance()->pause();
				Director::getInstance()->getEventDispatcher()->pauseEventListenersForTarget(this);
				paures->setSelectedIndex(1);
				break;
			}
		}
	}
	void scene_reset() 
	{
		auto move = MoveTo::create(2, Point(visibleSize.width * 500 / 1024, visibleSize.height / 2 + origin.y - 57));
		show->stopAllActions();
		show->runAction(RepeatForever::create(Spawn::create(Repeat::create(run(), 9), move, nullptr)));
	}
	void menuCloseCallback(Ref* pSender) 
	{
		SimpleAudioEngine::getInstance()->end();
		Director::getInstance()->replaceScene(newScene::createScene());
	}
	void togglemenu(Object* psender)//2
	{
		MenuItemToggle* temp = (MenuItemToggle*)psender;
		if (temp->getSelectedIndex() == 1)
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
			Director::getInstance()->pause();
			Director::getInstance()->getEventDispatcher()->pauseEventListenersForTarget(this);
		}
		else
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
			Director::getInstance()->resume();
			Director::getInstance()->getEventDispatcher()->resumeEventListenersForTarget(this);
		}
	}
	void normMenuCallback(Ref* pSender)
	{
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		Director::getInstance()->replaceScene(GameScene::createScene());
		GameScene::speed = 2.5;
	}
	//ChooseScene.cpp line 39
	void hardMenuCallback(Ref* pSender)
	{
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
		Director::getInstance()->replaceScene(GameScene::createScene());
		GameScene::speed = 1.5;
	}
	//ChooseScene.cpp line 46
	bool init()
	{
		if (!Layer::init())
		{
			return false;
		}

		Label* labelSingle = Label::create("Normal", "Papyrus", 60);
		auto singleMenuItem = MenuItemLabel::create(
			labelSingle,
			CC_CALLBACK_1(ChooseScene::normMenuCallback, this));

		Label* labelDouble = Label::create("Hard", "Papyrus", 60);
		auto doubleMenuItem = MenuItemLabel::create(
			labelDouble,
			CC_CALLBACK_1(ChooseScene::hardMenuCallback, this));


		auto startMenu = Menu::create(singleMenuItem, doubleMenuItem, NULL);
		startMenu->setPosition(visibleSize.width / 2, visibleSize.height / 2);
		startMenu->alignItemsVertically();
		this->addChild(startMenu);

		return true;
	}                                                            
	//ChooseScene.cpp line 13
	void newScene(EventKeyboard::KeyCode keyCode, Event* event)
	{
		switch (keyCode)
		{
		case(EventKeyboard::KeyCode::KEY_ESCAPE):
			Director::getInstance()->replaceScene(GameScene::createScene());
			Director::getInstance()->resume();
			break;
		case(EventKeyboard::KeyCode::KEY_BACKSPACE):
			Director::getInstance()->replaceScene(WelcomeScene::createScene());
			Director::getInstance()->resume();
			break;
		}
	}
};

