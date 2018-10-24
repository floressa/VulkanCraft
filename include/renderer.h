#ifndef RENDERER_H
#define RENDERER_H

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
private:
    /* data */
    VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;

public:
    Renderer(/* args */) { }
    ~Renderer() { }

    void drawFrame();
    void createRenderPass();
    void createGraphicsPipeline();
    VkShaderModule createShaderModule(const std::vector<char>& code);

};

#endif