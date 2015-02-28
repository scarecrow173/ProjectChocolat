-- ProjectChocolat --
module("ProjectChocolat", package.seeall)
local Solutions_DirPath = "Tools/premake/Solutions/"
local Solution_Name = "ProjectChocolat"
local Project_Path = Solutions_DirPath .. Solution_Name
solution (Solution_Name)
configurations { "Debug", "Release" }

require(Project_Path .. "/Core")
require(Project_Path .. "/Math")
require(Project_Path .. "/Memory")
require(Project_Path .. "/IO")
require(Project_Path .. "/Thread")
require(Project_Path .. "/File")
require(Project_Path .. "/Debugger")
require(Project_Path .. "/Profile")
--require(Project_Path .. "/Window")
require(Project_Path .. "/Framework")
--require(Project_Path .. "/ImageAnalyzer")
--require(Project_Path .. "/SoundAnalyzer")

------------------------------------------
-- Applications --
require(Project_Path .. "/wxWidgetsSample")