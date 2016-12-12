#include"newScene.h"

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
	auto label = Label::createWithSystemFont("restart", "Arial", 60);
	label->setPosition(250, 450);
	label->setColor(Color3B(0, 0, 0));
	this->addChild(label);
	auto label1 = Label::createWithSystemFont("back to menu", "Arial", 60);
	label1->setPosition(600, 450);
	label1->setColor(Color3B(0, 0, 0));
	this->addChild(label1);
	auto scale = ScaleBy::create(0.1, 3);
	auto arrow = Sprite::create("back.png");
	arrow->setPosition(600, 200);
	arrow->runAction(scale);
	this->addChild(arrow);


	return true;
}