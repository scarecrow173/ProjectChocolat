-- Core  --
module("Core", package.seeall)
local ProjectName = "Core" 
local DebugDefines =
{
	"DEBUG"
}
local ReleaseDefines =
{
	"NDEBUG"
}
project (ProjectName)
	kind "ConsoleApp"
	language "C++"
	files
	{
		ProjectName .. "/**.h",
		ProjectName .. "/**.c",
		ProjectName .. "/**.hpp",
		ProjectName .. "/**.cpp",
	}
make_API.SetupConfiguration("Debug", DebugDefines, "", "", "", "Symbols")
make_API.SetupConfiguration("Release", ReleaseDefines, "", "", "", "Optimize")

