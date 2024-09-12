cmake_minimum_required(VERSION 3.27)
project(GrapsLab1)

set(CMAKE_CXX_STANDARD 23)

add_executable(GrapsLab1 main.cpp
        GraffComponents/Vertex.cpp
        GraffComponents/Vertex.h
        GraffComponents/Edge.cpp
        GraffComponents/Edge.h)
