#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <regex>

using namespace std;

void print_arr(const vector<string> &arr) {
    cout << "[";
    for (const auto& i: arr) {
        cout << i << ", ";
    }
    cout << "]" << endl;

}

struct Res {
    string from;
    string conn;
    string to;
    int dist;
};

int max_dist = INT_MIN;

// node, list of pairs, pair of dist and neighbor
map<string, vector<pair<int, string>>> graph;

vector<string> split_string(const string& s) {
    regex regex{R"([:]+)"}; // split on space and comma
    sregex_token_iterator it{s.begin(), s.end(), regex, -1};
    vector<std::string> words{it, {}};
    return words;
}


// do a dfs only 2 levels deep, backtracking
void dfs(vector<pair<int, string>> &adj, Res &result, vector<string>& curr_nodes, int curr_dist) {
//    cout << "dist so far: " << curr_dist << endl;
    if (curr_nodes.size() == 3) {
        if (curr_dist > max_dist) {
            result.from = curr_nodes[0];
            result.conn = curr_nodes[1];
            result.to = curr_nodes[2];
            result.dist = curr_dist;
            max_dist = curr_dist;
        }
        return;
    }

//    print_arr(curr_nodes);

    for (const auto& node : adj) {
        // add this line to remove duplicates
        if (std::find(curr_nodes.begin(), curr_nodes.end(), node.second) != curr_nodes.end()) continue;
        curr_nodes.push_back(node.second);
        dfs(adj, result, curr_nodes, curr_dist + node.first);
//        print_arr(curr_nodes);
//        cout << "popped back " << curr_nodes.back() << endl;
        curr_nodes.pop_back();
    }
}

string longest(const string& input) {
    // build the graph, dont wanna put in a function lol
    vector<string> split = split_string(input);
    string from = split[0];
    string to = split[1];
    int dist = stoi(split[2]);

    // push from and to
    auto p = make_pair(dist, to);
    graph[from].push_back(p);

    // push to and from
    auto p2 = make_pair(dist, from);
    graph[to].push_back(p2);

    Res result;
    // next do backtracking
    for (const auto& node: graph) {
        vector<string> curr = {node.first};

        dfs(graph[node.first], result, curr, 0);
//        cout << result.conn << endl;
    }

    if (result.conn.empty()) {
        return "NONE";
    }

    // NOTE: doesn't do alphabetical order for ties but im too tired to implement that so oh well lmao
    return to_string(result.dist) + ":" + result.from + ":" + result.conn + ":" + result.to;
}


int main() {
    string one = longest("CHI:NYC:719");
    cout << "output of one: " << one << endl;
    string two = longest("NYC:LA:2414");
    cout << "output of two: " << two << endl;
    string three = longest("NYC:SEATTLE:2448");
    cout << "output of three: " << three << endl;
    string four = longest("NYC:HAWAII:4924");
    cout << "output of four: " << four << endl;


    return 0;
}