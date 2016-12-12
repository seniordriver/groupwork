#ifndef __NEWSCENE_SCENE_H__
#define __NEWSCENE_SCENE_H__

#include "cocos2d.h"
#include "ObjectDefine.h"

USING_NS_CC;


class newScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(newScene);

};



#endif // __NEWSCENE_SCENE_H__
