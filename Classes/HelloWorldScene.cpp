#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !CCLayerColor::initWithColor(ccc4(241, 241, 241, 255))     )
    {
        return false;
    }
    setTouchEnabled(true);
    currentScore = 0;
    targetScore = 100;

    // ----------------------------- X ------------------------------
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    // ----------------------------- X --------------------------------
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();

    label = CCLabelTTF::create("0", "Helvetica", 250);
    label->setColor(ccc3(192, 57, 43));
    label->setPosition(ccp(size.width/2, size.height/2));
 
    this->addChild(label);

    
    schedule(schedule_selector(HelloWorld::updateScore), 1/30.0f);
    
    return true;
}

void HelloWorld::updateScore()
{
    if( currentScore < targetScore )
    {
        currentScore += 5; // change to whatever you like
        
        char *labelString = new char;
        snprintf(labelString, 10, "%d", currentScore);
        
        label->setString(labelString);
    }
    else
    {
        this->unschedule(schedule_selector(HelloWorld::updateScore));
    }
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}