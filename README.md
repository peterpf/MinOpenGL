# MinOpenGL

Minimalistic setup to get started with OpenGL.

## Dependencies

- [GLAD](https://github.com/Dav1dde/glad)
- [GLFW](https://github.com/glfw/glfw)

## Setup

Initialize the git submodules.
Open a terminal, change into `vendor/glad` and execute:

```
python main.py --generator=c --extensions=GL_EXT_framebuffer_multisample,GL_EXT_texture_filter_anisotropic --out-path="../glad_files"
```

Download and install [CMake](https://cmake.org/). Build the project with the `CMakeLists.txt` of the project.
