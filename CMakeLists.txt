cmake_minimum_required(VERSION 3.0.0)

project(VulkanCraft)

set(EXECUTABLE_OUTPUT_PATH ./${CMAKE_BUILD_TYPE})

set(SOURCE main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

target_include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/lib/include/GLFW)
set(HEADER_FILES )

if(WIN32)
    target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/libs/windows/x64/GLFW/glfw3.lib)
endif()