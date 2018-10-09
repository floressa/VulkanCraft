cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

project(VulkanCraft)

include_directories(lib)
include_directories(lib/include/GLM)
add_subdirectory(lib)

add_executable(${PROJECT_NAME} main.cpp)

find_package(glfw3 3.2 REQUIRED)
find_package(Vulkan REQUIRED)

target_include_directories(${PROJECT_NAME} ${Vulkan_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${Vulkan_LIBRARIES})

#target_link_libraries(${PROJECT_NAME} lib)