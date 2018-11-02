#ifndef TEXTURE_H
#define TEXTURE_H

#include <vulkan/vulkan.h>

#include <string>

#include "device.h"

class Texture
{
public:
    Texture(std::string inPath) : path(inPath) {}
    ~Texture() { }

    void cleanup();
    
    void load();
    void createTextureImage();

private:
    Device* device;

    std::string path;

    int texWidth;
    int texHeight;
    int texChannels;

    stbi_uc* pixels;

    uint32_t mipLevels;

    VkImage textureImage;
    VkImageView textureImageView;
    VkDeviceMemory textureImageMemory;

    void createTextureImageView();
    void generateMipMaps(VkImage image, VkFormat imageFormat, int32_t texWidth,
        int32_t texHeight, uint32_t mipLevels);
};

#endif