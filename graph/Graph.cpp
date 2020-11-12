#include <iostream>
#include <vector>
#include <queue>
#include <set>

struct Edge {
    int src;
    int dest;
};

// directed graph without weight
class Graph {
public:
    std::vector<std::vector<int>> adj_list;

    // n = number of nodes in the graph
    Graph(const std::vector<Edge> &edges, int n) {
        adj_list.resize(n); // change size of vector and fill in with default data state, 0s for int

        for (auto &edge: edges) {
            adj_list[edge.src].push_back(edge.dest);

            // for undirected graph:
            // adj_list[edge.dest].push_back(edge.src);
        }
    }

    void print_bfs(int start_node) {
        std::queue<int> q;
        std::set<int> seen;
        q.push(start_node);
        seen.insert(start_node);
        while (!q.empty()) {
            int front = q.front();
             std::cout << front << " ";
//            res.push_back(front);
            q.pop();

            for (int i: adj_list[front]) {
                if (seen.find(i) == seen.end()) {
                    q.push(i);
                    seen.insert(i);
                }
            }
        }
    }
};

void print_graph(const Graph &graph, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << i << "-->";

        for (int v : graph.adj_list[i]) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
//    std::vector<Edge> edges =
//            {
//                    {0, 1},
//                    {1, 2},
//                    {2, 0},
//                    {2, 1},
//                    {3, 2},
//                    {4, 5},
//                    {5, 4}
//            };

    std::vector<Edge> edges =
            {
                    {0, 1},
                    {0, 2},
                    {0, 3},
                    {2, 4}
            };



    // Number of nodes in the graph
    int N = 6;

    // construct graph
    Graph graph(edges, N);

    // print adjacency list representation of graph
//    print_graph(graph, N);

    // do bfs
    graph.print_bfs(0);

    return 0;
}