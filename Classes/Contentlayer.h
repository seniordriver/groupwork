

#include "cocos2d.h"

USING_NS_CC;

class ContentLayer : public cocos2d::Layer
{
protected:
	// ��¼�����Ŀ�ʼ����
	Vec2 _beginPos;
	// �˵�
	Menu* _itemMenu;
public:
	
	static Scene* createScene();
	/**
	* init��������ɳ�ʼ��������
	* ע�⣺init������Cocos2d-x�з���boolֵ�������Ƿ���Cocos2d-iPhone�еġ�id��
	*/
	virtual bool init();
	/**
	* ʹ��CREATE_FUNC�괴����ǰ��Ķ��󣬷��صĶ��󽫻����Զ��ͷųع����ڴ���ͷ�
	*/
	CREATE_FUNC(ContentLayer);

	// ���ÿһ���˵���ʱ�Ļص�����
	void menuCallback(Ref * sender);

	// �����¼��ص�����
	bool onTouchBegan(Touch* touch, Event* event);
	void moveBar(Touch* touch, Event* event);
	Sprite*  sprite = Sprite::create("scrollbar.png");
};


