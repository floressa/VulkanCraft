# VulkanCraft

A Minecraft clone implemented from scratch using Vulkan.

**- IMPORTANT - Currently the project is only Vulkan/Engine setup. The Minecraft part is very much in the beginning stages.**

Inspired by Hopson's 'Coding Minecraft in One Week' video, but using Vulkan instead of OpenGL and building with CMake as a learning exercise (...and not in a week).

## Getting Started

### Prerequisites

To build from source, a Vulkan SDK needs to be installed on your computer. The LunarG Vulkan SDK can be downloaded at <https://www.lunarg.com/vulkan-sdk/>

### Installation

External libraries are currently loaded in as submodules. You will need to clone the repo with `git clone --recurse-submodules https://github.com/floressa/VulkanCraft`

## Built With

- [GLFW](https://github.com/glfw/glfw) - Cross-platform window creation
- [glm](https://github.com/g-truc/glm) - OpenGL Mathematics library (but also with Vulkan!)
- [stb](https://github.com/nothings/stb) - Multiple utility libraries for use in games. Primarily using [stb_image.h](https://github.com/nothings/stb/blob/master/stb_image.h) for this project

## Notes

General notes taken during the development of this project can be found in [notes.md](notes.md)

## License

This project is licensed under the MIT license - see [LICENSE](LICENSE) for details