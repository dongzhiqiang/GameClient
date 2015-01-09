---------------------------------------------------------
-- 日期：	20150107
-- 作者:	Dzq
-- 描述:	游戏大厅登录界面
---------------------------------------------------------


-- 全局服务器地址
local gloable_svr_ip 	= '192.168.1.79'
local gloable_svr_port	= 20016

local pLoadScene 		= nil 	----加载界面

local winSize = CCDirector:sharedDirector():getWinSize()

local function initLoadUI()
	pLoadScene = CCScene:create()

	local pLoadLayer = CCLayer:create()
	pLoadScene:addChild(pLoadLayer)
	pLoadLayer:setTag(1)

	local bg = CCSprite:create("res/bg.jpg")
	bg:setPosition(winSize.width/2, winSize.height/2)
	pLoadLayer:addChild(bg)

	Client:GetInstance():SetCurScene(pLoadScene)
end

local function showLoadUI()
	if pLoadScene == nil then
		initLoadUI()
	end

	CCDirector:sharedDirector():runWithScene(pLoadScene)

	local curScene = Client:GetInstance():GetCurScene()
	local curLayer = curScene:getChildByTag(1)
	local logo = CCSprite:create("res/logo.png")
	logo:setPosition(winSize.width/2, winSize.height/2 + 100)
	curLayer:addChild(logo)

	
end

showLoadUI()
