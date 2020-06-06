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
        cppdialect "C++14"
        staticruntime "off"

        targetdir "$(SolutionDir)extension\\plugin\\lib\\win"
        objdir "$(SolutionDir)project\\obj"
        linkoptions { conan_exelinkflags }

        buildoptions { "/Zc:wchar_t-" }
        postbuildcommands { "if exist \"$(SolutionDir)extension\\plugin\\lib\\win\\$(TargetName).fcm\" del /Q \"$(SolutionDir)extension\\plugin\\lib\\win\\$(TargetName).fcm\"", "ren \"$(SolutionDir)extension\\plugin\\lib\\win\\$(TargetName).dll\" \"$(TargetName).fcm\"" }

        defines {
            "_WINDOWS",
            "USE_HTTP_SERVER",
            "USE_RUNTIME",
            "NDEBUG"
        }

        files
        {
            "project/include/**.h",
            "project/src/**.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/JSONAllocator.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/JSONChildren.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/JSONDebug.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/JSONIterators.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/JSONMemory.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/JSONNode.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/JSONNode_Mutex.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/JSONPreparse.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/JSONStream.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/JSONValidator.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/JSONWorker.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/JSONWriter.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/internalJSONNode.cpp",
            "project/lib/ThirdParty/libjson_7.6.1/libjson/_internal/Source/libjson.cpp",
            "project/lib/ThirdParty/mongoose/mongoose.c"
        }

        includedirs
        {
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

        filter "configurations:Debug"
            defines "_DEBUG"
            runtime "Debug"
            symbols "on"
        
        filter "configurations:Release"
            defines "_RELEASE"
            runtime "Release"
            optimize "on"