#ifndef SWAPCHAIN_H
#define SWAPCHAIN_H

#include <vulkan/vulkan.h>

#include <vector>

#include "device.h"

struct SwapChainSupportDetails
{
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};

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

private:
    Device* device;

    VkSwapchainKHR swapChainKHR;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    
    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;

    void createImageViews();
    void createFrameBuffers();

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

};

#endif