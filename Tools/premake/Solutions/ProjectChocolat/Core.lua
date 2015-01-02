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
make_API.SetupProject (ProjectName)
make_API.SettingCppStaticLibProject()
make_API.SettingCppFiles(ProjectName)
--Debug Setting--
make_API.SetupConfiguration("Debug", DebugDefines, "lib", "", "", "", "Symbols")
--Release Setting--
make_API.SetupConfiguration("Release", ReleaseDefines, "lib", "", "", "", "Optimize")