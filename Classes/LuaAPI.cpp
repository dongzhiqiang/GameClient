#include "LuaAPI.h"
#include "Client.h"

int api_load_file( const char* file )
{
	CCLog("load lua file: %s", file);
	return CCLuaEngine::defaultEngine()->executeScriptFile(file);
}

