//
// Created by gydgem on 9/16/2024.
//

#include "Task2Handler.h"

hgem::Task2Handler::Task2Handler() {
    graph.addVertex("S",0);
    graph.addVertex("C",0);
    graph.addVertex("D",0);
    graph.addVertex("F",0);
    graph.addVertex("E",0);
    graph.addVertex("H",0);
    graph.addVertex("I",0);
    graph.addVertex("G",0);
    graph.addVertex("B",0);
    graph.addVertex("A",0);
    graph.addEdge("S","C","SC",6);
    graph.addEdge("C","D","CD",2);
    graph.addEdge("C","F","CF",1);
    graph.addEdge("F","D","FD",3);
    graph.addEdge("S","F","SF",5);
    graph.addEdge("S","A","SA",7);
    graph.addEdge("S","E","SE",6);
    graph.addEdge("A","C","AC",-2);
    graph.addEdge("A","B","AB",4);
    graph.addEdge("B","G","BG",-2);
    graph.addEdge("B","H","BH",-4);
    graph.addEdge("G","I","GI",-1);
    graph.addEdge("I","H","IH",1);
    graph.addEdge("E","H","EH",3);
    graph.addEdge("E","F","EF",-2);
    graph.addEdge("H","G","HG",1);
}

void hgem::Task2Handler::task2() {
    auto res = bellmanFordShortestPathIgnoreVertexWeightAndGetAllSteps(graph, "S");
    std::vector<std::string> allNameVertex;
    for (auto iteratorVertices = graph.beginVertices(); iteratorVertices != graph.endVertices(); iteratorVertices++){
        allNameVertex.push_back(iteratorVertices->getNameVertex());
    }

    std::cout << "Task2\n******************************************************************************\n";

    for (const auto &valueNameColumn : allNameVertex){
        std::cout << std::format("|{:^5}", valueNameColumn);
    }

    std::cout<<"|\n";

    for (const auto &valueLine : res){
        for (const auto &valueNameColumn : allNameVertex){
            if (valueLine.find(valueNameColumn) == valueLine.end()){
                std::cout << std::format("|{:^5}", "inf");
                continue;
            }

            std::cout << std::format("|{:^5}", valueLine.find(valueNameColumn)->second);
        }
        std::cout<<"|\n";
    }

}
