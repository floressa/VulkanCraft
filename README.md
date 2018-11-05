# Vulkan Engine Learning

This project is a learning exercise to try to create an engine structure using  Vulkan as the base graphics API and a few popular utility libraries

## Getting Started

### Prerequisites

To build from source, a Vulkan SDK needs to be installed on your computer. The LunarG Vulkan SDK can be downloaded at <https://www.lunarg.com/vulkan-sdk/>

### Installation

External libraries are currently loaded in as submodules. You will need to clone the repo with `git clone --recurse-submodules https://github.com/floressa/vulkan-engine-learning`

## Built With

- [GLFW](https://github.com/glfw/glfw) - Cross-platform window creation
- [glm](https://github.com/g-truc/glm) - OpenGL Mathematics library (but also with Vulkan!)
- [stb](https://github.com/nothings/stb) - Multiple utility libraries for use in games. Primarily using [stb_image.h](https://github.com/nothings/stb/blob/master/stb_image.h) for this project
- [tinyobjloader](https://github.com/syoyo/tinyobjloader) - .obj file loader for loading in model files

## Notes

This project is intended as a personal project for learning Vulkan. General notes taken during the development of this project can be found in [notes.md](notes.md)

## License

This project is licensed under the MIT license - see [LICENSE](LICENSE) for details

## Acknowledgements

Resources I used when stuck in various places on this project

- ClemensGerstung's [LowPolyEngine](https://github.com/ClemensGerstung/LowPolyEngine) has a clean, compact CMakeLists.txt that I referenced while making my own