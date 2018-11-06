#ifndef APPLICATION_H
#define APPLICATION_H
#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>

#include "device.h"
#include "renderer.h"

const int WIDTH = 800;
const int HEIGHT = 600;
const int MAX_FRAMES_IN_FLIGHT = 2;

class Application
{
public:
    Application();
    void run();

private:
    // ! May want to create separate Window class
    GLFWwindow* window;
    VkSurfaceKHR surface;
    
    VkInstance instance;
    VkDebugUtilsMessengerEXT callback;
    
    Device device;
    Renderer renderer;

    bool framebufferResized = false;


    void initWindow();
    void initVulkan();
    void cleanup();
    void mainLoop();
    void createInstance();
    void createSurface();
    void setupDebugCallback();

    void createSyncObjects();
    void verifyExtensions();
    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();

    static void framebufferResizeCallback(GLFWwindow* window, int width, int height)
    {
        auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
        app->framebufferResized = true;
    }
};

#endif