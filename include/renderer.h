#ifndef RENDERER_H
#define RENDERER_H

#include <vulkan/vulkan.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include "device.h"
#include "swapchain.h"
#include "vertex.h"

struct UniformBufferObject
{
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 proj;
};

class Renderer
{
public:
    Renderer(/* args */) { }
    ~Renderer() { }

    void init();

    void drawFrame();

private:
    Device* device;
    SwapChain swapChain;

    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;

    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;

    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;

    VkDescriptorSetLayout descriptorSetLayout;
    std::vector<VkDescriptorSet> descriptorSets;
    VkDescriptorPool descriptorPool;
    VkSampler textureSampler;

    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    
    VkImage textureImage;
    VkDeviceMemory textureImageMemory;
    VkImageView textureImageView;

    uint32_t mipLevels;

    size_t currentFrame = 0;
    
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;


    // ! Moved from Application, still might not be the right place
    void createDescriptorSetLayout();
    void createDescriptorSets();
    void createDescriptorPool();

    // ! Might need to go in device.h instead
    void createVertexBuffer();
    void createIndexBuffer();
    void createUniformBuffers();
    void updateUniformBuffer(uint32_t currentImage);

    void createTextureImageView();
    
    // ! Texture samplers might not be necessary for this project but I will
    // ! add the structure needed to use them in Vulkan anyways for now
    void createTextureSampler();

    VkFormat findDepthFormat();
};

#endif