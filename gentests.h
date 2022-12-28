#ifndef PATHSUM_GENTESTS_H
#define PATHSUM_GENTESTS_H
#include "bits/stdc++.h"
int get_random_sum(int cur_vertex, int parent, int cur_sum, std::vector<int> &values,
                   std::vector<std::vector<int>> &graph);
void gen_test(int test_number, int min_nodes, int max_nodes);

#endif //PATHSUM_GENTESTS_H
