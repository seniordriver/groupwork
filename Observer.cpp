#include"Observer.h"
//#include"GameScene.h"
using namespace CocosDenshion;
USING_NS_CC;

 void Observer::KeyUp()
{
	 auto move = MoveBy::create(0.4, Vec2(0, -200));
	 auto move1 = MoveBy::create(0.4, Vec2(0, -5));
	 for (int i = 0; i < listener1.size(); i++)
	 {
		 Sprite* test = listener1.at(i);
		 //Sprite* test2 = listener1.at(i+1);
		 if (i==0){
			 test->stopAllActions();
			 test->runAction(RepeatForever::create(GameScene::jump()));
		 }
		 else if(i==1){
			 test->runAction(Sequence::create(move, move->reverse(), nullptr));
			 //test2->runAction(Sequence::create(move->clone()->clone(), move->clone()->clone()->clone()->reverse(), nullptr));
		 }
		 else{
			 test->runAction(Sequence::create(move->clone()->clone(), move->clone()->clone()->reverse(), nullptr));
		 
		 }
	 }
}

 void Observer::KeyDown()
 {
	 for (int i = 0; i < listener2.size(); i++)
	 {
		 Sprite* test = listener2.at(i);
		 test->stopAllActions();
		 test->runAction(Repeat::create(GameScene::slide(), 4));
	 }
 }



