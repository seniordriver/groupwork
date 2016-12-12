#include"SettingScene.h"
#include"ObjectDefine.h"

Scene* SettingScene::createScene()
{
	auto scene = Scene::create();
	auto layer = SettingScene::create();
	scene->addChild(layer);
	return scene;
}

bool SettingScene::init()
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

	toggleItem->setPosition(Vec2(100,100));
	auto musicMenu = Menu::create(toggleItem, NULL);
	musicMenu->setPosition(Point::ZERO);
	this->addChild(musicMenu);
	
	Label* labelSetting = Label::create("back", "Papyrus", 60);
	auto settingMenuItem = MenuItemLabel::create(labelSetting,CC_CALLBACK_1(SettingScene::menuWelCallback, this));
	settingMenuItem->setPosition(visibleSize.width-labelSetting->getContentSize().width ,100);
	auto settingMenu = Menu::create(settingMenuItem, NULL);
	settingMenu->setPosition(Point::ZERO);
	this->addChild(settingMenu);

	auto label = Label::create("Music :", "Papyrus", 60);
	label->setPosition(200, 400);
	this->addChild(label);
	Label* plus = Label::create("Celebrate", "Papyrus", 60);
	Label* minus = Label::create("Origin", "Papyrus", 60);
	auto addmenu = MenuItemLabel::create(plus, CC_CALLBACK_1(SettingScene::menuaddhard, this));
	addmenu->setPosition(visibleSize.width/2, 400);
	auto removemenu = MenuItemLabel::create(minus, CC_CALLBACK_1(SettingScene::menuremhard, this));
	removemenu->setPosition(visibleSize.width / 2+300, 400);
	auto menu = Menu::create(addmenu,removemenu, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
	return true;
}

void SettingScene::menuMusicCallback(cocos2d::Ref* pSender)
{	
	MusicControl::changeisStop();
	MusicControl::playBackgroundMusic();
}

void SettingScene::menuWelCallback(cocos2d::Ref* psender)
{
	Director::getInstance()->popScene();
}
void SettingScene::menuaddhard(cocos2d::Ref* pSender)
{
	//SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	//SimpleAudioEngine::sharedEngine()->playBackgroundMusic("celebrate.mp3", true);
	int a = 2;
	MusicControl::changemusic(a);
	MusicControl::playBackgroundMusic();
}

void SettingScene::menuremhard(cocos2d::Ref* psender)
{
	//SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	//SimpleAudioEngine::sharedEngine()->playBackgroundMusic("bgm.wav", true);
	int a = 1;
	MusicControl::changemusic(a);
	MusicControl::playBackgroundMusic();
}

