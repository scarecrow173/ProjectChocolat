-- Generics --
module("Generics", package.seeall)
local ProjectName = "Generics" 
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
	"Core",
	"Memory"
}
make_API.SetupProject (ProjectName)
make_API.SettingCppStaticLibProject()
make_API.SettingCppFiles(ProjectName)
--Debug Setting--
make_API.SetupConfiguration("Debug", DebugDefines, "lib", "", LinkProjects, "", "Symbols")
--Release Setting--
make_API.SetupConfiguration("Release", ReleaseDefines, "lib", "", LinkProjects, "", "Optimize")
