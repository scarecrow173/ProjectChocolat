-- ProjectChocolat --
module("ProjectChocolat", package.seeall)
Solution_Name = "ProjectChocolat"
solution ("../../../" .. Solution_Name)
configurations { "Debug", "Release" }
dofile(Solution_Name .. "/Core.lua")
dofile(Solution_Name .. "/ImageAnalyzer.lua")
dofile(Solution_Name .. "/SoundAnalyzer.lua")
