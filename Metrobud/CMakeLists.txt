# Create the Metrobud executable
add_executable(Metrobud)

# Find source files
file(GLOB_RECURSE METROBUD_SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
)

target_sources(Metrobud PRIVATE ${METROBUD_SOURCES})

# Set include directories
target_include_directories(Metrobud
    PRIVATE
        ${CMAKE_SOURCE_DIR}/thirdparty/include/SDL3
        ${CMAKE_SOURCE_DIR}/thirdparty/include/glad
        ${CMAKE_SOURCE_DIR}/thirdparty/include/glm
        ${CMAKE_SOURCE_DIR}/thirdparty/include/imgui
        ${CMAKE_SOURCE_DIR}/AuraEngine/src
)

# Link libraries
target_link_libraries(Metrobud
    PRIVATE
        AuraEngine
)

# Post-build command to copy SDL3.dll
add_custom_command(TARGET Metrobud POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
        ${CMAKE_SOURCE_DIR}/thirdparty/lib/SDL3/SDL3.dll
       ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/SDL3.dll
)