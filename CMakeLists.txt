cmake_minimum_required(VERSION 3.10)

project(EventsGLFW LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

add_executable(EventsGLFW main.cpp)

target_link_libraries(EventsGLFW
    ${OPENGL_LIBRARIES}
    glfw
    GLEW
)


