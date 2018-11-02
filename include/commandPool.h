#ifndef COMMANDPOOL_H
#define COMMANDPOOL_H

#include <vulkan/vulkan.h>

#include "device.h"

class CommandPool
{
public:
    CommandPool(/* args */) { }
    ~CommandPool() { }

    void init(Device* inDevice);
    void cleanup();

    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer CommandBuffer);

private:
    Device* device;

    VkCommandPool vkCommandPool;
    std::vector<VkCommandBuffer> commandBuffers;

    void createCommandPool();
    void createCommandBuffers();
};

#endif