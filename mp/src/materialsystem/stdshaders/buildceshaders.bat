@echo off

taskkill /IM shadercompile.exe

call buildshaders.bat CEShaders_dx9_20b -game "C:\Program Files (x86)\Steam\steamapps\common\Team Fortress 2\tf" -source "C:\Users\matt\source\repos\CastingEssentials\sdk2013\mp\src"

copy "shaders\fxc\*" "..\..\..\..\..\plugin_folder\shaders\fxc\"