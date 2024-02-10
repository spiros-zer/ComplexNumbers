-- (c) Spyridon Zervos


workspace "PolarCoordinatesTest"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }
    startproject "PolarCoordinatesTest"

OutputDir = '%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}'

group "Core"
    include "Core/Build-Core.lua"
group ""

include "App/Build-App.lua"