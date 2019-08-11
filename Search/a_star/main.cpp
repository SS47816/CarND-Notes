#include <iostream>
#include <vector>
#include "a_star.h"

using std::cout;
using std::endl;

const int X = 1;
const int _ = 0;

vector<vector<int>> map = {
    {_, X, _, _, _, _,},
    {_, X, _, _, _, _,},
    {_, X, _, _, _, _,},
    {_, X, _, _, _, _,},
    {_, _, _, _, X, _,}
    };

vector<int> start = {0, 0};
vector<int> goal = {(int)map.size() - 1, (int)map[0].size() - 1};
const int cost = 1;

int main()
{
    A_STAR a_star = A_STAR();
    A_STAR::result planning_result = a_star.search(map, start, goal, cost);
    a_star.print_search_result(planning_result, start, goal);
    return 0;
}