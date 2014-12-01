-- Core  --

--table.insert(ProjectChocolat.Project_Table, "Core")
	project "../../../Core"
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
