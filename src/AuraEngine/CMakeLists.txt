file(GLOB_RECURSE SOURCE_FILES "*.cpp")
add_library(AuraEngine STATIC ${SOURCE_FILES})

set_target_properties(AuraEngine PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

target_compile_features(AuraEngine PUBLIC cxx_std_23)
target_compile_options(AuraEngine PUBLIC -Wall -Werror)

target_include_directories(AuraEngine PRIVATE .)
target_include_directories(AuraEngine PRIVATE ../../vendor/include)

target_link_libraries(AuraEngine glfw3)