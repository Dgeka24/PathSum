#include "gentests.h"
#include "treegenerator.h"
#include "solution.h"


int get_random_sum(int cur_vertex, int parent, int cur_sum, std::vector<int> &values,
                   std::vector<std::vector<int>> &graph) {
    cur_sum += values[cur_vertex];
    std::vector<int> transitions;
    for (int vertex : graph[cur_vertex]) {
        if (vertex != parent) {
            transitions.push_back(vertex);
        }
    }
    if (transitions.empty()) {
        return cur_sum;
    }
    else if (transitions.size() == 1) {
        return get_random_sum(transitions[0], cur_vertex, cur_sum, values, graph);
    }
    else {
        std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
        unsigned int idx = gen() % 2;
        return get_random_sum(transitions[idx], cur_vertex, cur_sum, values, graph);
    }
}

void gen_test(int test_number, int min_nodes = 2, int max_nodes = 1000) {
    std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> nodes_amount_gen(min_nodes, max_nodes);
    std::uniform_int_distribution<> target_sum_gen(-1000, 1000);
    std::uniform_int_distribution<> value_gen(-1000, 1000);
    std::string filename_input = "tests/input" + std::to_string(test_number) + ".txt";
    std::ofstream input;
    input.open(filename_input);
    // generating amount of nodes
    int nodes_amount = nodes_amount_gen(gen);
    input << nodes_amount << std::endl;
    // generating values for vertexes
    for (int i = 0; i < nodes_amount; ++i) {
        input << value_gen(gen) << " ";
    }
    input << std::endl;
    // generating binary_tree
    std::string format_string = "bi" + std::to_string(nodes_amount - 1) + ",0";
    tree_generator_by_ouuan::Tree Tree(format_string);
    input << Tree;
    // generating target_sum
    if (gen() % 2) {
        input << target_sum_gen(gen);
    }
    else {
        input.close();
        std::ifstream read_inputs;
        read_inputs.open(filename_input);
        std::vector<int> values;
        std::vector<std::vector<int>> graph;
        read_input(read_inputs, values, graph);
        read_inputs.close();
        int target_sum = get_random_sum(1, -1, 0, values, graph);
        input.open(filename_input, std::ios_base::app);
        input << target_sum;
    }
    input.close();
    solve(test_number);
}