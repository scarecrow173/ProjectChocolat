-- wxWidgetsSample  --
module("wxWidgetsSample", package.seeall)
local ProjectName = "wxWidgetsSample"
local DebugDefines =
{
	"DEBUG"
}
local ReleaseDefines =
{
	"NDEBUG"
}
local LinkProjects =
{
	
}
make_API.SetupProject (ProjectName)
make_API.SettingCppApplicationProject()
make_API.SettingCppFiles(ProjectName)
--Debug Setting--
make_API.SetupConfiguration("Debug", DebugDefines, "lib", "", LinkProjects, "", "Symbols")
--Release Setting--
make_API.SetupConfiguration("Release", ReleaseDefines, "lib", "", LinkProjects, "", "Optimize")
