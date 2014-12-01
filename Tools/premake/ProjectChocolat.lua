-- ProjectChocolat --
require "Tools/premake/make_API"
module("ProjectChocolat", package.seeall)
Solution_Name = "ProjectChocolat"
Project_Table =
{
}
solution (Solution_Name)
configurations { "Debug", "Release" }
dofile("Tools/premake/Projects/Core.lua")
dofile("Tools/premake/Projects/ImageAnalyzer.lua")
dofile("Tools/premake/Projects/SoundAnalyzer.lua")
