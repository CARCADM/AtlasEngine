cmake_minimum_required(VERSION 3.31)


project("AtlasEngine")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)

add_executable(AtlasEngine 
TestEntry.cpp
_dependencies/glad/src/glad.c)

target_link_libraries(AtlasEngine
PRIVATE
${CMAKE_SOURCE_DIR}/_dependencies/libSDL3.a
opengl32
PUBLIC
-lwinmm 
-lsetupapi 
-limm32 
-lversion 
-lcfgmgr32)

target_include_directories(AtlasEngine 
PRIVATE 
${CMAKE_SOURCE_DIR}/_dependencies
${CMAKE_SOURCE_DIR}/_dependencies/glad/include/glad
)

add_subdirectory(${CMAKE_SOURCE_DIR}/Window)
add_subdirectory(${CMAKE_SOURCE_DIR}/Renderer)
add_subdirectory(${CMAKE_SOURCE_DIR}/Util)