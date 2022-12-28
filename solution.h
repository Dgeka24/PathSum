#ifndef PATHSUM_SOLUTION_H
#define PATHSUM_SOLUTION_H
#include <bits/stdc++.h>
void read_input(std::ifstream &input, std::vector<int> &values, std::vector<std::vector<int>> &graph);
bool dfs(int cur_vertex, int parent, int cur_sum, int target_sum, std::vector<int> &values,
         std::vector<std::vector<int>> &graph);
void solve(int test_number);
#endif //PATHSUM_SOLUTION_H
