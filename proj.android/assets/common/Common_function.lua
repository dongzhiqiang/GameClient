-- cclog
cclog = function(...)
    print(string.format(...))
end

-- 设置全局变量
function set_global(k,v)
	rawset(_G,k,v)
end

--修改一个CCSprite的纹理
function api_set_sprite_texture(sprite,path)
	if path== nil or sprite == nil then
		return false
	end
	local texture = CCTextureCache:sharedTextureCache():addImage(path)
	if texture == nil then
		return false
	end
	sprite:setTexture(texture)
	sprite:setTextureRect(CCRectMake(0,0,texture:getContentSize().width,texture:getContentSize().height))
	return true
end

----------------------------------------------------------
-- 基本共用界面动画
-- 界面放大显示
function api_action_scale_show(layer,fade)
	layer:setScale(0.1)
	layer:setOpacity(0)
	layer:setVisible(true)
	
	local fadeTo = 255
	if fade ~= nil then
		fadeTo = fade
	end
	
	local action1 = CCSpawn:createWithTwoActions(CCScaleTo:create(0.12,1.15),CCFadeTo:create(0.12,fadeTo))
	local action  = CCSequence:createWithTwoActions(action1,CCScaleTo:create(0.1,1.0))
	layer:runAction(action)
end
-- 界面缩小隐藏
function api_action_scale_hide(layer)
	layer:setVisible(true)	
	local array = CCArray:create()
	array:addObject(CCScaleTo:create(0.1,1.15))
	array:addObject(CCSpawn:createWithTwoActions(CCScaleTo:create(0.12,0.1),CCFadeTo:create(0.12,0)))
	array:addObject(CCHide:create())
	local action  = CCSequence:create(array)
	layer:runAction(action)
end
-- 界面渐现
function api_action_fade_show(layer, time)
	layer:setOpacity(0)
	layer:setVisible(true)	
	local action = CCFadeTo:create(time,255)
	layer:runAction(action)
end
-- 界面渐隐
function api_action_fade_hide(layer, time)
	layer:setVisible(true)
	local action  = CCSequence:createWithTwoActions(CCFadeTo:create(time,0),CCHide:create())
	layer:runAction(action)
end