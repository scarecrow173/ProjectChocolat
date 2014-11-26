-- premake.lua --
solution "ProjectChocolat"
	configurations { "Debug", "Release" }

	project "Demo"
		kind "ConsoleApp"
		language "C++"
		files
		{
			"Source/**.h",
			"Source/**.c",
			"Source/**.hpp",
			"Source/**.cpp",
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