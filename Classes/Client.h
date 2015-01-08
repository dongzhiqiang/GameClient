#pragma once

#include "Typedef.h"

class Client:public CCObject //tolua_export
{//tolua_export
public:
	Client(void);
	~Client(void);

	//tolua_begin
	static Client* GetInstance()
	{
		static Client s;
		return &s;
	}

	CCScene* GetCurScene();

	void SetCurScene(CCScene* pScene);

	//tolua_end
	
	bool LoadGame();


protected:
	CCScenePtr m_pCurScene;
};//tolua_export

#define g_pClient Client::GetInstance()