#ifndef DEVICE_H
#define DEVICE_H

#include <vulkan/vulkan.h>

class Device
{
private:
    findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

public:
    Device(/* args */);
    ~Device();

    void createLogicalDevice();
    void createTextureSampler();
    VkImageView createImageView(VkImage image, VkFormat format,
        VkImageAspectFlags aspectFlags, uint32_t mipLevels);

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    VkSampleCountFlagBits getMaxUsableSampleCount();

};

#endif