:: (c) Spyridon Zervos


@echo off
git submodule update --init --recursive
git submodule update --recursive --remote

pushd ..
external\premake\premake5.exe --file=Build.lua vs2022
popd

pause