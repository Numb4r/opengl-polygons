#ifndef LOADLUA_HPP
#define LOADLUA_HPP
extern "C"{
    #include <lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
}
lua_State *L = luaL_newstate();
#endif