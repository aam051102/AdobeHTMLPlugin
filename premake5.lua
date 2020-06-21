include "conanbuildinfo.premake.lua"


workspace "AdobeHTMLPlugin"
    conan_basic_setup()
    architecture "x64"
    startproject "Sandbox"
    
    libjsonSrc = "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/"

    configurations {
        "Debug",
        "Release"
    }

    project "AdobeHTMLPlugin"
        kind "SharedLib"
        language "C++"
        cppdialect "C++14"
        staticruntime "off"

        targetdir "$(SolutionDir)extension\\plugin\\lib\\win"
        objdir "$(SolutionDir)project\\obj"
        linkoptions { conan_exelinkflags }

        buildoptions { "/Zc:wchar_t-" }

        defines {
            "_WINDOWS",
            "USE_HTTP_SERVER",
            "USE_RUNTIME"
        }

        files {
            "project/include/**.h",
            "project/src/**.cpp",
            "%{libjsonSrc}JSONAllocator.cpp",
            "%{libjsonSrc}JSONChildren.cpp",
            "%{libjsonSrc}JSONDebug.cpp",
            "%{libjsonSrc}JSONIterators.cpp",
            "%{libjsonSrc}JSONMemory.cpp",
            "%{libjsonSrc}JSONNode.cpp",
            "%{libjsonSrc}JSONNode_Mutex.cpp",
            "%{libjsonSrc}JSONPreparse.cpp",
            "%{libjsonSrc}JSONStream.cpp",
            "%{libjsonSrc}JSONValidator.cpp",
            "%{libjsonSrc}JSONWorker.cpp",
            "%{libjsonSrc}JSONWriter.cpp",
            "%{libjsonSrc}internalJSONNode.cpp",
            "%{libjsonSrc}libjson.cpp",
            "project/lib/ThirdParty/mongoose/mongoose.c"
        }

        includedirs {
            "$(SolutionDir)project/include",
            "$(SolutionDir)project/lib",
            "$(SolutionDir)project/lib/xdk/core/include/common",
            "$(SolutionDir)project/lib/xdk/core/include/interfaces",
            "$(SolutionDir)project/lib/xdk/app/include/common",
            "$(SolutionDir)project/lib/xdk/app/include/interfaces",
            "$(SolutionDir)project/lib/xdk/app/include/interfaces/DOM",
            "$(SolutionDir)project/lib/xdk/app/include/interfaces/Exporter",
            "$(SolutionDir)project/lib/ThirdParty/libjson_7.6.1/libjson",
            "$(SolutionDir)project/lib/ThirdParty/mongoose"
        }

        postbuildcommands {
            "if exist \"$(SolutionDir)extension\\plugin\\lib\\win\\$(TargetName).fcm\" del /Q \"$(SolutionDir)extension\\plugin\\lib\\win\\$(TargetName).fcm\"",
            "ren \"$(SolutionDir)extension\\plugin\\lib\\win\\$(TargetName).dll\" \"$(TargetName).fcm\"",
            "fc /b \"$(SolutionDir)node_modules\\animejs\\lib\\anime.min.js\" \"$(SolutionDir)extension\\Runtime\\runtime\\anime.min.js\" > nul",
            "if errorlevel 1 ( copy \"$(SolutionDir)node_modules\\animejs\\lib\\anime.min.js\" \"$(SolutionDir)extension\\Runtime\\runtime\\anime.min.js\" )",
            "call node \"$(SolutionDir)index.js\"",
        }

        filter "configurations:Debug"
            defines "_DEBUG"
            runtime "Debug"
            symbols "on"

            defines {
                "DEBUG"
            }

            postbuildcommands {
                "ren \"$(SolutionDir)build\\*.zxp\" \"$(TargetName).zxp\"",
                "cd \"$(SolutionDir)exman\"",
                "call ExManCmd.exe /install \"$(SolutionDir)build\\$(TargetName).zxp\""
            }
        
        filter "configurations:Release"
            defines "_RELEASE"
            runtime "Release"
            optimize "on"

            defines {
                "NDEBUG"
            }