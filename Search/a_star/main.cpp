#include <iostream>
#include <vector>
#include "a_star.h"

const int X = 1;
const int _ = 0;

vector<vector<int> > map = {
    {1, 1, 1, 0, 0, 0,},
    {1, 1, 1, 0, 1, 0,},
    {0, 0, 0, 0, 0, 0,},
    {1, 1, 1, 0, 1, 1,},
    {1, 1, 1, 0, 1, 1,}
};

vector<int> start = {4, 3, 0}; //{x, y, theta}
/* theta = 0: up
           1: left
           2: down
           3: right
*/

vector<int> goal = {2, 0}; //{x, y}

vector<int> costs = {2, 1, 20};

// vector<int> start(2, 0);
// vector<int> goal = {(int)map.size() - 1, (int)map[0].size() - 1};
// const int cost = 1;

int main()
{
    A_STAR a_star = A_STAR();
    A_STAR::Result planning_result = a_star.search(map, start, goal, costs);
    a_star.print_search_result(planning_result, start, goal);
    return 0;
}