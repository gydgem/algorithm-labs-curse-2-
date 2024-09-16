cmake_minimum_required(VERSION 3.27)
project(GraphLab1)

set(CMAKE_CXX_STANDARD 23)

add_executable(GraphLab1 main.cpp
        GraphComponents/Vertex.h
        GraphComponents/Edge.h
        Сommon/CommonIterators/MapSecondElementIterator.h
        GraphAlgorithm/dijkstrasShortestPath.h
        GraphAlgorithm/bellmanFordShortestPath.h
        GraphTypes/Graph.h
        LabComponent/Task1Handler.cpp
        LabComponent/Task1Handler.h
        LabComponent/Task2Handler.cpp
        LabComponent/Task2Handler.h
        LabComponent/Program.cpp
        LabComponent/Program.h
        LabComponent/Task3Handler.cpp
        LabComponent/Task3Handler.h
        GraphAlgorithm/floydWarshallShortestPath.h
        GraphAlgorithm/floydWarshallShortestPath.h.cpp)
