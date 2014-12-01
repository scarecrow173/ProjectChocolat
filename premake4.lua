-- premake.lua --
require "Tools/premake/ProjectChocolat"
for i , ver in pairs(ProjectChocolat.Project_Table) do
	print(ver)
end
--solution "ProjectChocolat"
--	configurations { "Debug", "Release" }
--
--	project "Demo"
--		kind "ConsoleApp"
--		language "C++"
--		files
--		{
--			"Source/**.h",
--			"Source/**.c",
--			"Source/**.hpp",
--			"Source/**.cpp",
--		}
--		configuration "Debug"
--			defines
--			{
--				"DEBUG"
--			}
--			flags
--			{
--				"Symbols"
--			}
--
--		configuration "Release"
--			defines
--			{
--				"NDEBUG"
--			}
--			flags
--			{
--				"Optimize"
--			}
