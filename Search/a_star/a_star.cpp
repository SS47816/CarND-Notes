#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include "a_star.h"

// Initializes A_STAR
A_STAR::A_STAR() {}

A_STAR::~A_STAR() {}

inline int A_STAR::huristic_cost(int x, int y, vector<int> &goal) 
{
    return fabs(x - goal[0]) + fabs(y - goal[1]);
}

inline bool A_STAR::compare_f_cost(const A_STAR::grid a, const A_STAR::grid b)
{
    return a.f < b.f;
}

vector<A_STAR::grid> A_STAR::expand(A_STAR::grid &state, vector<int> &goal)
{
    
}

A_STAR::result A_STAR::search(vector<vector<int>> &map, vector<int> &start, vector<int> &goal){
    /* 
        search for the shortest path
    */

    // init the first(starting) grid
    grid state;
    state.x = start[0];
    state.y = start[1];
    state.g = 0;
    state.f = state.g + huristic_cost(state.x, state.y, goal);

    // init closed list, expand list, action list
    vector<vector<int>> closed(map.size(), vector<int>(map[0].size()));
    closed[start[0]][start[1]] = 1;
    vector<vector<int>> expand(map.size(), vector<int>(map[0].size(), -1));
    vector<vector<int>> action(map.size(), vector<int>(map[0].size(), -1));

    // init open list
    vector<grid> open_list;
    open_list.push_back(state);

    bool found = false;
    bool resign = false;
    int count = 0;

    while (!found && !resign)
    {
        if (open_list.empty())
        {
            resign = true;
            std::cout << "Search Failed! No path available." << std::endl;
        }
        else 
        {
            sort(open_list.begin(), open_list.end(), compare_f_cost);
            grid current_grid = open_list[0];

        }
    }
}
