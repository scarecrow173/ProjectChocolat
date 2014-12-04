-- ProjectChocolat --
module("ProjectChocolat", package.seeall)
local Solutions_DirPath = "Tools/premake/Solutions/"
local Solution_Name = "ProjectChocolat"
solution (Solution_Name)
configurations { "Debug", "Release" }
require(Solutions_DirPath .. Solution_Name .. "/Core")
--require(Solutions_DirPath .. Solution_Name .. "/Math")
--require(Solutions_DirPath .. Solution_Name .. "/Memory")
--require(Solutions_DirPath .. Solution_Name .. "/Thread")
--require(Solutions_DirPath .. Solution_Name .. "/File")
--require(Solutions_DirPath .. Solution_Name .. "/Debugger")
--require(Solutions_DirPath .. Solution_Name .. "/Framework")
--require(Solutions_DirPath .. Solution_Name .. "/ImageAnalyzer")
--require(Solutions_DirPath .. Solution_Name .. "/SoundAnalyzer")
