#pragma once
#include "cocos2d.h"  
USING_NS_CC;
class BaseLayer :public cocos2d::Layer
{
public:
	BaseLayer(void);
	virtual ~BaseLayer(void);

	void appear();
	void disappear();
	void close();
};
