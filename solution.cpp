#include "solution.h"

void read_input(std::ifstream &input, std::vector<int> &values, std::vector<std::vector<int>> &graph) {
    int nodes;
    input >> nodes;
    graph.resize(nodes + 1);
    values.resize(nodes + 1);
    for (int i = 1; i <= nodes; ++i) {
        input >> values[i];
    }
    for (int i = 0; i < nodes - 1; ++i) {
        int vertex1, vertex2;
        input >> vertex1;
        input >> vertex2;
        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }
}

bool dfs(int cur_vertex, int parent, int cur_sum, int target_sum, std::vector<int> &values,
         std::vector<std::vector<int>> &graph) {
    cur_sum += values[cur_vertex];
    std::vector<int> transitions;
    for (int vertex : graph[cur_vertex]) {
        if (vertex != parent) {
            transitions.push_back(vertex);
        }
    }
    if (transitions.empty()) {
        return cur_sum == target_sum;
    }
    for (int vertex : transitions) {
        if (dfs(vertex, cur_vertex, cur_sum, target_sum, values, graph)) {
            return true;
        }
    }
    return false;
}

void solve(int test_number) {
    std::string filename_input = "tests/input" + std::to_string(test_number) + ".txt";
    std::string filename_output = "tests/output" + std::to_string(test_number) + ".txt";
    std::ifstream input;
    input.open(filename_input);
    std::ofstream output;
    output.open(filename_output);
    std::vector<int> values;
    std::vector<std::vector<int>> graph;
    int n;
    read_input(input, values, graph);
    n = int(graph.size()) - 1;
    int target_sum;
    input >> target_sum;
    input.close();
    if (dfs(1, -1, 0, target_sum, values, graph)) {
        output << "YES" << std::endl;
    }
    else {
        output << "NO" << std::endl;
    }

}