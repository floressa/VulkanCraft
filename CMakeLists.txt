cmake_minimum_required(VERSION 3.0.0)
project(VulkanCraft)

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

include_directories($(PROJECT_SOURCE_DIR)/lib)
add_subdirectory(lib)

add_executable(${PROJECT_NAME} main.cpp)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} lib)
endif()