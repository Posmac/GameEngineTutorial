workspace "RefraEngine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GameEngineSeries"
	location "GameEngineSeries"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/intermidiate/" .. outputdir .. "/%{prj.name}")
	
	pchheader "rfpch.h"
	pchsource "GameEngineSeries/src/rfpch.cpp"
	
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
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
		"GameEngineSeries/vendor/spdlog/include",
		"GameEngineSeries/src"
	}
	
	links
	{
		"GameEngineSeries"
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