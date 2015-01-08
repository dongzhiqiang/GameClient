
----配置脚本名
local scriptName = "hall/load.lua"

----调用函数
local function callFunc()
	--cclog("call lua function ----------------- ")
	-- print("call lua function ----------------- ")
	local curScene = Client:GetInstance():GetCurScene()
	local curLayer = curScene:getChildByTag(1)
	-- print("00000000000000000000000")
	-- local spt = CCSprite:create("res/dialog_close_btn_d.png")
	-- spt:setPosition(300,50)
	-- curLayer:addChild(spt)

	-- spt = CCSprite:create("res/progress_bar.png")
	-- spt:setPosition(50,100)
	-- curLayer:addChild(spt)

	-- spt = CCSprite:create("res/btn_no_d.png")
	-- spt:setPosition(100,20)
	-- curLayer:addChild(spt)

	spt = CCSprite:create("res/icon_alert.png")
	spt:setPosition(150,400)
	curLayer:addChild(spt)


	-- spt = CCSprite:create("res/icon_loading.png")
	-- spt:setPosition(200,400)
	-- curLayer:addChild(spt)
	-- api_action_fade_hide(spt,1)
	--api_action_fade_show(spt,0.5)
	api_action_scale_show(spt,200)
	cclog("weoifjwoigjeroigjoerijgoerijgioe")
end

function RefreshScript(msg,wParam,lParam)
	--cclog('OnKeyMsg  msg:'..msg..' wParam : '..wParam..' lParam:'..lParam)
	print('OnKeyMsg  msg:'..msg..' wParam : '..wParam..' lParam:'..lParam)
	if wParam == 112 then 	    ------------------F1
		api_load_file('common/Refresh.lua')
		--api_load_file(scriptName)
	elseif wParam == 113 then 	------------------F2
		callFunc()
	end
end

