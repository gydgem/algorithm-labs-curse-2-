#include <bits/stdc++.h>
#include "GraphComponents/Vertex.h"
#include "GraphTypes/Graph.h"
#include "GraphAlgorithm/dijkstrasAlgorithm.h"

using Graph = hgem::Graph<std::string, int64_t, std::string, int64_t>;

int main() {
    Graph g;
    g.addVertex("a",0);
    g.addVertex("b", 1);
    g.addVertex("c",2);
    g.addVertex("d",3);
    g.addEdge("a", "b", "edge1",1);
    g.addEdge("a", "c", "edge2",2);
    g.addEdge("b","c","edge3",3);
    g.addEdge("c","d","edge4",4);
    g.addEdge("b","d","edge5",5);


   /* std::cout << "*****************************************************************************************\n";
    for (auto edge : g.getVertex("a")){
        std::cout << edge.getSourceVertex().getNameVertex() << " " << edge.getTargetVertex().getNameVertex() << " " << edge.getNameEdge() << "\n";
    }
    std::cout << "*****************************************************************************************\n";

    for (Graph::IteratorVertices it = g.beginVertices(); it != g.endVertices(); it++){
        Graph::TypeVertex &vertex = *it;
        std::cout << vertex.getNameVertex() << " " << vertex.getWeightVertex() << "\n";
    }

    std::cout << g.getVertex("a").getOutgoingEdge("edge1").getTargetVertex().getNameVertex() << "\n";*/
   auto res = hgem::CalcDijkstraShortestPathsIgnoreVertexWeight(g,"a");
   for (auto value:res){
       std::cout << value.first << " " << value.second << "\n";
   }

}
