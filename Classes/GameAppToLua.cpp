/*
** Lua binding: GameApp
** Generated automatically by tolua++-1.0.92 on 01/08/15 15:49:19.
*/

extern "C" {
#include "tolua_fix.h"
}

#include <map>
#include <string>
#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"

using namespace cocos2d;
using namespace cocos2d::extension;
using namespace CocosDenshion;

/* Exported function */
TOLUA_API int  tolua_GameApp_open (lua_State* tolua_S);

#include "../Classes/globleDef.h"
#include "../Classes/Typedef.h"
#include "../Classes/Client.h"
#include "../Classes/LuaAPI.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Client");
 tolua_usertype(tolua_S,"CCScene");
 tolua_usertype(tolua_S,"CCObject");
}

/* method: GetInstance of class  Client */
#ifndef TOLUA_DISABLE_tolua_GameApp_Client_GetInstance00
static int tolua_GameApp_Client_GetInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Client* tolua_ret = (Client*)  Client::GetInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Client");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCurScene of class  Client */
#ifndef TOLUA_DISABLE_tolua_GameApp_Client_GetCurScene00
static int tolua_GameApp_Client_GetCurScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCurScene'", NULL);
#endif
  {
   CCScene* tolua_ret = (CCScene*)  self->GetCurScene();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCScene");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCurScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCurScene of class  Client */
#ifndef TOLUA_DISABLE_tolua_GameApp_Client_SetCurScene00
static int tolua_GameApp_Client_SetCurScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Client",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCScene",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Client* self = (Client*)  tolua_tousertype(tolua_S,1,0);
  CCScene* pScene = ((CCScene*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCurScene'", NULL);
#endif
  {
   self->SetCurScene(pScene);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCurScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: api_load_file */
#ifndef TOLUA_DISABLE_tolua_GameApp_api_load_file00
static int tolua_GameApp_api_load_file00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isstring(tolua_S,1,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* file = ((const char*)  tolua_tostring(tolua_S,1,0));
  {
   int tolua_ret = (int)  api_load_file(file);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'api_load_file'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_GameApp_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Client","Client","CCObject",NULL);
  tolua_beginmodule(tolua_S,"Client");
   tolua_function(tolua_S,"GetInstance",tolua_GameApp_Client_GetInstance00);
   tolua_function(tolua_S,"GetCurScene",tolua_GameApp_Client_GetCurScene00);
   tolua_function(tolua_S,"SetCurScene",tolua_GameApp_Client_SetCurScene00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"api_load_file",tolua_GameApp_api_load_file00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_GameApp (lua_State* tolua_S) {
 return tolua_GameApp_open(tolua_S);
};
#endif

