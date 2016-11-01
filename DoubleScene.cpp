
#include "DoubleScene.h"
#include "newScene.h"

USING_NS_CC;


//
//bool DoubleScene::isHaveSaveFile1()
//{
//	if (!CCUserDefault::sharedUserDefault()->getBoolForKey("isHaveSaveFileXml1"))
//	{
//		CCUserDefault::sharedUserDefault()->setBoolForKey("isHaveSaveFileXml1", true);
//		CCUserDefault::sharedUserDefault()->flush();
//		CCUserDefault::sharedUserDefault()->setIntegerForKey("integer1", 0);
//		CCUserDefault::sharedUserDefault()->setIntegerForKey("integer1", count1);
//		return false;
//	}
//	else
//	{
//		if (count1 > CCUserDefault::sharedUserDefault()->getIntegerForKey("integer1"))
//			CCUserDefault::sharedUserDefault()->setIntegerForKey("integer1", count1);
//		return true;
//	}
//}
//
//bool DoubleScene::isHaveSaveFile2()
//{
//	if (!CCUserDefault::sharedUserDefault()->getBoolForKey("isHaveSaveFileXml2"))
//	{
//		CCUserDefault::sharedUserDefault()->setBoolForKey("isHaveSaveFileXml2", true);
//		CCUserDefault::sharedUserDefault()->flush();
//		CCUserDefault::sharedUserDefault()->setIntegerForKey("integer2", 0);
//		CCUserDefault::sharedUserDefault()->setIntegerForKey("integer2", count2);
//		return false;
//	}
//	else
//	{
//		if (count2 > CCUserDefault::sharedUserDefault()->getIntegerForKey("integer2"))
//			CCUserDefault::sharedUserDefault()->setIntegerForKey("integer2", count2);
//		return true;
//	}
//}

Animate*DoubleScene::jump()
{
	auto animation = Animation::create();
	animation->addSpriteFrameWithFileName("stick man4.png");
	animation->addSpriteFrameWithFileName("stick man3.png");
	animation->addSpriteFrameWithFileName("stick man3.png");
	animation->setDelayPerUnit(1.0f / 10.0f);
	auto jump = Animate::create(animation);
	return jump;
}

Animate* DoubleScene::run()
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

Animate* DoubleScene::slide()
{
	auto animation2 = Animation::create();
	animation2->addSpriteFrameWithFileName("stick mans.png");
	animation2->addSpriteFrameWithFileName("stick mans.png");
	animation2->addSpriteFrameWithFileName("stick mans.png");
	animation2->addSpriteFrameWithFileName("stick mans.png");
	animation2->setDelayPerUnit(1.0f / 10.0f);
	auto slide = Animate::create(animation2);
	return slide;
}

void DoubleScene::collide1(float dt)
{
	if ((count1++) % 100 == 0)
	{
		auto s = Sprite::create("enemy.png");
		int a = rand() % 150 + 100;
		float b = rand() % 10 / 1000 + 1.8;
		auto m1 = MoveBy::create(b, Vec2(-1050, 0));
		s->setPosition(Vec2(1000, a));
		sprite1.pushBack(s);
		auto rotate = RotateBy::create(1, 90);
		s->runAction(Spawn::create(Repeat::create(rotate, 20), m1, nullptr));
		this->addChild(s, 3);
	}
	for (int i = 0; i < sprite1.size(); i++)
	{
		Sprite* enemy = sprite1.at(i);
		if (enemy->getBoundingBox().intersectsRect(show->getBoundingBox()))
		{
			SimpleAudioEngine::getInstance()->end();
			SimpleAudioEngine::getInstance()->playEffect("bge.wav");
			Director::getInstance()->replaceScene(newScene::createScene());
			//isHaveSaveFile1();

		}
		else
		{
			if (i % 15 == 0)
				score1->setString(StringUtils::format("SCORE : %d", count1));
			highscore1 = UserDefault::sharedUserDefault()->getIntegerForKey("integer1");
			high1->setString(StringUtils::format("HIGH SCORE : %d", highscore1));
		}
	}
}
void DoubleScene::collide2(float dt)
{
	if ((count2++) % 100 == 0)
	{
		auto s = Sprite::create("enemy.png");
		int a = rand() % 150 +460;
		float b = rand() % 10 / 1000 + 1.8;
		auto m1 = MoveBy::create(b, Vec2(-1050, 0));
		s->setPosition(Vec2(1000, a));
		sprite2.pushBack(s);
		auto rotate = RotateBy::create(1, 90);
		s->runAction(Spawn::create(Repeat::create(rotate, 20), m1, nullptr));
		this->addChild(s, 3);
	}
	for (int i = 0; i < sprite2.size(); i++)
	{
		Sprite* enemy = sprite2.at(i);
		if (enemy->getBoundingBox().intersectsRect(show->getBoundingBox()))
		{
			SimpleAudioEngine::getInstance()->end();
			SimpleAudioEngine::getInstance()->playEffect("bge.wav");
			Director::getInstance()->replaceScene(newScene1::createScene());
			//isHaveSaveFile2();
		}
		else
		{
			if (i % 15 == 0)
				score2->setString(StringUtils::format("SCORE : %d", count2));
			highscore2 = UserDefault::sharedUserDefault()->getIntegerForKey("integer2");
			high2->setString(StringUtils::format("HIGH SCORE : %d", highscore2));
		}
	}
}
bool DoubleScene::checksprite1(Sprite* check)
{
	Vec2 bg = check->getPosition();
	if (bg.y < 0){ return true; }
	else{ return false; }
}
bool DoubleScene::checksprite2(Sprite* check)
{
	Vec2 bg = check->getPosition();
	if (bg.y < visibleSize.height/2){ return true; }
	else{ return false; }
}


