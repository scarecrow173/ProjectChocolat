-- make_API --
module("make_API", package.seeall)
----------------------------------
--	Setup Project				--
----------------------------------
function SetupProject(projectName)
	project(projectName)
	pchheader(projectName .. ".h")
	pchsource(projectName .. ".cpp")
	buildoptions("/Yc" .. projectName .. ".h")

end
----------------------------------
--	Config Setting				--
----------------------------------
function SetupConfiguration(targetConfig, define, targetDir, libDirs, linkLibs, includeDirs, flag)
	configuration (targetConfig)
	
	if (os.get() == "windows") then
		defines(define)
		targetdir("Bin" .. "/" .. targetConfig .. "/" .. targetDir)
		libdirs("Bin" .. "/" .. targetConfig .. "/" .. "lib")
		links(linkLibs)
		includedirs(linkLibs)
		includedirs(includeDirs)
		flags(flag)
	elseif (os.get() == "macosx") then
		
	else
		
	end
end
----------------------------------
--	C++ Static Lib Setting		--
----------------------------------
function SettingCppStaticLibProject()
	kind "StaticLib"
	language "C++"
end
----------------------------------
--	C++ Static Lib Setting		--
----------------------------------
function SettingCppApplicationProject()
	kind "ConsoleApp"
	language "C++"
end
----------------------------------
--	C++ Files Dir Setting		--
----------------------------------
function SettingCppFiles(projectName)
	files
	{
		projectName .. "/**.h",
		projectName .. "/**.c",
		projectName .. "/**.hpp",
		projectName .. "/**.cpp",
	}
end