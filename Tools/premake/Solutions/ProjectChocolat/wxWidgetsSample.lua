-- wxWidgetsSample  --
module("wxWidgetsSample", package.seeall)
local ProjectName = "wxWidgetsSample"
local DebugDefines =
{
	"DEBUG",
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
	"wxUSE_UNICODE_WCHAR=1"
}
local ReleaseDefines =
{
	"NDEBUG",
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
	"wxUSE_UNICODE_WCHAR=1"
}
local LinkProjects =
{
	"Dependencies/wxWidgets-3.0.2/include/",
	"Dependencies/wxWidgets-3.0.2/include/**",
	"Dependencies/wxWidgets-3.0.2/samples/",
--	"Dependencies/wxWidgets-3.0.2/include/msvc"
}
make_API.SetupProject (ProjectName)
make_API.SettingCppApplicationProject()
make_API.SettingCppFiles(ProjectName)
--Debug Setting--
make_API.SetupConfiguration("Debug", DebugDefines, "lib", "", LinkProjects, "", "Symbols")
--Release Setting--
make_API.SetupConfiguration("Release", ReleaseDefines, "lib", "", LinkProjects, "", "Optimize")
