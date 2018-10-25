#ifndef RENDERER_H
#define RENDERER_H

#include <vulkan/vulkan.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

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
    VkShaderModule createShaderModule(const std::vector<char>& code);

private:
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;

    VkDescriptorSetLayout descriptorSetLayout;
    std::vector<VkDescriptorSet> descriptorSets;
    VkDescriptorPool descriptorPool;

    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    
    VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;

    void createRenderPass();
    void createGraphicsPipeline();

    // ! Moved from Application, still might not be the right place
    void createDescriptorSetLayout();
    void createDescriptorSets();
    void createDescriptorPool();

    // ! Might need to go in device.h instead
    void createVertexBuffer();
    void createIndexBuffer();

    void createUniformBuffer();
    void updateUniformBuffer(uint32_t currentImage);

    VkFormat findDepthFormat();
};

#endif