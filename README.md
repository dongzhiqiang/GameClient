# MyGame0106
1、配置GameApp.pgk的编译时 提示tolua++的路径不对，需要将cocos2dx-2.2.6引擎的cocos2d-x-2.2.6\tools\tolua++目录下的tolua++解压

2、引擎里的 CCLuaStack 在调用 lua 函数时不支持传参，需多加个函数 如下


  CCLuaStack.h 
  
    virtual int executeGlobalFunction(const char* functionName,const std::vector<CCLuaValue>& values)
  
  CCLuaStack.cpp
  
    int CCLuaStack::executeGlobalFunction(const char* functionName,const std::vector<CCLuaValue>& values)
    {
    	lua_getfield(m_state, LUA_GLOBALSINDEX,functionName);      /* query function by name, stack: function */
        if (!lua_isfunction(m_state, -1))
        {
            TRACE_ERROR("[LUA ERROR] name '%s' does not represent a Lua function", functionName);
            lua_pop(m_state, 1);
            return 0;
        }
    
    	for(int i=0;i<values.size();++i)
    	{
    		pushCCLuaValue(values[i]);
    	}
    
    	int error = lua_pcall(m_state,values.size(),1, 0);                                                 /* callfunction, stack: ret */
    	if (error) 
    	{ 
    		TRACE_ERROR("[LUA ERROR] %s", lua_tostring(m_state, - 1)); 
    		lua_pop(m_state, 1); // clean error message 
    		return 0;
    	}
    
    	int ret = 0;
        if (lua_isnumber(m_state, -1))
        {
            ret = lua_tointeger(m_state, -1);
        }
        else if (lua_isboolean(m_state, -1))
        {
            ret = lua_toboolean(m_state, -1);
        }
        // remove return value from stack
        lua_pop(m_state, 1);                                                /* L: ... [G] */
        
        return ret;
    }

3、github 上传时会遇到些问题 修改配置 C:\Program Files (x86)\Git\etc\gitconfig 在 [core] 里 加 compression = -1
    上传文件会限制大小，太大上传不了 修改配置 在 [http] 里 加 postBuffer = 524288000
    
      [core]
      	symlinks = false
      	autocrlf = true
      	compression = -1
      [color]
      	diff = auto
      	status = auto
      	branch = auto
      	interactive = true
      [pack]
      	packSizeLimit = 2g
      [help]
      	format = html
      [http]
      	sslCAinfo = /bin/curl-ca-bundle.crt
      	postBuffer = 524288000
      [sendemail]
      	smtpserver = /bin/msmtp.exe
      
      [diff "astextplain"]
      	textconv = astextplain
      [rebase]
      	autosquash = true

4、配置eclipse环境
    在eclipse导入此项目，由于是lua工程，虽然eclipse里安装了adt，但检测不出 C/C++ Build 的选项
    需先将项目转化为C++工程，在 File -> New -> Other -> 选C++的项目
    转化完需要配置C++build选项 将Use default build command 选项勾去掉
    Build command 改为 bash ${ProjDirPath}/build_native.sh,  Build location 改为 ${ProjDirPath}
    
