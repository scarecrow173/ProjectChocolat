-- File  --
module("File", package.seeall)
local ProjectName = "File" 
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
