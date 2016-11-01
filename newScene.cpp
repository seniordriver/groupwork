#include "newScene.h"
#include "GameScene.h"
#include "WelcomeScene.h"

USING_NS_CC;

Scene* newScene::createScene()
{
	auto scene = Scene::create();
	auto layer = newScene::create();
	scene->addChild(layer);
	return scene;
}

bool newScene::init()
{

	if (!Layer::init())
	{
		return false;
	}
	Director::getInstance();
	Sprite* back = Sprite::create("background1.png");
	back->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	back->setPosition(Vec2(0, 0));
	this->addChild(back);
	auto label = Label::createWithSystemFont("restart", "Papyrus", 60);
	label->setPosition(250, 450);
	label->setColor(Color3B(0, 0,255));
	this->addChild(label);
	auto label1 = Label::createWithSystemFont("back to menu", "Papyrus", 60);
	label1->setPosition(600, 450);
	label1->setColor(Color3B(0, 0, 255));
	this->addChild(label1);
	auto label2 = Label::createWithSystemFont("Press ESC or touch to restart" , "Papyrus", 60);
	label2->setPosition(450, 180);
	label2->setColor(Color3B(255, 0, 0));
	this->addChild(label2);
	auto label3 = Label::createWithSystemFont("Press Backspace or touch to back", "Papyrus", 60);
	label3->setPosition(450, 90);
	label3->setColor(Color3B(255, 0, 0));
	this->addChild(label3);
	auto restart = MenuItemImage::create("restart1.png", "restart1.png", CC_CALLBACK_1(newScene::menustart, this));
	auto arrow = MenuItemImage::create("back1.png", "back1.png", CC_CALLBACK_1(newScene::menuback, this));
	auto menu = Menu::create(restart, arrow, NULL);
	menu->setPosition(400, 300);
	menu->alignItemsHorizontallyWithPadding(150);
	this->addChild(menu, 3);

	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(newScene::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
}

void newScene::menustart(cocos2d::Ref* psender)
{
	Director::getInstance()->replaceScene(GameScene::createScene());
	Director::getInstance()->resume();
}
void newScene::menuback(cocos2d::Ref* psender)
{
	Director::getInstance()->replaceScene(WelcomeScene::createScene());
	Director::getInstance()->resume();
}

void newScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
	case(EventKeyboard::KeyCode::KEY_ESCAPE) :
		Director::getInstance()->replaceScene(GameScene::createScene());
		Director::getInstance()->resume();
		break;
	case(EventKeyboard::KeyCode::KEY_BACKSPACE):
		Director::getInstance()->replaceScene(WelcomeScene::createScene());
		Director::getInstance()->resume();
		break;
	}
}