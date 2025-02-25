file(GLOB_RECURSE SOURCE_FILES "*.cpp")
add_executable(Metrobud ${SOURCE_FILES})

set_target_properties(Metrobud PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_compile_features(Metrobud PUBLIC cxx_std_23)
target_compile_options(Metrobud PUBLIC -Wall -Werror)

target_include_directories(Metrobud PRIVATE .)
target_include_directories(Metrobud PRIVATE ..)
target_include_directories(Metrobud PRIVATE ../AuraEngine)
target_include_directories(Metrobud PRIVATE ../../vendor/include)

link_directories("${CMAKE_BINARY_DIR}/lib")

target_link_libraries(Metrobud AuraEngine)