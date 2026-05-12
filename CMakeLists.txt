cmake_minimum_required(VERSION 3.10)
project(Kengine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GLFW
include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8
)
FetchContent_MakeAvailable(glfw)

# External library sources (compiled sources only)
set(EXTERNAL_SOURCES
    external/glad/src/glad.c
    external/stb_image/stb_image.cpp
)

# External library include directories
set(EXTERNAL_HEADERS
    ${CMAKE_SOURCE_DIR}/external/glad/include
    ${CMAKE_SOURCE_DIR}/external/stb_image
    ${CMAKE_SOURCE_DIR}/external/glm
)

# Add external libraries (GLAD with sources)
add_library(glad ${EXTERNAL_SOURCES})
target_include_directories(glad PUBLIC external/glad/include)

# GLM is header-only, create interface library
add_library(glm INTERFACE)
target_include_directories(glm INTERFACE ${CMAKE_SOURCE_DIR}/external/glm)

# Main project sources
set(SOURCES
    src/main.cpp
    src/Renderer/Shader.h
    src/Renderer/Shader.cpp
    src/Renderer/Camera.h
    src/Renderer/Camera.cpp
    src/Renderer/Texture.h
    src/Renderer/Texture.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE 
    glfw 
    glad
    glm
)

# Include directories for stb_image (header-only)
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}/external/stb_image
)
