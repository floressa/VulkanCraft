#ifndef DEVICE_H
#define DEVICE_H

#include <vulkan/vulkan.h>

#include <vector>

#include "queuefamily.h"

const std::vector<const char*> deviceExtensions = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};

class Device
{
public:
    Device(/* args */);
    ~Device();

    void init(VkInstance instance);

    VkPhysicalDevice& getPhysicalDevice() { return &physicalDevice; }
    VkDevice& getLogicalDevice() { return &device; }

    QueueFamilyIndices findQueueFamilies();

    VkFormat findSupportedFormat(const std::vector<VkFormat>& candidates,
        VkImageTiling tiling, VkFormatFeatureFlags features);
   

    void createImage(uint32_t width, uint32_t height, uint32_t mipLevels,
        VkSampleCountFlagBits numSamples, VkFormat format, VkImageTiling tiling,
        VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image,
        VkDeviceMemory& imageMemory);
    
    void transitionImageLayout(VkImage image, VkFormat format,
        VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);

    VkImageView createImageView(VkImage image, VkFormat format,
        VkImageAspectFlags aspectFlags, uint32_t mipLevels);
    

    void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties,
        VkBuffer& buffer, VkDeviceMemory& bufferMemory);

    void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
    void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);

    VkSampleCountFlagBits getMaxUsableSampleCount();
    VkQueue getPresentQueue() { return presentQueue; }
    VkQueue getGraphicsQueue() { return graphicsQueue; }


private:
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkDevice device;  // Logical device
    VkQueue graphicsQueue;
    VkQueue presentQueue;

    void pickPhysicalDevice(VkInstance instance);
    bool isDeviceSuitable(VkPhysicalDevice device);
    void createLogicalDevice();

    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

    // ! Temporarily a helper function, will see if necessary to remain as such
    QueueFamilyIndices findQueueFamiliesHelper(VkPhysicalDevice device);
    
    // ! May need to move this
    bool hasStencilComponent(VkFormat format);
};

#endif
