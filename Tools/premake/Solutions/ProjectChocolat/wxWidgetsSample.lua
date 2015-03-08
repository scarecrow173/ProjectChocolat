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
local LinkProjects ={}
local DebugLinkLibs = {}
local ReleaseLinkLibs ={}
local DebugIncludeDirs = 
{
	"Dependencies/wxWidgets-3.0.2/include/",
}
local ReleaseIncludeDirs =
{
	"Dependencies/wxWidgets-3.0.2/include/",	
}
local DebugLibDirs={}
local ReleaseLibDirs={}

if (os.get() == "windows") then
	table.insert(DebugDefines ,
		{
			"WIN32",
			"_DEBUG",
			"__WXMSW__",
			"_WINDOWS",
			"NOPCH",
		}
	)
	table.insert(ReleaseDefines,
		{
			"WIN32",
			"__WXMSW__",
			"NDEBUG",
			"_WINDOWS",
			"NOPCH",
		}
	)
	table.insert(DebugIncludeDirs,
		{"Dependencies/wxWidgets-3.0.2/lib/vc_lib/mswud","Dependencies/rtaudio-4.1.1"})
	table.insert(ReleaseIncludeDirs,
		{"Dependencies/wxWidgets-3.0.2/lib/vc_lib/mswu", "Dependencies/rtaudio-4.1.1"})

	table.insert(DebugLinkLibs,
		{
			"wxmsw30ud_core",
			"wxbase30ud",
			"wxtiffd",
			"wxjpegd",
			"wxpngd",
			"wxzlibd",
			"wxregexud",
			"wxexpatd",
			"winmm",
			"comctl32",
			"rpcrt4",
			"wsock32",
			"wininet",
		}
	)
	table.insert(ReleaseLinkLibs,
		{
			"wxmsw30u_core",
			"wxbase30u",
			"wxtiff",
			"wxjpeg",
			"wxpng",
			"wxzlib",
			"wxregexu",
			"wxexpat",
			"winmm",
			"comctl32",
			"rpcrt4",
			"wsock32",
			"wininet",
	}
	)
	table.insert(DebugLibDirs,"Dependencies/wxWidgets-3.0.2/lib/vc_lib")
	table.insert(ReleaseLibDirs,"Dependencies/wxWidgets-3.0.2/lib/vc_lib")

elseif(os.get() == "macosx") then
	table.insert(DebugDefines ,
		{
			"$(WX_PREPROCESSOR_DEFINITIONS)",
			"WXBUILDING",
			"$(WXPLATFORM)",
			"__WX__",
			"wxUSE_BASE=1",
			"_FILE_OFFSET_BITS=64",
			"_LARGE_FILES",
			"MACOS_CLASSIC",
			"__WXMAC_XCODE__=1",
			"SCI_LEXER",
			"WX_PRECOMP=1",
			"wxUSE_UNICODE_UTF8=0",
			"wxUSE_UNICODE_WCHAR=1",
			"__WXOSX_COCOA__",
			"WXROOT=$(PROJECT_DIR)/Dependencies/wxWidgets-3.0.2",
			"__MACOSX_CORE__",
		}
	)
	table.insert(ReleaseDefines ,
		{
			"$(WX_PREPROCESSOR_DEFINITIONS)",
			"WXBUILDING",
			"$(WXPLATFORM)",
			"__WX__",
			"wxUSE_BASE=1",
			"_FILE_OFFSET_BITS=64",
			"_LARGE_FILES",
			"MACOS_CLASSIC",
			"__WXMAC_XCODE__=1",
			"SCI_LEXER",
			"WX_PRECOMP=1",
			"wxUSE_UNICODE_UTF8=0",
			"wxUSE_UNICODE_WCHAR=1",
			"__WXOSX_COCOA__",
			"WXROOT=$(PROJECT_DIR)/Dependencies/wxWidgets-3.0.2",
			"__MACOSX_CORE__",
		}
	)
	table.insert(DebugIncludeDirs, 1,
		{"Dependencies/wxWidgets-3.0.2/build/osx/setup/cocoa/include"})
	table.insert(ReleaseIncludeDirs, 1,
		{"Dependencies/wxWidgets-3.0.2/build/osx/setup/cocoa/include"})

	table.insert(DebugIncludeDirs ,
		{
			"Dependencies/rtaudio-4.1.1",
		}
	)
	table.insert(ReleaseIncludeDirs ,
		{
			"Dependencies/rtaudio-4.1.1",
		}
	)
	
	table.insert(DebugLinkLibs,
		{
			"CoreAudio.framework",
		}
	)
	table.insert(ReleaseLinkLibs,
		{
			"CoreAudio.framework",
	}
	)
	
else

end


make_API.SetupProject (ProjectName)
make_API.SettingCppMainApplicationProject()
make_API.SettingCppFiles(ProjectName)
--Debug Setting--
make_API.SetupConfiguration("Debug", DebugDefines, "lib", DebugLibDirs, DebugLinkLibs, LinkProjects, DebugIncludeDirs, "Symbols")
--Release Setting--
make_API.SetupConfiguration("Release", ReleaseDefines, "lib", ReleaseLibDirs, ReleaseLinkLibs, LinkProjects, ReleaseIncludeDirs, "Optimize")
