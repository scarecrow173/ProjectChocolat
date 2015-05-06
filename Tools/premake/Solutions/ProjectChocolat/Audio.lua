-- Audio  --
module("Audio", package.seeall)
local ProjectName = "Audio" 
local DebugDefines =
{
	"DEBUG",
}
local ReleaseDefines =
{
	"NDEBUG",
}
local  LinkProjects =
{
	"Core"
}
local IncludeDirs ={}
local ExtensionPathes = {}
if (os.get() == "windows") then
	local WinDefs = 
	{
		"WIN32",
		"__WINDOWS_ASIO__",
		"__WINDOWS_WASAPI__"
	}
	table.insert(DebugDefines, WinDefs)
	table.insert(ReleaseDefines, WinDefs)
	table.insert(IncludeDirs,
		{
			"Dependencies/rtaudio-4.1.1/",
			"Dependencies/rtaudio-4.1.1/include/",
		})
	table.insert(ExtensionPathes,
		{
			"Dependencies/rtaudio-4.1.1/*.h",
			"Dependencies/rtaudio-4.1.1/*.hpp",
			"Dependencies/rtaudio-4.1.1/*.c",
			"Dependencies/rtaudio-4.1.1/*.cpp",
			"Dependencies/rtaudio-4.1.1/include/*.h",
			"Dependencies/rtaudio-4.1.1/include/*.hpp",
			"Dependencies/rtaudio-4.1.1/include/*.c",
			"Dependencies/rtaudio-4.1.1/include/*.cpp",
		})

elseif(os.get() == "macosx") then

end

make_API.SetupProject (ProjectName)
make_API.SettingCppStaticLibProject()
make_API.SettingCppFiles(ProjectName)
files(ExtensionPathes)
--Debug Setting--
make_API.SetupConfiguration("Debug", DebugDefines, "lib", "",  "", LinkProjects, IncludeDirs, "Symbols")
--Release Setting--
make_API.SetupConfiguration("Release", ReleaseDefines, "lib", "",  "", LinkProjects, IncludeDirs, "Optimize")