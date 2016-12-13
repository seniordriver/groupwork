#include "BaseLayer.h"

BaseLayer::BaseLayer(void)
{
}

BaseLayer::~BaseLayer(void)
{
}

void BaseLayer::appear()
{
	//层弹出动画
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	this->setPosition(Point(origin.x + visibleSize.width / 2, origin.y - visibleSize.height / 2));
	auto moveTo = MoveTo::create(0.5, Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
	auto easeBounceOut = EaseBackOut::create(moveTo);
	this->runAction(easeBounceOut);
}

void BaseLayer::disappear()
{
	//消失动画，消失后移除自身
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();

	auto moveTo = MoveTo::create(0.5, Point(origin.x + visibleSize.width / 2, origin.y - visibleSize.height / 2));
	auto easeBounceIn = EaseBackIn::create(moveTo);
	Sequence* seq = Sequence::create(easeBounceIn, RemoveSelf::create(true), NULL);
	this->runAction(seq);
}

void BaseLayer::close()
{
	disappear();
}