Scene* DoubleScene::createScene()
{
	auto scene = Scene::create();
	auto layer = DoubleScene::create();
	scene->addChild(layer);
	return scene;
}


bool DoubleScene::init()
{

	if (!Layer::init())
	{
		return false;
	}
	Director::getInstance();
	auto restart = MenuItemImage::create("restart.png", "restart2.png", CC_CALLBACK_1(DoubleScene::menuCloseCallback, this));

	paures = MenuItemToggle::createWithTarget(this, menu_selector(DoubleScene::togglemenu), MenuItemImage::create("stop.png", "stop2.png"), MenuItemImage::create("resume.png", "resume2.png"), NULL);
	if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
	{
		paures->setSelectedIndex(1);
	}
	else
	{
		paures->setSelectedIndex(0);
	}

	auto menu = Menu::create(paures, restart, NULL);
	menu->alignItemsVerticallyWithPadding(20);
	menu->setPosition(Vec2(800, 600));
	this->addChild(menu, 1);

	SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.wav", true);
	score1 = Label::createWithSystemFont("0", "Arial", 20);
	score1->setPosition(200, 650);
	score1->setColor(Color3B(0, 0, 0));
	this->addChild(score1, 3);
	score2 = Label::createWithSystemFont("0", "Arial", 20);
	score2->setPosition(200, 350);
	score2->setColor(Color3B(0, 0, 0));
	this->addChild(score2, 3);
	high1 = Label::createWithSystemFont("0", "Arial", 20);
	high1->setPosition(200, 600);
	high1->setColor(Color3B(0, 0, 0));
	this->addChild(high1, 3);
	high2 = Label::createWithSystemFont("0", "Arial", 20);
	high2->setPosition(200, 300);
	high2->setColor(Color3B(0, 0, 0));
	this->addChild(high2, 3);


	show->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	show->setPosition(Vec2(show->getContentSize().width + origin.x, visibleSize.height *2/ 3+ origin.y - show->getContentSize().height / 2));
	show2->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	show2->setPosition(Vec2(show->getContentSize().width + origin.x, visibleSize.height *1/ 3 + origin.y - show->getContentSize().height / 2));

	back2->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	back2->setPosition(Vec2(0, 0));
	back->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	back->setPosition(0,visibleSize.height/2);

	this->addChild(back);
	this->addChild(show, 3);
	this->addChild(back2);
	this->addChild(show2, 3);

	auto move1 = MoveTo::create(3, Point(visibleSize.width * 500 / 1024, visibleSize.height * 2 / 3 + origin.y - show->getContentSize().height / 2));
	show->runAction(RepeatForever::create(Spawn::create(Repeat::create(run(), 9), move1, nullptr)));
	auto move2 = MoveTo::create(3, Point(visibleSize.width * 500 / 1024, visibleSize.height * 1 / 3 + origin.y - show->getContentSize().height / 2));
	show2->runAction(RepeatForever::create(Spawn::create(Repeat::create(run(), 9), move2, nullptr)));

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(DoubleScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(DoubleScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	this->schedule(schedule_selector(DoubleScene::collide1));
	this->schedule(schedule_selector(DoubleScene::collide2));
	return true;
}

void DoubleScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	auto move = MoveBy::create(0.4, Vec2(0, -200));
	if (!checksprite1(back))
	{
		switch (keyCode)
		{
		case(EventKeyboard::KeyCode::KEY_UP_ARROW) :
			show->stopAllActions();
			show->runAction(RepeatForever::create(jump()));
			back->runAction(Sequence::create(move, move->reverse(), nullptr));
			for (int i = 0; i < sprite1.size(); i++)
			{
				sprite1.at(i)->runAction(Sequence::create(move->clone()->clone(), move->clone()->clone()->reverse(), nullptr));
			}
			break;
		case(EventKeyboard::KeyCode::KEY_DOWN_ARROW) :
			show->stopAllActions();
			show->runAction(Repeat::create(slide(), 4));
			break;
		case(EventKeyboard::KeyCode::KEY_ESCAPE) :
			CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
			Director::getInstance()->pause();
			Director::getInstance()->getEventDispatcher()->pauseEventListenersForTarget(this);
			paures->setSelectedIndex(1);
			break;
		}
	}
	if (!checksprite1(back))
	{
		switch (keyCode)
		{
		case(EventKeyboard::KeyCode::KEY_W) :
			show2->stopAllActions();
			show2->runAction(RepeatForever::create(jump()));
			back2->runAction(Sequence::create(move->clone, move->clone()->reverse(), nullptr));
			for (int i = 0; i < sprite2.size(); i++)
			{
				sprite2.at(i)->runAction(Sequence::create(move->clone()->clone(), move->clone()->clone()->reverse(), nullptr));
			}
			break;
		case(EventKeyboard::KeyCode::KEY_S) :
			show2->stopAllActions();
			show2->runAction(Repeat::create(slide(), 4));
			break;
		}
	}
}

void DoubleScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	auto move = MoveTo::create(2, Point(visibleSize.width * 500 / 1024, visibleSize.height / 2 + origin.y - 57));
	show->stopAllActions();
	show->runAction(RepeatForever::create(Spawn::create(Repeat::create(run(), 9), move, nullptr)));
	show2->stopAllActions();
	show2->runAction(RepeatForever::create(Spawn::create(Repeat::create(run()->clone(), 9), move, nullptr)));

}




void DoubleScene::menuCloseCallback(Ref* pSender)
{
	SimpleAudioEngine::getInstance()->end();
	Director::getInstance()->replaceScene(newScene::createScene());
}

void DoubleScene::togglemenu(Object* psender)
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





