#ifndef TEXTURE_H
#define TEXTURE_H

#include <vulkan/vulkan.h>

class Texture
{
public:
    Texture(/* args */) { }
    ~Texture() { }

    void createTextureImage();

    void generateMipMaps(VkImage image, VkFormat imageFormat, int32_t texWidth,
        int32_t texHeight, uint32_t mipLevels);

private:
    /* data */
};

#endif