//
// Created by gydgem on 9/16/2024.
//

#include "Task1Handler.h"

namespace hgem {
    Task1Handler::Task1Handler() {
        graph.addVertex("s", 0);
        graph.addVertex("a", 0);
        graph.addVertex("b", 0);
        graph.addVertex("c", 0);
        graph.addVertex("t", 0);
        graph.addVertex("d", 0);
        graph.addVertex("f", 0);
        graph.addVertex("g", 0);
        graph.addEdge("s","a","sa",5);
        graph.addEdge("s","c","sc",4);
        graph.addEdge("s","d","sd",5);
        graph.addEdge("a","b","ab",3);
        graph.addEdge("a","f","af",3);
        graph.addEdge("a","g","ag",1);
        graph.addEdge("b","c","bc",5);
        graph.addEdge("b","g","bg",5);
        graph.addEdge("c","t","ct",4);
        graph.addEdge("d","f","df",1);
        graph.addEdge("f","g","fg",3);
        graph.addEdge("g","t","gt",7);
    }

    void Task1Handler::task1() {
        std::cout << "Task1\n******************************************************************************\n";
        auto res = dijkstraShortestPathsIgnoreVertexWeight(graph, "s");

        for (const auto& value : res) {
            std::cout << value.first << " " <<value.second << "\n";
        }
    }
} // hgem