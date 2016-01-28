solution "Korv"

	location "build"
	targetdir "build"
    platforms { "x64" }
	configurations {"Debug", "Release"}    
    -- Windows compiler junk
    defines("_CRT_SECURE_NO_WARNINGS")
    defines("_CRT_NONSTDC_NO_DEPRECATE")		
	flags { "Symbols" }

project "korv-test"
    kind "ConsoleApp"
    language "C++"
    targetname "korv-test"
	includedirs { "src" }
    files { "src/**.cpp" }
	files { "tests/**.cpp" }
    files { "src/**.h" }
