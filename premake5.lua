workspace "Ymir"
    architecture "x64"
    startproject "Sandbox"

    configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ymir"
	location "Ymir"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

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
			"YM_PLATFORM_WINDOWS",
			"YM_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "YM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "YM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "YM_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Ymir/vendor/spdlog/include",
		"Ymir/src"
	}

	links
	{
		"Ymir"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"YM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "YM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "YM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "YM_DIST"
		optimize "On"