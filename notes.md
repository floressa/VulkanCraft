# Notes

General notes taken while making the project

## To-do

- Add basic camera controls
- Add offline mipmap generation capabilities
- Make a custom allocator or use [GPUOpen's allocator](https://vulkan-tutorial.com/Vertex_buffers/Staging_buffer)
- Split main.cpp into better OO-style classes

## General

- Comments made in the style of `// !` or `// *` are done so to interact with the Better Comments extension for Visual Studio Code
- Referenced [this repo](https://github.com/gujans/travis-gtest-cmake-example/blob/master/.travis.yml) for help integrating travis and testing

### OS-Specific

#### Windows

- Easiest build/compile setup for Windows has been using nuwen's MinGW distro and CMake with a Ninja generator
- This strategy has issues with debugging however, GDB does not seem to want to stop for breakpoints added after the program has started execution

#### Linux

#### MacOS