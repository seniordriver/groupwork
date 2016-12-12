

#include "Contentlayer.h"
#include "WelcomeScene.h"

// ①结构体
typedef struct _Controller
{
	// 菜单项名称
	const std::string itemName;
	// C++11中std::function，使用它可以实现类似函数指针的功能，这里是单击菜单项时返回的场景对象
	std::function<Scene*()> callback;
}Controller;



// 本例重点是测试单点触摸时的屏幕滑动，所以此处单击每一个菜单项时返回的都是WelcomeScene场景
Controller itemNames[] =
{
	{ "Helping Tips", []() { return WelcomeScene::createScene(); } },
	{ "I. use UP arrow & DOWN arrow ", [](){ return WelcomeScene::createScene(); } },
	{ "to JUMP or SLIDE", [](){ return WelcomeScene::createScene(); } },
	{ "II. press ESC to pause the game", [](){ return WelcomeScene::createScene(); } },
	{ "III. while you're in the pausing menu", [](){ return WelcomeScene::createScene(); } },
	{ "press ESC to restart", [](){ return WelcomeScene::createScene(); } },
	{ "press BACKSPACE to the main menu", [](){ return WelcomeScene::createScene(); } },
	{ "IV. background music : ", [](){ return WelcomeScene::createScene(); } },
	{ "Monster  Hunter", [](){ return WelcomeScene::createScene(); } },
	{ "V. STAFF : ", [](){ return WelcomeScene::createScene(); } },
	{ "XU Diwen", [](){ return WelcomeScene::createScene(); } },
	{ "with Wang Junjie, Zhong Zhenbin, Zhao xu", [](){ return WelcomeScene::createScene(); } },
	{ " ", [](){ return WelcomeScene::createScene(); } },
	{ " ", [](){ return WelcomeScene::createScene(); } },
	{ "PRESS ME(to main menu)                 ", [](){ return WelcomeScene::createScene(); } },
};

/*
sizeof操作符的作用是返回一个对象或类型名的长度。当sizeof作用于一个class 、struct时，返回这些类型对象所占字节数
②计算菜单项的数量
*/
static int itemCount = sizeof(itemNames) / sizeof(itemNames[0]);
// 每一个菜单项之间的间隔
#define LINE_SPACE  150

Scene* ContentLayer::createScene()
{
	// 创建一个场景对象，该对象将会由自动释放池管理内存的释放
	auto scene = Scene::create();

	// 创建层对象，该对象将会由自动释放池管理内存的释放
	auto layer = ContentLayer::create();

	// 将WelcomeScene层作为子节点添加到场景
	scene->addChild(layer);
		// 返回场景对象
		return scene;
}

bool ContentLayer::init()
{

	if (!Layer::init())
	{
		return false;
	}

	// 获得设备支持的可见OpenGL视图大小（即窗口大小）。
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// ③创建菜单
	_itemMenu = Menu::create();
	// 循环添加菜单项
	for (int i = 0; i < itemCount; ++i)
	{
		// 创建Label
		auto label = Label::createWithSystemFont(itemNames[i].itemName, "Papyrus", 48);
		// 创建menuItemLabel,触碰时调用menuCallback函数
		auto menuItem = MenuItemLabel::create(label, CC_CALLBACK_1(ContentLayer::menuCallback, this));
		// 设置tag，用于menuCallback中判断触碰的菜单在itemNames中的下标
		menuItem->setTag(i);
		// 将菜单项添加到菜单
		_itemMenu->addChild(menuItem);

		// 设置菜单项位置
		menuItem->setPosition(Vec2(visibleSize.width / 2, (visibleSize.height - (i + 1) * LINE_SPACE)));
	}
	_itemMenu->setPosition(Vec2::ZERO);
	// 将菜单添加为当前层的子节点
	this->addChild(_itemMenu, 1);

	// ④注册触碰监听器
	auto listener = EventListenerTouchOneByOne::create();
	// 设置是否向下传递触摸
	listener->setSwallowTouches(true);
	// 设置触碰开始时调用onTouchBegan函数
	listener->onTouchBegan = CC_CALLBACK_2(ContentLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(ContentLayer::moveBar, this);
	// 添加场景优先事件监听器。
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	sprite->setPosition(Vec2(visibleSize.width - sprite->getContentSize().width/2, visibleSize.height -sprite->getContentSize().height/2 ));
	this->addChild(sprite,2);
	return true;
}

// ⑤触碰开始的回调函数
bool ContentLayer::onTouchBegan(Touch* touch, Event* event)
{
	// 记录触碰的坐标
	_beginPos = touch->getLocation();
	return true;
}

void ContentLayer::moveBar(Touch* touch, Event  *event)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto touchLocation = touch->getLocation();
	float nextMoveY = touchLocation.y - _beginPos.y;
	auto curPos = _itemMenu->getPosition();
	// 下一个位置 = Vec2(菜单位置的x,菜单位置的y+触碰的偏移量)
	auto nextPos = Vec2(curPos.x, curPos.y + nextMoveY);
	// 如果nextPos的y < 0，即滚动到最前面的菜单
	if (nextPos.y < 0.0f)
	{
		// 菜单设置为Vec2(0,0)位置
		_itemMenu->setPosition(Vec2::ZERO);
		return;
	}
	// 如果nextPos的y大于菜单的总高度 - 屏幕高度，即滚动到最后的菜单
	if (nextPos.y >((itemCount + 1)* LINE_SPACE - visibleSize.height))
	{
		// 菜单高度设置为菜单项总高度-屏幕高度
		_itemMenu->setPosition(Vec2(0, ((itemCount + 1)* LINE_SPACE - visibleSize.height)));
		return;
	}
	// 重新设置菜单的位置
	_itemMenu->setPosition(nextPos);
	auto cur_Pos = sprite->getPosition();
	auto next_Pos = Vec2(cur_Pos.x, cur_Pos.y - nextMoveY /3.3 );    //   item移动除以item总 = 滚动条移动除以滚动条总
	if ( next_Pos.y > (visibleSize.height - sprite->getContentSize().height/2)) 
	{
		sprite->setPosition(Vec2(visibleSize.width - sprite->getContentSize().width / 2, visibleSize.height - sprite->getContentSize().height/2));
		return;
	}
	// 如果nextPos的y大于菜单的总高度 - 屏幕高度，即滚动到最后的菜单
	if (next_Pos.y <(sprite->getContentSize().height/2))
	{
		// 菜单高度设置为菜单项总高度-屏幕高度
		sprite->setPosition(Vec2(visibleSize.width - sprite->getContentSize().width / 2, sprite->getContentSize().height/2));
		return;
	}
	sprite->setPosition(next_Pos);
	_beginPos = touchLocation;

}
// ⑦触碰每一个菜单时调用的函数
void ContentLayer::menuCallback(Ref * sender)
{
	// 获得触碰的菜单项
	auto menuItem = static_cast<MenuItem *>(sender);
	// 获得之前设置的tag，用于判断触碰的菜单在itemNames中的下标
	int index = menuItem->getTag();
	log("index: %d", index);
	// 获得对于的场景
	auto scene = itemNames[index].callback();
	// 切换场景
	if (scene)
	{
		Director::getInstance()->replaceScene(scene);
	}
}


