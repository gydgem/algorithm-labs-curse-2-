cmake_minimum_required(VERSION 3.27)
project(GraphLab1)

set(CMAKE_CXX_STANDARD 23)

add_executable(GraphLab1 main.cpp
        GraphComponents/Vertex.h
        GraphComponents/Edge.h
        Сommon/CommonIterators/MapSecondElementIterator.h
        GraphAlgorithm/dijkstrasAlgorithm.h
        GraphAlgorithm/bellmanFordShortestPath.h
        GraphTypes/Graph.h)
