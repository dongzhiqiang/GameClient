#pragma once

#include "globleDef.h"

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

// CCObject÷«ƒ‹÷∏’Î
template<class T>
class CCObjectPtr
{	
public:	
	CCObjectPtr(T * p = 0)
		: _obj(p)
	{
		CC_SAFE_RETAIN(_obj);
	}
	CCObjectPtr(CCObjectPtr const & r)
		: _obj(r.get())
	{
		CC_SAFE_RETAIN(_obj);
	}
	~CCObjectPtr() 
	{
		CC_SAFE_RELEASE(_obj);
	}

	template<class _Other>
	CCObjectPtr(CCObjectPtr<_Other> const & r)
		: _obj(r.get())
	{
		CC_SAFE_RETAIN(_obj);
	}

	CCObjectPtr& operator=(T* ptr)
	{
		CC_SAFE_RETAIN(ptr);
		CC_SAFE_RELEASE(_obj);
		_obj = ptr;
		return (*this);
	}
	CCObjectPtr& operator=(CCObjectPtr const & r)
	{
		CC_SAFE_RETAIN(r.get());
		CC_SAFE_RELEASE(_obj);
		_obj = r.get();
		return *this;
	}
	template<class _Other>
	CCObjectPtr<T>& operator=(CCObjectPtr<_Other> const & r)
	{
		CC_SAFE_RETAIN(r.get());
		CC_SAFE_RELEASE(_obj);
		_obj = r.get();
		return (*this);
	}
	T& operator*() const
	{
		return (*get());
	}

	T* operator->() const 
	{
		return get();
	}

	T* get() const 
	{
		return (_obj);
	}

	bool operator !()
	{
		return !get();
	}

	operator bool()
	{
		return get()!= 0;
	}
private:
	T*	_obj;	
};

template<class T> inline bool operator==(CCObjectPtr<T>  const & a, CCObjectPtr<T> const & b) 
{ 
	return a.get() == b.get();
} 
template<class T> inline bool operator!=(CCObjectPtr<T> const & a, CCObjectPtr<T> const & b) 
{ 
	return a.get() != b.get(); 
} 
template<class T> inline bool operator<(CCObjectPtr<T> const & a, CCObjectPtr<T> const & b)
{
	return std::less<T*>()(a.get(), b.get());
}

typedef CCObjectPtr<CCSprite>	CCSpritePtr;
typedef CCObjectPtr<CCScene>	CCScenePtr;
typedef CCObjectPtr<CCLayer>	CCLayerPtr;
