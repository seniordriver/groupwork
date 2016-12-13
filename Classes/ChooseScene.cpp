#include "ChooseScene.h"


Scene* ChooseScene::createScene()
{

	auto scene = Scene::create();
	auto layer = ChooseScene::create();
	scene->addChild(layer);
	return scene;
}

bool ChooseScene::init()
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

void ChooseScene::normMenuCallback(Ref* pSender)
{
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	Director::getInstance()->replaceScene(GameScene::createScene());
	GameScene::speed = 2.5;
}

void ChooseScene::hardMenuCallback(Ref* pSender)
{
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	Director::getInstance()->replaceScene(GameScene::createScene());
	GameScene::speed=1.5;
}
