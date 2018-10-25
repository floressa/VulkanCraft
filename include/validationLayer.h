#ifndef VALIDATIONLAYER_H
#define VALIDATIONLAYER_H

#include <vector>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

const std::vector<const char*> validationLayers = {"VK_LAYER_LUNARG_standard_validation"};

class ValidationLayer
{
public:
    ValidationLayer(/* args */) { }
    ~ValidationLayer() { }

private:
    /* data */
};

#endif