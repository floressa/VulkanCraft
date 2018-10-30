#ifndef TEXTURE_H
#define TEXTURE_H

#include <vulkan/vulkan.h>

#include <string>

class Texture
{
public:
    Texture(/* args */) { }
    ~Texture() { }

    void cleanup();
    
    void createTextureImage(std::string path);

private:
    Device* device;

    uint32_t mipLevels;

    VkImage textureImage;
    VkImageView textureImageView;
    VkDeviceMemory textureImageMemory;

    void createTextureImageView();
    void generateMipMaps(VkImage image, VkFormat imageFormat, int32_t texWidth,
        int32_t texHeight, uint32_t mipLevels);
};

#endif