#include <iostream>
#include <unordered_map>
#include <regex>

//hashmap<string, hashset/list neighbors> unweighted
//hashmap<string, hashmap<string, weight> neighbors> weighted
using namespace std;

vector<string> split_string(const string& s) {
    std::regex regex{R"([:]+)"}; // split on space and comma
    std::sregex_token_iterator it{s.begin(), s.end(), regex, -1};
    std::vector<std::string> words{it, {}};
    return words;
}

class Graph {
    unordered_map<string, unordered_map<string, int>> transit_map;

    void add_stop(string in) {
        auto parsed = split_string(in);
        string from = parsed[0];
        string to = parsed[1];
        int dist = stoi(parsed[2]);

        transit_map[from] = unordered_map<string, int>{{to, dist}};
        transit_map[to] = unordered_map<string, int>{{from, dist}};
    }

};

int longest_trip(string in) {
    Graph.add_stop(in)

}



// recursive dfs:
// current city
// visited cities <-- hashset
// path so far (int)
// global variable: longest path seen so far, initialize as min_value
// counter for nodes visited so far
// keep track of the path (array)

// base case:
// if there's no neighbors or if the neighbors are all visited
// if nodes visited is more than 3, set the longest path in the global variable
// longest path = path so far

// graph:
// nyc:
//          chi: 1700
// //       sea: 200


// chi:
        //nyc: 1700

// sea:
        // nyc: 200

int main() {

    return 0;
}

int longestPath = min_value;
ArrayList citiesTraveled;

void dfs (string current_city, unordered_set visited_cities, int total_dist, int city_count, ArrayList path_of_cities) {

    if (!transit_map.contains(current_city) or city_count > 3 or neighbors have all been visited) {
        longestPath = total_dist;
        citiesTraveled = path_of_cities;
        return;
    }

    for (neighbor : transit_map.get(current_city)) {
        if (!visited_cities.contains(neighbor)) {
            visited_cities.add(neighbor);
            path_of_cities.add(neighbor);
            dfs(neighbor, visited_cities, total_dist + weight between current_city and neighbor, city_count +1, path_of_cities);
            path_of_cities.remove(last index);
            visited_cities.remove(neighbor); // backtracking
        }
    }
}

// leftover questions: what is the starting city
// what about multiple cities with same path