#pragma once

//tolua_begin
typedef char						int8;
typedef unsigned char				uint8;
typedef	short						int16;
typedef unsigned short				uint16;
typedef	long						int32;
typedef	unsigned long				uint32;
typedef long long					int64;
typedef unsigned long long			uint64;
//tolua_end

#include <string>
typedef std::string			String;

#include <vector>
#include <list>
#include <map>
#include <deque>
#include <sstream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <time.h>
#include <iostream>

using namespace std;


#define XVector			std::vector
#define XList			std::list
#define XMap			std::map
#define XSet			std::set
#define XMultiSet		std::multiset


#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif
#include "CCLuaEngine.h"