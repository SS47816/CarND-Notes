#include <iostream>
#include <vector>
#include "a_star.h"

using std::cout;
using std::endl;

int X = 1;
int _ = 0;

vector<vector<int>> map = {
    {_, X, _, _, _, _,},
    {_, X, _, _, _, _,},
    {_, X, _, _, _, _,},
    {_, X, _, _, _, _,},
    {_, _, _, _, X, _,}
    };

vector<int> start = {0, 0};
vector<int> goal = {(int)map.size() - 1, (int)map[0].size() - 1};
int cost = 1;

int main()
{

    return 0;
}