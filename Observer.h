#pragma once
#include "GameScene.h"
#include "newScene.h"
#include"ChooseScene.h"
#include"SettingScene.h"
class Observer
{
public:
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event * event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	void MenuClicked();
	void BackClicked();
	void Stickman_control()
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
};

