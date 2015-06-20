-- SoundAnalyzer  --
module("SoundAnalyzer", package.seeall)
local ProjectName = "SoundAnalyzer" 
local DebugDefines =
{
	"DEBUG"
}
local ReleaseDefines =
{
	"NDEBUG"
}
make_API.SetupProject (ProjectName)
make_API.SettingCppApplicationProject()
make_API.SettingCppFiles(ProjectName)
--Debug Setting--
make_API.SetupConfiguration("Debug", DebugDefines, "App", "", "", "", "Symbols")
--Release Setting--
make_API.SetupConfiguration("Release", ReleaseDefines, "App", "", "", "", "Optimize")