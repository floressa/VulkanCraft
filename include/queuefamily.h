#ifndef QUEUEFAMILY_H
#define QUEUEFAMILY_H

#include <algorithm>
#include <optional>

struct QueueFamilyIndices
{
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        if (graphicsFamily)
        {
            return true;
        } 
        else {
            return false;
        }
    }
};

#endif