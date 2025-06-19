/*
LUA_QMM - Allow mods to be made as Lua scripts
Copyright 2004-2025
https://github.com/thecybermind/LUA_QMM/
3-clause BSD license: https://opensource.org/license/bsd-3-clause

Created By:
    Kevin Masterson < cybermind@gmail.com >

*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <qmmapi.h>

#include "version.h"
#include "game.h"

#include <string.h>

pluginres_t* g_result = nullptr;
plugininfo_t g_plugininfo = {
	QMM_PIFV_MAJOR,								// plugin interface version major
	QMM_PIFV_MINOR,								// plugin interface version minor
	"Lua_QMM",									// name of plugin
	LUA_QMM_VERSION,							// version of plugin
	"Run Lua scripts as mods",					// description of plugin
	LUA_QMM_BUILDER,							// author of plugin
	"https://github.com/thecybermind/lua_qmm/",	// website of plugin
};
eng_syscall_t g_syscall = NULL;
mod_vmMain_t g_vmMain = NULL;
pluginfuncs_t* g_pluginfuncs = NULL;
pluginvars_t* g_pluginvars = NULL;

// store the game's entity and client info
gentity_t* g_gents = NULL;
int g_numgents = 0;
int g_gentsize = sizeof(gentity_t);
gclient_t* g_clients = NULL;
int g_clientsize = sizeof(gclient_t);


C_DLLEXPORT void QMM_Query(plugininfo_t** pinfo) {
	QMM_GIVE_PINFO();
}


C_DLLEXPORT int QMM_Attach(eng_syscall_t engfunc, mod_vmMain_t modfunc, pluginres_t* presult, pluginfuncs_t* pluginfuncs, pluginvars_t* pluginvars) {
	QMM_SAVE_VARS();

	return 1;
}


C_DLLEXPORT void QMM_Detach() {
}


C_DLLEXPORT intptr_t QMM_vmMain(intptr_t cmd, intptr_t* args) {
	if (cmd == GAME_INIT) {
	}
	else if (cmd == GAME_CLIENT_COMMAND) {
	}

	QMM_RET_IGNORED(1);
}


C_DLLEXPORT intptr_t QMM_syscall(intptr_t cmd, intptr_t* args) {
	// this is fairly common to store entity/client data. the second argument (num gentities) changes
	// every time a new entity is spawned, so this gets called a lot. no other args should change after
	// the first call. for QUAKE2 and Q2R, this is a QMM polyfill call
	if (cmd == G_LOCATE_GAME_DATA) {
		g_gents = (gentity_t*)(args[0]);
		g_numgents = args[1];
		g_gentsize = args[2];
		g_clients = (gclient_t*)(args[3]);
		g_clientsize = args[4];
	}

	QMM_RET_IGNORED(1);
}


C_DLLEXPORT intptr_t QMM_vmMain_Post(intptr_t cmd, intptr_t* args) {
	QMM_RET_IGNORED(1);
}


C_DLLEXPORT intptr_t QMM_syscall_Post(intptr_t cmd, intptr_t* args) {
	QMM_RET_IGNORED(1);
}
