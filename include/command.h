#ifndef COMMAND_H
#define COMMAND_H

#include <vulkan/vulkan.h>

class Command
{
private:
    /* data */
public:
    Command(/* args */) { }
    ~Command() { }

    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);
};

#endif