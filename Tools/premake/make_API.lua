-- make_API --
module("make_API", package.seeall)

function SetupProject(projectName)

end

function SetupConfiguration(targetConfig, define, targetDir, libDirs, includeDirs, flag)
	configuration (targetConfig)
	
	if (os.get() == "windows") then
		defines(define)
		targetdir(targetDir)
		libdirs(libDirs)
		includedirs(includeDirs)
		flags(flag)
	elseif (os.get() == "macosx") then
		
	else
		
	end
end



