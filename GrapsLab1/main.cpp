#include <iostream>
#include <bits/stdc++.h>
#include "GraphComponents/Edge.h"
#include "GraphComponents/Vertex.h"
using Vertex = hgem::Vertex<std::string, int64_t ,std::string, int64_t>;
using Edge = hgem::Edge<std::string, int64_t, std::string, int64_t>;

int main() {
    Vertex a("a", 12);
    Vertex b("b", 12);
    Vertex c("c",12);
    Edge edg(c , b, "edge",123);
    a.addEdge(edg);

}
