#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>

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

    // i can also try a slightly different algorithm that has a target.
    // this one just searches everything
    // https://leetcode.com/problems/all-paths-from-source-to-target/discuss/118647/C++-DFS-Recursive-Easy-to-Understand
    void print_dfs_recursive(int node, std::set<int> &seen) {
        seen.insert(node);

        std::cout << node << " ";

        for (int n : adj_list[node]) {
            if (seen.find(n) == seen.end()) {
                print_dfs_recursive(n, seen);
            }
        }
    }

    // print all the nodes in the graph using dfs
    // DONT PUT SEEN BEFORE PUSHING TO CALL STACK
    void print_dfs_iterative(int start) {
        std::set<int> seen;
        std::stack<int> stk;
        stk.push(start);
        seen.insert(start);
        while (!stk.empty()) {
            int top = stk.top();
            std::cout << top << " ";
            stk.pop();

            if (!seen.count(top)) {
                seen.insert(top);
            }
            
            for (int neighbor: adj_list[top]) {
                if (seen.find(neighbor) == seen.end()) {
//                    seen.insert(neighbor);
                    stk.push(neighbor);
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

    std::vector<Edge> bfs_edges =
            {
                    {0, 1},
                    {0, 2},
                    {0, 3},
                    {2, 4}
            };

    std::vector<Edge> dfs_edges = {
            // Notice that node 0 is unconnected node
            {1, 2}, {1, 7}, {1, 8}, {2, 3}, {2, 6}, {3, 4},
            {3, 5}, {8, 9}, {8, 12}, {9, 10}, {9, 11}
    };


    int bfs_N = 5;
    int dfs_N = 13;

    // construct graph
    Graph bfs_graph(bfs_edges, bfs_N);
    Graph dfs_graph(dfs_edges, dfs_N);

    // print adjacency list representation of graph
//    print_graph(graph, N);

    // do bfs
    bfs_graph.print_bfs(0);

    // do recursive dfs
    std::cout << std::endl;
    std::set<int> s;
    dfs_graph.print_dfs_recursive(1, s);

    // do iterative dfs, it uses a stack and prints in different order than recursive
    std::cout << std::endl;
    dfs_graph.print_dfs_iterative(1);


    return 0;
}