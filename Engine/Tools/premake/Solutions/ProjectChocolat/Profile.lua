-- Profile  --
module("Profile", package.seeall)
local ProjectName = "Profile"
local DebugDefines =
{
	"DEBUG"
}
local ReleaseDefines =
{
	"NDEBUG"
}
local  LinkProjects =
{
	"Core"
}
make_API.SetupProject(ProjectName)
make_API.SettingCppStaticLibProject()
make_API.SettingCppFiles(ProjectName)
--Debug Setting--
make_API.SetupConfiguration("Debug", DebugDefines, "lib", "", "", LinkProjects, "", "Symbols")
--Release Setting--
make_API.SetupConfiguration("Release", ReleaseDefines, "lib", "", "", LinkProjects, "", "Optimize")
