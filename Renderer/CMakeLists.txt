target_include_directories(AtlasEngine
PRIVATE
${CMAKE_SOURCE_DIR}/Renderer
)

target_sources(AtlasEngine
PRIVATE
${CMAKE_SOURCE_DIR}/Renderer/MainRenderLoop.cpp)