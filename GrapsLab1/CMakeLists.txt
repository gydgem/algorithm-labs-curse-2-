cmake_minimum_required(VERSION 3.27)
project(GrapsLab1)

set(CMAKE_CXX_STANDARD 23)

add_executable(GrapsLab1 main.cpp
        GraphComponents/Vertex.cpp
        GraphComponents/Vertex.h
        GraphComponents/Edge.cpp
        GraphComponents/Edge.h
        Graph.cpp
        Graph.h)
