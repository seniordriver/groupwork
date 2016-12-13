#include "WelcomeScene.h"
#include "GameScene.h"
#include "SettingScene.h"
#include "ObjectDefine.h"
#include "ChooseScene.h"
#include "SimpleAudioEngine.h"
#include"newScene.h"
#include"Contentlayer.h"
USING_NS_CC;
using namespace CocosDenshion;

Scene* WelcomeScene::createScene()
{

	auto scene = Scene::create();
	auto layer = WelcomeScene::create();
	scene->addChild(layer);
	return scene;
}

bool WelcomeScene::init()
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
	helpMenuItem->setPosition(visibleSize.width / 2, visibleSize.height / 2-20);
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

void WelcomeScene::startMenuCallback(Ref* pSender)
{
	Director::getInstance()->replaceScene(
		TransitionSlideInT::create(0.5f, ChooseScene::createScene()));

}

void WelcomeScene::settingMenuCallback(Ref* pSender)
{
	Director::getInstance()->pushScene(SettingScene::createScene());
}

void WelcomeScene::helpMenuCallback(Ref* pSender)
{
	Director::getInstance()->pushScene(ContentLayer::createScene());
}

Animate* run1()
{
	auto animation1 = Animation::create();
	animation1->addSpriteFrameWithFileName("stick man.png");
	animation1->addSpriteFrameWithFileName("stick man1.png");
	animation1->addSpriteFrameWithFileName("stick man2.png");
	animation1->addSpriteFrameWithFileName("stick man1.png");
	animation1->setDelayPerUnit(1.0f / 10.0f);
	auto run = Animate::create(animation1);
	return run;
}