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

A_STAR::result A_STAR::search(vector<vector<int>> &map, vector<int> &start, vector<int> &goal, int cost){
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
    vector<vector<int>> closed_list(map.size(), vector<int>(map[0].size()));
    closed_list[start[0]][start[1]] = 1;
    vector<vector<int>> expand_list(map.size(), vector<int>(map[0].size(), -1));
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
            // pop out the grid with the lowest f cost
            sort(open_list.begin(), open_list.end(), compare_f_cost);
            grid current_grid = open_list[0];
            open_list.erase(open_list.begin());

            int x = current_grid.x;
            int y = current_grid.y;
            int g = current_grid.g;
            expand_list[x][y] = count;
            count += 1;

            // if the current grid reaches the goal
            if (x == goal[0] && y == goal[1])
            {
                found = true;
                std::cout << "Goal Reached!" << std::endl;
            }
            else
            {
                // for all of the 4 possible motions(up, left, down, right)
                for (int i = 0; i < motion.size(); i++)
                {
                    int x2 = x + motion[i][0];
                    int y2 = y + motion[i][1];
                    // if next grid is within the map
                    if ((x2 >= 0 && x2 <= map.size()) && (y2 >= 0 && y2 <= map[0].size()))
                    {
                        // if next grid is not in the closed_list and is drivable on the map
                        if (closed_list[x2][y2] == 0 && map[x2][y2] == 0) 
                        {
                            // set it as the next_state
                            grid next_grid;
                            next_grid.x = x2;
                            next_grid.y = y2;
                            next_grid.g = g + cost;
                            next_grid.f = next_grid.g + huristic_cost(x2, y2, goal);

                            // update the lists
                            open_list.push_back(next_grid);
                            closed_list[x2][y2] = 1;
                            action[x2][y2] = i;
                        }
                    }
                }
            }
        }
    }
}
