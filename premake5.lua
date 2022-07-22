workspace "RefraEngine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--Include directories relative to root folder (solution dir)
IncludeDir = {}
IncludeDir["GLFW"] = "Engine/vendor/GLFW/include"

include "Engine/vendor/GLFW"
--END

project "Engine"
	location "Engine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/intermidiate/" .. outputdir .. "/%{prj.name}")
	
	pchheader "rfpch.h"
	pchsource "Engine/src/rfpch.cpp"
	
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}
	
	links
	{
		"GLFW",
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"RF_PLATFORM_WINDOWS",
			"RF_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
		filter "configurations:Debug"
			defines "RF_DEBUG"
			symbols "On"
			
		filter "configurations:Release"
			defines "RF_RELEASE"
			optimize "On"
		
		filter "configurations:Dist"
			defines "RF_DIST"
			optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/intermidiate/" .. outputdir .. "/%{prj.name}")
	
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Engine/vendor/spdlog/include",
		"Engine/src"
	}
	
	links
	{
		"Engine"
	}
	
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"RF_PLATFORM_WINDOWS"
		}
		
		filter "configurations:Debug"
			defines "RF_DEBUG"
			symbols "On"
			
		filter "configurations:Release"
			defines "RF_RELEASE"
			optimize "On"
		
		filter "configurations:Dist"
			defines "RF_DIST"
			optimize "On"