#ifndef TEXTURE_H
#define TEXTURE_H

#include <vulkan/vulkan.h>

#include <string>

#include "device.h"

class Texture
{
public:
    Texture(/* args */) { }
    ~Texture() { }

    void cleanup();
    
    void loadTextureFromFile(std::string path);
    void createTextureImage();

private:
    Device* device;

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