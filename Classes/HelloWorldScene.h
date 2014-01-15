#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::CCLayerColor
{
public:
    virtual bool init();
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    
    CREATE_FUNC(HelloWorld);
    
private:
    CCLabelTTF* label;
    int currentScore;
    int targetScore;
    
    void updateScore();
};

#endif // __HELLOWORLD_SCENE_H__
