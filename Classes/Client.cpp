
#include "Client.h"
#include "CCLuaEngine.h"
#include "GameAppToLua.h"
#include "LuaCocos2d.h"
#include "Lua_extensions_CCB.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include "Lua_web_socket.h"
#endif

Client::Client( void )
{
}

Client::~Client( void )
{
}

bool Client::LoadGame()
{
	//初始化网络

	//添加资源路径
	
	CCFileUtils::sharedFileUtils()->addSearchPath("hall/");
	CCFileUtils::sharedFileUtils()->addSearchPath("moudle/");

	// register lua engine
	CCLuaEngine* pEngine = CCLuaEngine::defaultEngine();
	CCScriptEngineManager::sharedManager()->setScriptEngine(pEngine);

	CCLuaStack *pStack = pEngine->getLuaStack();
	lua_State *tolua_s = pStack->getLuaState();
	tolua_extensions_ccb_open(tolua_s);

	pStack = pEngine->getLuaStack();
	tolua_s = pStack->getLuaState();
	tolua_GameApp_open(tolua_s);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	pStack = pEngine->getLuaStack();
	tolua_s = pStack->getLuaState();
	tolua_web_socket_open(tolua_s);
#endif

	pEngine->executeScriptFile("hall/load.lua");

	return true;
}

CCScene* Client::GetCurScene()
{
	return m_pCurScene.get();
}

void Client::SetCurScene( CCScene* pScene )
{
	m_pCurScene = pScene;
}

