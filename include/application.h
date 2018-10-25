#ifndef APPLICATION_H
#define APPLICATION_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <vector>

#include "swapchain.h"
#include "device.h"


const int WIDTH = 800;
const int HEIGHT = 600;

const std::string MODEL_PATH = "../models/chalet.obj";
const std::string TEXTURE_PATH = "../textures/chalet.jpg";

const int MAX_FRAMES_IN_FLIGHT = 2;

class Application
{
public:
    void run();

private:
    // ! May want to create Window class
    GLFWwindow* window;
    
    VkInstance instance;
    VkDebugUtilsMessengerEXT callback;
    VkSurfaceKHR surface;
    
    Device device;

    SwapChain swapChain;

    VkCommandPool commandPool;
    std::vector<VkCommandBuffer> commandBuffers;

    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;

    size_t currentFrame = 0;

    bool framebufferResized = false;

    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;

    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;

    uint32_t mipLevels;
    VkSampler textureSampler;



    static void framebufferResizeCallback(GLFWwindow* window, int width, int height)
    {
        auto app = reinterpret_cast<Application*>(glfwGetWindowUserPointer(window));
        app->framebufferResized = true;
    }

    void initVulkan();
    void cleanup();
    void mainLoop();
    void createInstance();
    void initWindow();
    void createSurface();
    void setupDebugCallback();

    void createSyncObjects();
    void verifyExtensions();
    bool checkValidationLayerSupport();
    std::vector<const char*> getRequiredExtensions();

    // ! May need to move
    void createCommandBuffers();

};

#endif