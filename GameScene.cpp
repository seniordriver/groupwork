#include "GameScene.h"
#include "newScene.h"
#include"ChooseScene.h"
#include"SettingScene.h"
//#include"Observer.h"

USING_NS_CC;

Observer exam;
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
		
		int a=0;
		if (ChooseScene::dif == 2){ a = rand() % 2; }
		if (a == 0) {
			auto b = factoryNormal->create();
			auto s = b->GetSprite();
			//sprite.pushBack(s);
			sprite->Push(s);
			//exam.listener1.pushBack(s);
			this->addChild(s, 3);
		}
		else {
			auto b = factoryFast->create();
			auto s = b->GetSprite();
			//sprite.pushBack(s);
			sprite->Push(s);
			//exam.listener1.pushBack(s);
			this->addChild(s, 3);
		}
		//auto s = Sprite::create("enemy.png");
		//auto b = Factory::create();
		//auto b = factoryNormal->create();
		//auto b = factoryFast->create();
		//auto s = b->GetSprite();
		/*int a = rand() % 150 + 280;
		auto m1 = MoveBy::create(speed, Vec2(-1050, 0));
		s->setPosition(Vec2(1000, a));
		sprite.pushBack(s);
		auto rotate = RotateBy::create(1, 360);
		s->runAction(Spawn::create(Repeat::create(rotate, 4), m1, nullptr));*/
		//sprite.pushBack(s);
		//this->addChild(s, 3);
	}
	Iterator* iter = sprite->CreateIterator();
	int i = 0;
	for (int i = 2; i < exam.listener1.size();)
	{
		exam.listener1.erase(exam.listener1.size()-1);
	}
	while (!iter->IsEnd())
	{
		
		//CCLog("%d\n", i);
		//CCLog("count %d, m_cnt %d", sprite->Count(), iter->m_cnt);
		//Sprite* enemy = sprite->Pop(i);
		Sprite* enemy = iter->GetCur();
		exam.listener1.pushBack(enemy);
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
			if (i % 15 == 0)
				score->setString(StringUtils::format("SCORE : %d", count));
			highscore = UserDefault::sharedUserDefault()->getIntegerForKey("integer");
			high->setString(StringUtils::format("HIGH SCORE : %d", highscore));
		}
		if (enemy->getPosition().x < origin.x - enemy->getContentSize().width / 2)
		{
			iter->Erase();
			//exam.listener1.eraseObject(enemy);
			this->removeChild(enemy, 1);
		}
		//cout << iter->GetCur() << " is ok" << endl;
		iter->Next();
		i++;
	}
	//for (int i = 0; i < sprite.size(); i++)
	//{
	//	Sprite* enemy = sprite.at(i);
	//	if (enemy->getBoundingBox().intersectsRect(show->getBoundingBox()))
	//	{


	//		SimpleAudioEngine::getInstance()->end();
	//		if (!MusicControl::getisStop())
	//			SimpleAudioEngine::getInstance()->playEffect("bge.wav");
	//		Director::getInstance()->replaceScene(newScene::createScene());
	//		isHaveSaveFile();
	//		
	//	}
	//	else
	//	{
	//		if (i%15==0)
	//		score->setString(StringUtils::format("SCORE : %d", count));
	//		highscore = UserDefault::sharedUserDefault()->getIntegerForKey("integer");
	//		high->setString(StringUtils::format("HIGH SCORE : %d", highscore));
	//	}
	//}
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
	exam.listener1.clear();
	exam.listener2.clear();
	StickMan::DestoryInstance();
	GameScene::show = StickMan::GetInstance();
	
	//a.listener2.pushBack(show);
	//StickMan* stickMan = StickMan::GetInstance();
	//Sprite* show = stickMan->GetStickMan();
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
	if(exam.listener1.empty())exam.listener1.pushBack(show);
	if (exam.listener2.empty())exam.listener2.pushBack(show);

	back->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	back->setPosition(Vec2(0, 0));
	exam.listener1.pushBack(back);
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
			//show->stopAllActions();
			//show->runAction(RepeatForever::create(jump()));
			exam.KeyUp();
			//for (int i = 0; i < sprite->Count(); i++)
			//{
			//	sprite->Pop(i)->runAction(Sequence::create(move->clone()->clone(), move->clone()->clone()->reverse(), nullptr));
			//}
			//back->runAction(Sequence::create(move, move->reverse(), nullptr));
			break;
		case(EventKeyboard::KeyCode::KEY_DOWN_ARROW) :
			//show->stopAllActions();
			exam.KeyDown();
			//show->runAction(Repeat::create(slide(),4));
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