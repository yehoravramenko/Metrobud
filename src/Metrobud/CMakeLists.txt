file(GLOB_RECURSE SOURCE_FILES "*.cpp")
add_executable(Metrobud ${SOURCE_FILES})

set_target_properties(Metrobud PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_DIR}/bin"
)

target_compile_features(Metrobud PUBLIC cxx_std_23)
target_compile_options(Metrobud PUBLIC -Wall -Werror)

target_include_directories(Metrobud PRIVATE .)
target_include_directories(Metrobud PRIVATE ..)
target_include_directories(Metrobud PRIVATE ../AuraEngine)
target_include_directories(Metrobud PRIVATE ../../vendor/include)

link_directories("${CMAKE_BINARY_DIR}/lib")

target_link_libraries(Metrobud AuraEngine)


if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set_property(TARGET Metrobud PROPERTY CXX_STANDARD_LIBRARIES optimized) # Release-specific libraries
    string(REPLACE "-g" "" CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}") # Remove -g (GCC/Clang)
else()
    set_property(TARGET Metrobud PROPERTY CXX_STANDARD_LIBRARIES debug) # Debug-specific libraries
    set(OUTPUT_NAME "Metrobud_debug")
endif()