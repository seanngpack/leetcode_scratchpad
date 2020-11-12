#include <iostream>
#include <vector>

// directed graph without weight
class Graph {
public:
    std::vector<int> vertices;
    std::vector<std::pair<int,int> edges;

    Graph(std::vector<int> &v, std::vector<std::pair<int, int>>& e) : vertices(v), edges(e) {}

};

int main() {

    std::vector<int> v = {0,1,2,3};
    std::vector<std::pair<int, int>> e = {{0,1}, {1,2}, {2,3}, {3,0}};
    Graph g(v,e);

    // print adjacency list representation of graph
    print_graph(graph, N);

    return 0;
}