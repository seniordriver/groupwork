#include "GameScene.h"
#include "newScene.h"
#include"ChooseScene.h"
#include"SettingScene.h"


USING_NS_CC;

double GameScene::speed = 2;
bool GameScene::isHaveSaveFile() 
{
	if (!CCUserDefault::sharedUserDefault()->getBoolForKey("isHaveSaveFileXml"))
	{
		CCUserDefault::sharedUserDefault()->setBoolForKey("isHaveSaveFileXml", true);
		CCUserDefault::sharedUserDefault()->flush();
		CCUserDefault::sharedUserDefault()->setIntegerForKey("integer", 0);
		CCUserDefault::sharedUserDefault()->setIntegerForKey("integer", count);
		return false;
	}
	else
	{
		if (count > CCUserDefault::sharedUserDefault()->getIntegerForKey("integer"))
			CCUserDefault::sharedUserDefault()->setIntegerForKey("integer", count );
		return true;
	}
}
Animate*GameScene:: jump()
{
	auto animation = Animation::create();
	animation->addSpriteFrameWithFileName("stick man4.png");
	animation->addSpriteFrameWithFileName("stick man3.png");
	animation->addSpriteFrameWithFileName("stick man3.png");
	animation->setDelayPerUnit(1.0f / 10.0f);
	auto jump = Animate::create(animation);
	return jump;
}

Animate* GameScene::run()
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

Animate* GameScene:: slide()
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

void GameScene::collide(float dt)
{
	if ((count++)% 100 == 0)
	{
		auto s = Sprite::create("enemy.png");
		int a = rand() % 150 + 280;
		auto m1 = MoveBy::create(speed, Vec2(-1050, 0));
		s->setPosition(Vec2(1000, a));
		sprite.pushBack(s);
		auto rotate = RotateBy::create(1, 360);
		s->runAction(Spawn::create(Repeat::create(rotate, 4), m1, nullptr));
		this->addChild(s, 3);
	}
	for (int i = 0; i < sprite.size(); i++)
	{
		Sprite* enemy = sprite.at(i);
		if (enemy->getBoundingBox().intersectsRect(show->getBoundingBox()))
		{
			SimpleAudioEngine::getInstance()->end();
			if (!MusicControl::getisStop())
				SimpleAudioEngine::getInstance()->playEffect("bge.wav");
			Director::getInstance()->replaceScene(newScene::createScene());
			isHaveSaveFile();
			
		}
		else
		{
			if (i%15==0)
			score->setString(StringUtils::format("SCORE : %d", count));
			highscore = UserDefault::sharedUserDefault()->getIntegerForKey("integer");
			high->setString(StringUtils::format("HIGH SCORE : %d", highscore));
		}
	}
}

bool GameScene::checksprite(Sprite* check)
{
	Vec2 bg = check->getPosition();
	if (bg.y < 0){ return true; }
	else{ return false; }
}


Scene* GameScene::createScene()
{
    auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}


bool GameScene::init()
{
	
	if (!Layer::init())
	{
		return false;
	}
	Director::getInstance();
	auto restart = MenuItemImage::create("restart.png","restart2.png",CC_CALLBACK_1(GameScene::menuCloseCallback, this));
	
	paures = MenuItemToggle::createWithTarget(this, menu_selector(GameScene::togglemenu), MenuItemImage::create("stop.png", "stop2.png"), MenuItemImage::create("resume.png", "resume2.png"), NULL);
	if (CocosDenshion::SimpleAudioEngine::getInstance()->isBackgroundMusicPlaying())
	{
		paures->setSelectedIndex(1);
	}
	else
	{
		paures->setSelectedIndex(0);
	}

	auto menu = Menu::create(paures,restart, NULL);
	menu->alignItemsVerticallyWithPadding(20);
	menu->setPosition(Vec2(800, 600));
	this->addChild(menu, 1);
	
	//SimpleAudioEngine::getInstance()->playBackgroundMusic("bgm.wav", true);
	MusicControl::playBackgroundMusic();

	score = Label::createWithSystemFont("0", "Arial", 32);
	score->setPosition(200, 600);
	score->setColor(Color3B(0,0,0));
	this->addChild(score, 3);
	high = Label::createWithSystemFont("0", "Arial", 32);
	high->setPosition(200, 550);
	high->setColor(Color3B(0, 0, 0));
	this->addChild(high, 3);


	show->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	show->setPosition(Vec2(show->getContentSize().width + origin.x, visibleSize.height / 2 + origin.y - show->getContentSize().height / 2));

	back->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	back->setPosition(Vec2(0, 0));

   this->addChild(back);
	this->addChild(show,3);
	
	auto move1 = MoveTo::create(3, Point(visibleSize.width * 500 / 1024, visibleSize.height / 2 + origin.y - 57));
	show->runAction(RepeatForever::create(Spawn::create(Repeat::create(run(), 9),move1,nullptr)));
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
		this->schedule(schedule_selector(GameScene::collide));

	return true;
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	auto move = MoveBy::create(0.4, Vec2(0, -200));
	if (!checksprite(back))
	{
		switch (keyCode)
		{
		case(EventKeyboard::KeyCode::KEY_UP_ARROW) :
			show->stopAllActions();
			show->runAction(RepeatForever::create(jump()));
			back->runAction(Sequence::create(move, move->reverse(), nullptr));
			for (int i = 0; i < sprite.size(); i++)
			{
				sprite.at(i)->runAction(Sequence::create(move->clone()->clone(), move->clone()->clone()->reverse(), nullptr));
			}
			break;
		case(EventKeyboard::KeyCode::KEY_DOWN_ARROW) :
			show->stopAllActions();
			show->runAction(Repeat::create(slide(),4));
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

void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	auto move = MoveTo::create(2, Point(visibleSize.width * 500 / 1024, visibleSize.height / 2 + origin.y - 57 ));
	show->stopAllActions();
	show->runAction(RepeatForever::create(Spawn::create(Repeat::create(run(), 9), move, nullptr)));
}
	



void GameScene::menuCloseCallback(Ref* pSender)
{
		SimpleAudioEngine::getInstance()->end();
		Director::getInstance()->replaceScene(newScene::createScene());
}

void GameScene::togglemenu(Object* psender)
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