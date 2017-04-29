#ifndef __ENDGAME_SCENE_H__
#define __ENDGAME_SCENE_H__

#include "cocos2d.h"
#include "ui\CocosGUI.h"

USING_NS_CC;

using namespace ui;
using namespace std;

class EndGameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	static string stats;
	Label *label1;
	CREATE_FUNC(EndGameScene);
};

#endif  __ENDGAME_SCENE_H__
