solution "SlidingPuzzle"
	configurations { "debug", "release" }

project "slidingpuzzle"
	kind "ConsoleApp"
	language "C++"
	files { "src/**" }
	objdir "build/obj"
	buildoptions { "-std=c++11" }

	configuration "debug"
		flags { "Symbols", "ExtraWarnings" }

	configuration "release"
		flags { "Optimize" }

