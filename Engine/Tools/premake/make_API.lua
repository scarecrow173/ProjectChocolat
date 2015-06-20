-- make_API --
module("make_API", package.seeall)
----------------------------------
--	Setup Project				--
----------------------------------
function SetupProject(projectName)
	project(projectName)
	if (os.get() == "windows") then
		pchheader(projectName .. ".h")
		pchsource(projectName .. ".cpp")
		buildoptions("/Yc" .. projectName .. ".h")
	end

end
----------------------------------
--	Config Setting				--
----------------------------------
function SetupConfiguration(targetConfig, define, targetDir, libDirs, linkLibs, LinkProjects, includeDirs, flagOption)
	configuration (targetConfig)
	defines(define)
	targetdir("Bin" .. "/" .. targetConfig .. "/" .. targetDir)

	libdirs("Bin" .. "/" .. targetConfig .. "/" .. "lib")
	libdirs(libDirs)
	links(linkLibs)

	links(LinkProjects)
	includedirs(LinkProjects)

	includedirs(includeDirs)

	if (targetConfig == "Debug") then
		flags ("Symbols")
	elseif (targetConfig == "Release") then
		flags ("Optimize")
	end

	if (os.get() == "windows") then
		defines("_CHOCOLAT_WINDOWS_")
	elseif (os.get() == "macosx") then
		defines("_CHOCOLAT_OSX_")
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
--	C++ Console Application Setting		--
----------------------------------
function SettingCppApplicationProject()
	kind "ConsoleApp"
	language "C++"
end
----------------------------------
--	C++ Console Application Setting		--
----------------------------------
function SettingCppMainApplicationProject()
	kind "WindowedApp"
	language "C++"
	flags("WinMain")
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
	includedirs(projectName)
end
----------------------------------
--	C++ Files Dir Setting		--
----------------------------------
function SettingExtensionCppFile( Path )
--	local PathTable={""}
	for i, value in pairs(Path) do
		print(value)
	end
	files(PathTable)
end