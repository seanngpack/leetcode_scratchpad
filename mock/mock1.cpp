#include <iostream>

int main() {
    return 0;
}
 0  1 2
[[1,1,0] 0
 [1,1,0] 1
 [0,0,1]] 2

[0,1] infected nodes

   0 1 2 3 4
0 [1 1 1 0 0]
1 [1 1 1 0 0]
2 [1 1 1 0 0]
3 [0 0 0 1 1]
4 [0 0 0 1 1]

infected nodes: [5, 1, 0, 4]

saved = 3
[3, 4, 0, 2]



5 - 10 - 13

 0 - 1 - 2
 |
 2

 4 - 3

// FORGOT TO CLARIFY RETURN
// DONT FORGET TO CLARIFY WHAT ARE GIVEN
// wrong iteration condition (iterating through graph.size() instead of infected.size()
// ^ slow

// goal: remove the infected node that mitigates the infection (lowers total infection count)

// check to see if "groups" are connected meaning, if an infected group is not connected to another, the other
// will not get infected

// check the neighbors of an infected node, maybe dfs? to go depper into the network and see
// who else is infected

// Want to do a search and visit every infected node (we know the neighbors of the original node are infected
// because they are connected aka neighbors) and as we recursive through the search we are updating
// the count of infected nodes, return (the number of infected nodes left in the network)
// when all the neighbors are visited. When the DFS ends we have the number of infected nodes,
// so we can just subtract # infected from total nodes in the network and return that ^

// dfs(graph, visited, curent node) // total number of nodes in network, how many are infected in network

int total_nodes; // total number of nodes in this graph
int num_saved = 0; // max number of nodes we can save

int higher_level(vector<vector<int>> &graph) {
    vector<bool> visited(graph.size(), false);

    for (int i = 0; i < infected_nodes.size(); i++) {
        if (!visited[i]) {
            dfs(graph, visited, i);
        }
        else {
            max(num_saved, 0);
        }

    }
}

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int cur_node) {

    num_saved ++; // okay for now, we're gonna be 1 count off

    // set current node visited to true
    visited[cur_node] = true;

    // explore the neighbors
    for (int i = 0; i < graph[cur_node].size(); i++) {
        if (!visited[i]) {
            dfs(graph, visited, i);
        }
    }
    return;
}






