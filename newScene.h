#ifndef __NEWSCENE_SCENE_H__
#define __NEWSCENE_SCENE_H__

#include "cocos2d.h"
#include"ObjectDefine.h"

USING_NS_CC;


class newScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void menustart(cocos2d::Ref* pSender);
	void menuback(cocos2d::Ref* pSender);

	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);


	CREATE_FUNC(newScene);

};

class newScene1 :public newScene
{
public:
	CREATE_FUNC(newScene1);
};



#endif // __NEWSCENE_SCENE_H__
