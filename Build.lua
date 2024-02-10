-- (c) Spyridon Zervos


workspace "ComplexNumbersTest"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }
    startproject "ComplexNumbersTest"

OutputDir = '%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}'

group "Core"
    include "Core/Build-Core.lua"
group ""

include "App/Build-App.lua"