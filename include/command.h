#ifndef COMMAND_H
#define COMMAND_H

#include <vulkan/vulkan.h>

#include "device.h"

class Command
{
public:
    Command(/* args */) { }
    ~Command() { }

    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);

private:
    /* data */
    Device* device;
};

#endif