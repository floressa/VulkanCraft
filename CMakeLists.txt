cmake_minimum_required(VERSION 3.0.0)

project(VulkanCraft)

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


#--------------------------------------------------
# VulkanCraft Compile options declaration
#--------------------------------------------------
option(GNU_COMPILED "Use GNU Compiler" ON)
option(AUTO_LOCATE_VULKAN "AUTO_LOCATE_VULKAN" ON)


#--------------------------------------------------
# GLFW
#--------------------------------------------------
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(lib/GLFW)


#--------------------------------------------------
# GLM
#--------------------------------------------------
set(GLM_TEST_ENABLE OFF)
set(GLM_QUIET OFF)

set(GLM_INCLUDE_DIR "lib/GLM/glm")
include_directories(${GLM_INCLUDE_DIR})


#--------------------------------------------------
# Vulkan
#--------------------------------------------------
if (AUTO_LOCATE_VULKAN)
    # Auto find Vulkan with CMake 3.7 or greater
    find_package(Vulkan)

    # Try extracting VulkanSDK path from ${Vulkan_INCLUDE_DIRS}
    if (NOT ${Vulkan_INCLUDE_DIRS} STREQUAL "")
        set(VULKAN_PATH ${Vulkan_INCLUDE_DIRS})
        STRING(REGEX REPLACE "/Include" "" VULKAN_PATH ${VULKAN_PATH})
    endif()

    if(NOT Vulkan_FOUND)
		# CMake may fail to locate the libraries but could be able to 
		# provide some path in Vulkan SDK include directory variable
		# 'Vulkan_INCLUDE_DIRS', try to extract path from this.
		message(STATUS "Failed to locate Vulkan SDK, retrying again...")
		if(EXISTS "${VULKAN_PATH}")
            message(STATUS "Successfully located the Vulkan SDK: ${VULKAN_PATH}")
            set(Vulkan_LIBRARY ${VULKAN_PATH})
            find_package(Vulkan)
		else()
			message("Error: Unable to locate Vulkan SDK. Please turn off auto locate option by specifying 'AUTO_LOCATE_VULKAN' as 'OFF'")
			message("and specify manually path using 'VULKAN_SDK' and 'VULKAN_VERSION' variables in the CMakeLists.txt.")
			return()
        endif()
    endif()
endif()


# Executable creation
add_executable(${PROJECT_NAME} main.cpp)


#--------------------------------------------------
# Target Definitions
#--------------------------------------------------
target_include_directories(${PROJECT_NAME} PUBLIC ${VULKAN_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} ${VULKAN_LIBRARY})

if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE VK_USE_PLATFORM_WIN32_KHR)
endif()


#--------------------------------------------------
# Define C++ Build options
#--------------------------------------------------
set_target_properties(${PROJECT_NAME} PROPERTIES 
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")


#--------------------------------------------------
# Define C version to be used for building the project
#--------------------------------------------------
set_target_properties(${PROJECT_NAME} PROPERTIES
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
)