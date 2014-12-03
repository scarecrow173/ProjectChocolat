-- Framework  --
module("Framework", package.seeall)
local ProjectName = "Framework" 
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
		configuration "Debug"
			defines
			{
				"DEBUG"
			}
			flags
			{
				"Symbols"
			}

		configuration "Release"
			defines
			{
				"NDEBUG"
			}
			flags
			{
				"Optimize"
			}
