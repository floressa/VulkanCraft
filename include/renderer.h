#pragma once

#include <vulkan/vulkan.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

#include "commandPool.h"
#include "swapchain.h"

// Temporary hard-coded paths
const std::string TEXTURE_PATH = "../textures/chalet.jpg";
const std::string MODEL_PATH = "../models/chalet.obj";

class Device;
class Mesh;
class Texture;
struct Vertex;

struct UniformBufferObject
{
    glm::mat4 model;
    glm::mat4 view;
    glm::mat4 proj;
};

class Renderer
{
public:
    void init(Device* inDevice);
    void drawFrame();
    void cleanupSwapChain();
    void cleanup();

private:
    Device* device;

    SwapChain swapChain;
    CommandPool commandPool;

    std::vector<Texture> textures;
    std::vector<Mesh> meshes;

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

    size_t currentFrame = 0;
    
    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;

    void createSyncObjects();

    // ! Moved from Application, still might not be the right place
    void createDescriptorSetLayout();
    void createDescriptorSets();
    void createDescriptorPool();

    // ! Might need to go in device.h instead
    void createVertexBuffer();
    void createIndexBuffer();
    void createUniformBuffers();
    void updateUniformBuffer(uint32_t currentImage);
    
    // ! Texture samplers might not be necessary for this project but I will
    // ! add the structure needed to use them in Vulkan anyways for now
    void createTextureSampler();

    VkFormat findDepthFormat();
};
