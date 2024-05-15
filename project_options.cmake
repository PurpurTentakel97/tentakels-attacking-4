include(${CMAKE_SOURCE_DIR}/cmake/warnings.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/sanitizers.cmake)

# the following function was taken from:
# https://github.com/cpp-best-practices/cmake_template/blob/main/ProjectOptions.cmake
macro(check_sanitizer_support)
    if ((CMAKE_CXX_COMPILER_ID MATCHES ".*Clang.*" OR CMAKE_CXX_COMPILER_ID MATCHES ".*GNU.*") AND NOT WIN32)
        set(supports_ubsan ON)
    else ()
        set(supports_ubsan OFF)
    endif ()

    if ((CMAKE_CXX_COMPILER_ID MATCHES ".*Clang.*" OR CMAKE_CXX_COMPILER_ID MATCHES ".*GNU.*") AND WIN32)
        set(supports_asan OFF)
    else ()
        set(supports_asan ON)
    endif ()
endmacro()

check_sanitizer_support()

if (PROJECT_IS_TOP_LEVEL)
    option(attacking_warnings_as_errors "Treat warnings as errors" ON)
    option(attacking_enable_undefined_behavior_sanitizer "Enable undefined behavior sanitizer" ${supports_ubsan})
    option(attacking_enable_address_sanitizer "Enable address sanitizer" ${supports_asan})
    option(attacking_tests "Build tests using Google Test" ON)
else ()
    option(attacking_warnings_as_errors "Treat warnings as errors" OFF)
    option(attacking_enable_undefined_behavior_sanitizer "Enable undefined behavior sanitizer" OFF)
    option(attacking_enable_address_sanitizer "Enable address sanitizer" OFF)
    option(attacking_tests "Build tests using Google Test" OFF)
endif ()

add_library(attacking_warnings INTERFACE)
set_warnings(attacking_warnings ${attacking_warnings_as_errors})

add_library(attacking_sanitizers INTERFACE)
enable_sanitizers(attacking_sanitizers ${attacking_enable_address_sanitizer} ${attacking_enable_undefined_behavior_sanitizer})

add_library(attacking_project_options INTERFACE)
target_link_libraries(attacking_project_options
                      INTERFACE attacking_warnings
                      INTERFACE attacking_sanitizers
)