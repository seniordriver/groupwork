

#include "Contentlayer.h"
#include "WelcomeScene.h"

// �ٽṹ��
typedef struct _Controller
{
	// �˵�������
	const std::string itemName;
	// C++11��std::function��ʹ��������ʵ�����ƺ���ָ��Ĺ��ܣ������ǵ����˵���ʱ���صĳ�������
	std::function<Scene*()> callback;
}Controller;



// �����ص��ǲ��Ե��㴥��ʱ����Ļ���������Դ˴�����ÿһ���˵���ʱ���صĶ���WelcomeScene����
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
sizeof�������������Ƿ���һ��������������ĳ��ȡ���sizeof������һ��class ��structʱ��������Щ���Ͷ�����ռ�ֽ���
�ڼ���˵��������
*/
static int itemCount = sizeof(itemNames) / sizeof(itemNames[0]);
// ÿһ���˵���֮��ļ��
#define LINE_SPACE  150

Scene* ContentLayer::createScene()
{
	// ����һ���������󣬸ö��󽫻����Զ��ͷųع����ڴ���ͷ�
	auto scene = Scene::create();

	// ��������󣬸ö��󽫻����Զ��ͷųع����ڴ���ͷ�
	auto layer = ContentLayer::create();

	// ��WelcomeScene����Ϊ�ӽڵ���ӵ�����
	scene->addChild(layer);
		// ���س�������
		return scene;
}

bool ContentLayer::init()
{

	if (!Layer::init())
	{
		return false;
	}

	// ����豸֧�ֵĿɼ�OpenGL��ͼ��С�������ڴ�С����
	Size visibleSize = Director::getInstance()->getVisibleSize();

	// �۴����˵�
	_itemMenu = Menu::create();
	// ѭ����Ӳ˵���
	for (int i = 0; i < itemCount; ++i)
	{
		// ����Label
		auto label = Label::createWithSystemFont(itemNames[i].itemName, "Papyrus", 48);
		// ����menuItemLabel,����ʱ����menuCallback����
		auto menuItem = MenuItemLabel::create(label, CC_CALLBACK_1(ContentLayer::menuCallback, this));
		// ����tag������menuCallback���жϴ����Ĳ˵���itemNames�е��±�
		menuItem->setTag(i);
		// ���˵�����ӵ��˵�
		_itemMenu->addChild(menuItem);

		// ���ò˵���λ��
		menuItem->setPosition(Vec2(visibleSize.width / 2, (visibleSize.height - (i + 1) * LINE_SPACE)));
	}
	_itemMenu->setPosition(Vec2::ZERO);
	// ���˵����Ϊ��ǰ����ӽڵ�
	this->addChild(_itemMenu, 1);

	// ��ע�ᴥ��������
	auto listener = EventListenerTouchOneByOne::create();
	// �����Ƿ����´��ݴ���
	listener->setSwallowTouches(true);
	// ���ô�����ʼʱ����onTouchBegan����
	listener->onTouchBegan = CC_CALLBACK_2(ContentLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(ContentLayer::moveBar, this);
	// ��ӳ��������¼���������
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	sprite->setPosition(Vec2(visibleSize.width - sprite->getContentSize().width/2, visibleSize.height -sprite->getContentSize().height/2 ));
	this->addChild(sprite,2);
	return true;
}

// �ݴ�����ʼ�Ļص�����
bool ContentLayer::onTouchBegan(Touch* touch, Event* event)
{
	// ��¼����������
	_beginPos = touch->getLocation();
	return true;
}

void ContentLayer::moveBar(Touch* touch, Event  *event)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto touchLocation = touch->getLocation();
	float nextMoveY = touchLocation.y - _beginPos.y;
	auto curPos = _itemMenu->getPosition();
	// ��һ��λ�� = Vec2(�˵�λ�õ�x,�˵�λ�õ�y+������ƫ����)
	auto nextPos = Vec2(curPos.x, curPos.y + nextMoveY);
	// ���nextPos��y < 0������������ǰ��Ĳ˵�
	if (nextPos.y < 0.0f)
	{
		// �˵�����ΪVec2(0,0)λ��
		_itemMenu->setPosition(Vec2::ZERO);
		return;
	}
	// ���nextPos��y���ڲ˵����ܸ߶� - ��Ļ�߶ȣ������������Ĳ˵�
	if (nextPos.y >((itemCount + 1)* LINE_SPACE - visibleSize.height))
	{
		// �˵��߶�����Ϊ�˵����ܸ߶�-��Ļ�߶�
		_itemMenu->setPosition(Vec2(0, ((itemCount + 1)* LINE_SPACE - visibleSize.height)));
		return;
	}
	// �������ò˵���λ��
	_itemMenu->setPosition(nextPos);
	auto cur_Pos = sprite->getPosition();
	auto next_Pos = Vec2(cur_Pos.x, cur_Pos.y - nextMoveY /3.3 );    //   item�ƶ�����item�� = �������ƶ����Թ�������
	if ( next_Pos.y > (visibleSize.height - sprite->getContentSize().height/2)) 
	{
		sprite->setPosition(Vec2(visibleSize.width - sprite->getContentSize().width / 2, visibleSize.height - sprite->getContentSize().height/2));
		return;
	}
	// ���nextPos��y���ڲ˵����ܸ߶� - ��Ļ�߶ȣ������������Ĳ˵�
	if (next_Pos.y <(sprite->getContentSize().height/2))
	{
		// �˵��߶�����Ϊ�˵����ܸ߶�-��Ļ�߶�
		sprite->setPosition(Vec2(visibleSize.width - sprite->getContentSize().width / 2, sprite->getContentSize().height/2));
		return;
	}
	sprite->setPosition(next_Pos);
	_beginPos = touchLocation;

}
// �ߴ���ÿһ���˵�ʱ���õĺ���
void ContentLayer::menuCallback(Ref * sender)
{
	// ��ô����Ĳ˵���
	auto menuItem = static_cast<MenuItem *>(sender);
	// ���֮ǰ���õ�tag�������жϴ����Ĳ˵���itemNames�е��±�
	int index = menuItem->getTag();
	log("index: %d", index);
	// ��ö��ڵĳ���
	auto scene = itemNames[index].callback();
	// �л�����
	if (scene)
	{
		Director::getInstance()->replaceScene(scene);
	}
}


