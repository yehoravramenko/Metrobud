file(GLOB_RECURSE SOURCE_FILES "*.cpp")
add_executable(metrobud ${SOURCE_FILES})

set_target_properties(metrobud PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_compile_features(metrobud PUBLIC cxx_std_23)
target_compile_options(metrobud PUBLIC -Wall -Werror)

target_include_directories(metrobud PRIVATE .)
target_include_directories(metrobud PRIVATE ../vendor/include)

target_link_libraries(metrobud glfw3)