target_include_directories(AtlasEngine
PRIVATE
${CMAKE_SOURCE_DIR}/Util
)

target_sources(AtlasEngine
PRIVATE
${CMAKE_SOURCE_DIR}/Util/Entity.cpp)