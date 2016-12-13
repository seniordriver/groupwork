#include"cocos2d.h"
#include"Enemy.h"
#include"EnemyNormal.h"
using namespace std;

class Factory {
public:
	static Enemy* create() {
		return EnemyNormal::create();
	};
};