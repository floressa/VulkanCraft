cmake_minimum_required(VERSION 3.0.0)
project(VulkanCraftEngine)

#--------------------------------------------------
# Define Build options
#--------------------------------------------------
option(GCC_RELEASE_MODE "Use Vulkan Optimizations" ON)
if (CMAKE_COMPILER_IS_GNUCC)
    option(ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" FALSE)

    if (ENABLE_COVERAGE)
        add_compile_options(--coverage -O0)
    endif()
endif()

if (GCC_RELEASE_MODE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_RELEASE_COMPILE_FLAGS}")
endif()


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
# Not sure if this is necessary
# set(GCC_RELEASE_COMPILE_FLAGS "-O3")

# C++ Build options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# C Build options
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Static Library Link to make .exe copyable under Windows
if (WIN32)
    set(CMAKE_EXE_LINKER_FLAGS -static)
endif()

# Necessary on Windows
include_directories("$ENV{VULKAN_SDK}/Include")


#--------------------------------------------------
# CMake Config header
#--------------------------------------------------
# Configure a header file to pass some of the CMake settings
# to the source code
configure_file(
    "${PROJECT_SOURCE_DIR}/cmake/VulkanCraftConfig.h.in"
    "${PROJECT_BINARY_DIR}/VulkanCraftConfig.h"
)

# VulkanCraft specific compile options declaration
# option(GNU_COMPILED "Use GNU Compiler" OFF)

# Add the binary tree to the search path for include files
# so that we will find VulkanCraftConfig.h
include_directories("${PROJECT_BINARY_DIR}")


#--------------------------------------------------
# GLFW
#--------------------------------------------------
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Build GLFW through CMake (Also loads/links Vulkan)
add_subdirectory(external/glfw glfw_local)


#--------------------------------------------------
# GLM
#--------------------------------------------------
set(GLM_TEST_ENABLE OFF)
set(GLM_QUIET ON)
set(GLM_INCLUDE_DIR "external/glm/glm")

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE "external/glm")


#--------------------------------------------------
# Header Libraries
#--------------------------------------------------
add_library(stb INTERFACE)
target_include_directories(stb INTERFACE "external/stb")

add_library(tinyobjloader INTERFACE)
target_include_directories(tinyobjloader INTERFACE "external/tinyobjloader")


#--------------------------------------------------
# VulkanCraft Files
#--------------------------------------------------
file(GLOB_RECURSE vce_includes include/*)
file(GLOB_RECURSE vce_sources src/*)
set(SOURCE_FILES ${vce_sources} ${vce_includes})

include_directories(include)

# Package source files as library
add_library(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} glfw ${VULKAN_LIBRARY} glm stb tinyobjloader)

# Executable creation
add_executable(VulkanCraft main.cpp)
# Link engine library to executable
target_link_libraries(VulkanCraft ${PROJECT_NAME})

if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE VK_USE_PLATFORM_WIN32_KHR)
endif()
