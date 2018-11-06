#ifndef QUEUEFAMILY_H
#define QUEUEFAMILY_H
#pragma once

#include <algorithm>

struct QueueFamilyIndices
{
    uint32_t graphicsFamily, presentFamily;
    bool graphicsFamilySet, presentFamilySet = false;

    void setGraphicsFamily(uint32_t value)
    {
        graphicsFamily = value;
        graphicsFamilySet = true;
    }

    void setPresentFamily(uint32_t value)
    {
        presentFamily = value;
        presentFamilySet = true;
    }

    bool isComplete() {
        return graphicsFamilySet && presentFamilySet;
    }
};

#endif