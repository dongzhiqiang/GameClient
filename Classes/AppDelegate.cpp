#include "cocos2d.h"
#include "CCEGLView.h"
#include "AppDelegate.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "Lua_extensions_CCB.h"
#include "Client.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "Lua_web_socket.h"
#endif

using namespace CocosDenshion;

USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SimpleAudioEngine::end();
}

#ifdef WIN32
void myGameKeyHook( UINT message,WPARAM wParam,LPARAM lParam )
{
	switch( message )
	{
	case WM_CHAR:
		{
		}
		break;
	case WM_KEYDOWN:
	case WM_KEYUP:
		{
			if (message == WM_KEYDOWN &&(lParam & 0x40000000))
			{
				break;
			}

			CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
			CCLuaStack* pStack = pEngine->getLuaStack();
			if (pStack)
			{
				std::vector<CCLuaValue> values;
				values.push_back(CCLuaValue::intValue(message));//±íÃ÷ÊÇkeydown
				values.push_back(CCLuaValue::intValue(wParam));
				values.push_back(CCLuaValue::intValue(lParam));
				pStack->executeGlobalFunction("RefreshScript",values);
			}
		}
		break;
	default:
		break;
	}
}
#endif

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

    // turn on display FPS
    pDirector->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY)
    CCFileUtils::sharedFileUtils()->addSearchPath("script");
#endif

#ifdef WIN32
	CCEGLView::sharedOpenGLView()->setAccelerometerKeyHook( &myGameKeyHook );
#endif // WIN32


    //std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename("hello.lua");
    //pEngine->executeScriptFile(path.c_str());

    return g_pClient->LoadGame();
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();

    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();

    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
