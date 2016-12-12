#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    



    // add "HelloWorld" splash screen"
	auto show = Sprite::create();
	auto show1 = Sprite::create();
	auto back = Sprite::create("background.png");
	auto sprite = Sprite::create("stick man2.png");
    // position the sprite on the center of the screen
   show->setPosition(Vec2(sprite->getContentSize().width/2+origin.x, visibleSize.height/3 + origin.y));
   show1->setPosition(Vec2(sprite->getContentSize().width / 2 + origin.x, visibleSize.height / 3 + origin.y));
   back->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
   back->setPosition(Vec2(0,0));
  /* auto scale = ScaleBy::create(visibleSize.width / back->getContentSize().width, visibleSize.height / back->getContentSize().height);
   back->runAction(scale);*/
	

    // add the sprite as a child to this layer
   this->addChild(back);
	this->addChild(show);
	this->addChild(show1);
	auto move1 = MoveBy::create(3, Vec2(-512,0));
	back->runAction(RepeatForever::create(Sequence::create(move1,move1->reverse(),nullptr)));
	auto animation = Animation::create();
	animation->addSpriteFrameWithFileName("stick man2.png");
	animation->addSpriteFrameWithFileName("stick man3.png");
	animation->addSpriteFrameWithFileName("stick man3.png");
	animation->addSpriteFrameWithFileName("stick man4.png");
	animation->addSpriteFrameWithFileName("stick man4.png");
	animation->addSpriteFrameWithFileName("stick man3.png");
	animation->addSpriteFrameWithFileName("stick man2.png");
	animation->addSpriteFrameWithFileName("stick man1.png");
	animation->setDelayPerUnit(1.0f / 10.0f);
	auto animation1 = Animation::create();
	animation1->addSpriteFrameWithFileName("stick man.png");
	animation1->addSpriteFrameWithFileName("stick man1.png");
	animation1->addSpriteFrameWithFileName("stick man2.png");
	animation1->addSpriteFrameWithFileName("stick man1.png");
	animation1->setDelayPerUnit(1.0f / 10.0f);
	auto animation2 = Animation::create();
	animation2->addSpriteFrameWithFileName("stick man.png");
	animation2->addSpriteFrameWithFileName("stick man1.png");
	animation2->addSpriteFrameWithFileName("stick man2.png");
	animation2->addSpriteFrameWithFileName("stick mans.png");
	animation2->addSpriteFrameWithFileName("stick mans.png");
	animation2->addSpriteFrameWithFileName("stick mans.png");
	animation2->addSpriteFrameWithFileName("stick mans.png");
	animation2->addSpriteFrameWithFileName("stick mans.png");
	animation2->addSpriteFrameWithFileName("stick man2.png");
	animation2->addSpriteFrameWithFileName("stick man1.png");
	animation2->setDelayPerUnit(1.0f / 10.0f);

	auto ani = Animate::create(animation);
	auto ani1= Animate::create(animation1);
	auto ani2 = Animate::create(animation2);
	auto move = MoveTo::create(3, Point(500, visibleSize.height / 3 + origin.y));
	
	auto jump = Repeat::create(JumpBy::create(1, Vec2(30, 0), 60, 4), 5);
	//show->runAction((RepeatForever::create(ani1)));
	/*for (int i = 0; i < 10; i++)
	{
		show->runAction(Repeat::create(ani1,i+1));
	}*/
	show->runAction(RepeatForever::create(Spawn::create(Repeat::create(ani1,9),Sequence::create(move, Spawn::create(ani,JumpBy::create(0.8, Vec2(0, 0), 100, 1),nullptr),ani2, nullptr),nullptr)));
    
    return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
