cmake_minimum_required(VERSION 3.26.4)

if(MSVC)
    set(CMAKE_GENERATOR_TOOLSET "v143" CACHE STRING "Platform Toolset" FORCE) 
endif()

project(universal-logger LANGUAGES C CXX)

add_compile_options(/W4 /WX)

add_subdirectory(src lib)
