# Create the AuraEngine shared library
add_library(AuraEngine SHARED)

# Add compile definition for DLL export
target_compile_definitions(AuraEngine PRIVATE AE_BUILD_DLL)

# Find source files
file(GLOB_RECURSE AURAENGINE_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"

    "${CMAKE_SOURCE_DIR}/thirdparty/src/imgui/*.cpp"
)

# Add glad source
list(APPEND AURAENGINE_SOURCES "${CMAKE_SOURCE_DIR}/thirdparty/src/glad.c")

target_sources(AuraEngine PRIVATE ${AURAENGINE_SOURCES})

# Set include directories
target_include_directories(AuraEngine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/AuraEngine
    PRIVATE
        ${CMAKE_SOURCE_DIR}/thirdparty/include/glad
        ${SDL3_INCLUDE_DIR}
        ${CMAKE_SOURCE_DIR}/thirdparty/include/stb
        ${CMAKE_SOURCE_DIR}/thirdparty/include/glm
        ${CMAKE_SOURCE_DIR}/thirdparty/include/imgui
)

# Link libraries
target_link_libraries(AuraEngine
    PRIVATE
        opengl32
        SDL3
)

# Post-build command to copy DLL
add_custom_command(TARGET AuraEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        $<TARGET_FILE:AuraEngine>
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Metrobud/$<TARGET_FILE_NAME:AuraEngine>
)