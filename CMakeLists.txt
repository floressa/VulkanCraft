cmake_minimum_required(VERSION 3.0.0)
project(VulkanCraft)

#--------------------------------------------------
# Define Build options
#--------------------------------------------------
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# C++ Build options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# C Build options
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

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

# Add the binary tree to the search path for include files
# so that we will find VulkanCraftConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# VulkanCraft specific compile options declaration
option(GNU_COMPILED "Use GNU Compiler" ON)


#--------------------------------------------------
# GLFW
#--------------------------------------------------
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Build GLFW through CMake (Also loads/links Vulkan)
add_subdirectory(external/GLFW glfw_local)


#--------------------------------------------------
# GLM
#--------------------------------------------------
set(GLM_TEST_ENABLE OFF)
set(GLM_QUIET ON)
set(GLM_INCLUDE_DIR "external/glm/glm")

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE "external/glm")

add_library(stb INTERFACE)
target_include_directories(stb INTERFACE "external/stb")


# Executable creation
add_executable(${PROJECT_NAME} main.cpp)


#--------------------------------------------------
# Target Definitions
#--------------------------------------------------
target_link_libraries(${PROJECT_NAME} glfw ${VULKAN_LIBRARY} glm stb)

if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE VK_USE_PLATFORM_WIN32_KHR)
endif()
