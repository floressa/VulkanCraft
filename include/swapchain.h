#ifndef SWAPCHAIN_H
#define SWAPCHAIN_H

#include <vulkan/vulkan.h>

#include <vector>

#include "device.h"


class SwapChain
{
public:
    void init();

    void createSwapChain();
    void cleanup();

    // Recreates the swap chain, used in handling situations where the window surface
    // changes, such as a window resize event
    void recreateSwapChain();

    VkSwapchainKHR getKHR() { return swapChainKHR; }
    std::vector<VkImage> getImages() { return swapChainImages; }
    uint32_t getImageCount() { return swapChainImages.size(); }
    VkFormat getImageFormat() { return swapChainImageFormat; }
    VkExtent2D getExtent() { return swapChainExtent; }
    void createFrameBuffers();
    VkFormat findDepthFormat();

    // TODO: Separate shader interaction into class
    VkShaderModule createShaderModule(const std::vector<char>& code);

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device, VkSurfaceKHR surface);

private:
    Device* device;

    VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;

    VkSwapchainKHR swapChainKHR;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    
    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkRenderPass renderPass;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

    VkImage depthImage;
    VkDeviceMemory depthImageMemory;
    VkImageView depthImageView;

    VkImage colorImage;
    VkDeviceMemory colorImageMemory;
    VkImageView colorImageView;

    void createImageViews();
    void createColorResources();
    void createDepthResources();
    void createGraphicsPipeline();
    void createRenderPass();

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

};

#endif