include "conanbuildinfo.premake.lua"

workspace "AdobeHTMLPlugin"
    conan_basic_setup()
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release"
    }

    project "AdobeHTMLPlugin"
        kind "SharedLib"
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

        targetdir "extension/plugin/lib/win"
        objdir "project/obj"
        linkoptions { conan_exelinkflags }

        files
        {
            "project/include/**.h",
            "project/src/**.cpp"
        }

        includedirs
        {
            "project/include"
            "project/lib"
        }

        filter "configurations:Debug"
            defines "_DEBUG"
            runtime "Debug"
            symbols "on"
        
        filter "configurations:Release"
            defines "_RELEASE"
            runtime "Release"
            optimize "on"

        postbuildcommands { "ren $(SolutionDir)extension\plugin\lib\win\$(TargetName).dll $(SolutionDir)extension\plugin\lib\win\$(TargetName).fcm" }