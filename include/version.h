/*
LUA_QMM - Allow mods to be made as Lua scripts
Copyright 2004-2025
https://github.com/thecybermind/LUA_QMM/
3-clause BSD license: https://opensource.org/license/bsd-3-clause

Created By:
    Kevin Masterson < cybermind@gmail.com >

*/

#ifndef __LUA_QMM_VERSION_H__
#define __LUA_QMM_VERSION_H__

#define STRINGIFY(x) STRINGIFY2(x)
#define STRINGIFY2(x) #x

#define LUA_QMM_VERSION_MAJOR	2
#define LUA_QMM_VERSION_MINOR	1
#define LUA_QMM_VERSION_REV	0

#define LUA_QMM_VERSION		STRINGIFY(LUA_QMM_VERSION_MAJOR) "." STRINGIFY(LUA_QMM_VERSION_MINOR) "." STRINGIFY(LUA_QMM_VERSION_REV)

#if defined(_WIN32)
#define LUA_QMM_OS             "Windows"
#ifdef _WIN64
#define LUA_QMM_ARCH           "x86_64"
#else
#define LUA_QMM_ARCH           "x86"
#endif
#elif defined(__linux__)
#define LUA_QMM_OS             "Linux"
#ifdef __LP64__
#define LUA_QMM_ARCH           "x86_64"
#else
#define LUA_QMM_ARCH           "x86"
#endif
#endif

#define LUA_QMM_VERSION_DWORD	LUA_QMM_VERSION_MAJOR , LUA_QMM_VERSION_MINOR , LUA_QMM_VERSION_REV , 0
#define LUA_QMM_COMPILE		__TIME__ " " __DATE__
#define LUA_QMM_BUILDER		"cybermind"

#endif // __LUA_QMM_VERSION_H__
