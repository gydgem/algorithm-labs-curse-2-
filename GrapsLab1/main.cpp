#include <bits/stdc++.h>
#include "GraphComponents/Vertex.h"
#include "Graph.h"

using Graph = hgem::Graph<std::string, int64_t, std::string, int64_t>;

int main() {
    Graph g;
    g.addVertex("a",0);
    g.addVertex("b", 1);
    g.addVertex("c",2);
    g.addEdge("a", "b", "edge1",0);
    g.addEdge("a", "c", "edge2",1);
    g.addEdge("b","c","edge3",2);

    std::cout << "*****************************************************************************************\n";
    for (const auto& edge : g.getVertex("a")){
        std::cout << edge.getSourceVertex().getNameVertex() << " " << edge.getTargetVertex().getNameVertex() << " " << edge.getNameEdge() << "\n";
    }
    std::cout << "*****************************************************************************************\n";

    for (Graph::IteratorVertices it = g.beginVertices(); it != g.endVertices(); it++){
        Graph::TypeVertex &vertex = *it;
        std::cout << vertex.getNameVertex() << " " << vertex.getWeightVertex() << "\n";
    }

    std::cout << g.getVertex("a").getOutgoingEdge("edge1").getTargetVertex().getNameVertex() << "\n";
}
