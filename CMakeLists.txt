# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (Tutorials)
# set(CMAKE_CXX_COMPILER "D:\\MinGW\\bin\\g++.exe" )
# set(CMAKE_C_COMPILER "D:\\MinGW\\bin\\gcc.exe" )


find_package(OpenGL REQUIRED)



if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



# Compile external dependencies 
add_subdirectory (external)



# if(INCLUDE_DISTRIB)
# 	add_subdirectory(distrib)
# endif(INCLUDE_DISTRIB)



include_directories(
	
	external/AntTweakBar-1.16/include/
	external/glfw-3.1.2/include/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
	external/assimp-3.0.1270/include/
	external/bullet-2.81-rev2613/src/
	common/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_1130
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# Tutorial 1
add_executable(CG
	common/shader.cpp
	common/shader.hpp
	common/controls.hpp
	common/controls.cpp
	shader/fragment.glsl
	shader/vertex.glsl
	src/CG.cpp
)
target_link_libraries(tutorial01_first_window
	${ALL_LIBS}
)
SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )
