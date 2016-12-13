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
	bool init_ChooseScene()
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
	//Newscene.cpp  line 69
	bool init_SettingScene()
	{
		if (!Layer::init())
		{
			return false;
		}

		//创建音乐开关
		MenuItemImage *_turnOn, *_turnOff;
		_turnOn = MenuItemImage::create(
			"button_voi_on.png",
			"button_voi_on.png");
		_turnOff = MenuItemImage::create(
			"button_voi_off.png",
			"button_voi_off.png");
		MenuItemToggle *toggleItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingScene::menuMusicCallback, this), _turnOn, _turnOff, NULL);

		toggleItem->setPosition(Vec2(100, 100));
		auto musicMenu = Menu::create(toggleItem, NULL);
		musicMenu->setPosition(Point::ZERO);
		this->addChild(musicMenu);

		Label* labelSetting = Label::create("back", "Papyrus", 60);
		auto settingMenuItem = MenuItemLabel::create(labelSetting, CC_CALLBACK_1(SettingScene::menuWelCallback, this));
		settingMenuItem->setPosition(visibleSize.width - labelSetting->getContentSize().width, 100);
		auto settingMenu = Menu::create(settingMenuItem, NULL);
		settingMenu->setPosition(Point::ZERO);
		this->addChild(settingMenu);

		auto label = Label::create("Music :", "Papyrus", 60);
		label->setPosition(200, 400);
		this->addChild(label);
		Label* plus = Label::create("Celebrate", "Papyrus", 60);
		Label* minus = Label::create("Origin", "Papyrus", 60);
		auto addmenu = MenuItemLabel::create(plus, CC_CALLBACK_1(SettingScene::menuaddhard, this));
		addmenu->setPosition(visibleSize.width / 2, 400);
		auto removemenu = MenuItemLabel::create(minus, CC_CALLBACK_1(SettingScene::menuremhard, this));
		removemenu->setPosition(visibleSize.width / 2 + 300, 400);
		auto menu = Menu::create(addmenu, removemenu, NULL);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu);
		return true;
	}
	//SettingScene.cpp line 12
	void menuMusicCallback(cocos2d::Ref* pSender)
	{
		MusicControl::changeisStop();
		MusicControl::playBackgroundMusic();
	}
	//SettingScene.cpp line 56
	void menuWelCallback(cocos2d::Ref* psender)
	{
		Director::getInstance()->popScene();
	}
	//SettingScene.cpp line 62
	void menuaddhard(cocos2d::Ref* pSender)
	{
		//SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		//SimpleAudioEngine::sharedEngine()->playBackgroundMusic("celebrate.mp3", true);
		int a = 2;
		MusicControl::changemusic(a);
		MusicControl::playBackgroundMusic();
	}
	//SettingScene.cpp line 66
	void menuremhard(cocos2d::Ref* psender)
	{
		//SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
		//SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bgm.wav", true);
		int a = 1;
		MusicControl::changemusic(a);
		MusicControl::playBackgroundMusic();
	}
	//SettingScene.cpp line 75
	bool init_WelcomeScene()
	{
		if (!Layer::init())
		{
			return false;
		}

		//SimpleAudioEngine::getInstance()->preloadBackgroundMusic(Music_File);
		//SimpleAudioEngine::getInstance()->playBackgroundMusic(Music_File, true);
		MusicControl::playBackgroundMusic();

		auto sprite = Sprite::create("background.png");
		sprite->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
		this->addChild(sprite);

		Label* labelStarting = Label::create("Start", "Papyrus", 50);
		labelStarting->setColor(Color3B(0, 255, 0));
		auto startMenuItem = MenuItemLabel::create(
			labelStarting,
			CC_CALLBACK_1(WelcomeScene::startMenuCallback, this));
		startMenuItem->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 120);
		auto startMenu = Menu::create(startMenuItem, NULL);
		startMenu->setPosition(Point::ZERO);
		this->addChild(startMenu);

		Label* labelSetting = Label::create("Setting", "Papyrus", 50);
		labelSetting->setColor(Color3B(0, 255, 0));
		auto settingMenuItem = MenuItemLabel::create(labelSetting, CC_CALLBACK_1(WelcomeScene::settingMenuCallback, this));
		settingMenuItem->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 50);
		auto settingMenu = Menu::create(settingMenuItem, NULL);
		settingMenu->setPosition(Point::ZERO);
		this->addChild(settingMenu);

		Label* labelHelp = Label::create("Help", "Papyrus", 50);
		labelHelp->setColor(Color3B(0, 255, 0));
		auto helpMenuItem = MenuItemLabel::create(labelHelp, CC_CALLBACK_1(WelcomeScene::helpMenuCallback, this));
		helpMenuItem->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 20);
		auto helpMenu = Menu::create(helpMenuItem, NULL);
		helpMenu->setPosition(Point::ZERO);
		this->addChild(helpMenu);

		auto title = Label::create("Stickman Run", "Papyrus", 100);
		title->setAnchorPoint(Vec2(0.5f, 0.5f));
		title->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 6 * 5));
		title->setColor(Color3B(0, 0, 0));
		this->addChild(title);

		Sprite *runner = Sprite::create("stick man2.png");
		runner->setPosition(Vec2(visibleSize.width - 1024, visibleSize.height / 2 - 128));
		auto move1 = MoveTo::create(3, Point(visibleSize.width / 2, visibleSize.height / 2 - 128));
		runner->runAction(RepeatForever::create(Spawn::create(Repeat::create(run1(), 9), move1, nullptr)));
		this->addChild(runner);

		return true;
	}
	//WelcomeScene.cpp line 21
	void startMenuCallback(Ref* pSender)
	{
		Director::getInstance()->replaceScene(
			TransitionSlideInT::create(0.5f, ChooseScene::createScene()));

	}
	//WelcomeScene.cpp line 77
	void settingMenuCallback(Ref* pSender)
	{
		Director::getInstance()->pushScene(SettingScene::createScene());
	}
	//WelcomeScene.cpp line 84
	void helpMenuCallback(Ref* pSender)
	{
		Director::getInstance()->pushScene(ContentLayer::createScene());
	}
	//WelcomeScene.cpp line 89
	//WelcomeScene.cpp line 
};

