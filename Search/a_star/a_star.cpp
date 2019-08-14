/*  a_star.cpp
    
    MIT License

    Copyright (c) 2018-2019 SS47816@github.com.

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

    CODE AUTHOR: SS47816
    E-MAIL: e0134075@u.nus.edu
    GitHub: SS47816@github.com

    Content:
    This piece of code is the implementation of A* search algorithm for navigation problems in 2D space. 
    This algorithm takes in a 2D map, a starting position, and a goal position, generates the shortest path between them.

    Input Format:
    vector<vector<int>> map, for each grid in map, drivalebe area are 0 and obstacles are 1
    vector<int> start, map coordinates in (x, y)
    vector<int> goal, map coordinates in (x, y)
    vector<int> costs, 

    Output Format:

    ~~ Feel free to make any modifications ~~
*/

#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include "a_star.h"

using std::vector;

// Initializes A_STAR
A_STAR::A_STAR() {}

A_STAR::~A_STAR() {}

inline int A_STAR::huristic_cost(int x, int y, vector<int> &goal)
{
    /* calculate the Manhattan huristic distance between the current grid cell and the goal */
    return fabs(x - goal[0]) + fabs(y - goal[1]);
}

static bool A_STAR::compare_f_cost(const A_STAR::Grid a, const A_STAR::Grid b)
{
    /* compare the f cost of two grid cells */
    return a.f < b.f;
}

A_STAR::Result A_STAR::search(vector<vector<int>> &map, vector<int> &start, vector<int> &goal, vector<int> costs)
{
    /* start searching for the shortest path */
    // init the first(starting) grid
    A_STAR::Grid state;
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
    vector<A_STAR::Grid> open_list;
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
            A_STAR::Grid current_grid = open_list[0];
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
                for (int i = 0; i < motion_.size(); i++)
                {
                    int x2 = x + motion_[i][0];
                    int y2 = y + motion_[i][1];
                    // if next grid is within the map
                    if ((x2 >= 0 && x2 <= map.size()) && (y2 >= 0 && y2 <= map[0].size()))
                    {
                        // if next grid is not in the closed_list and is drivable on the map
                        if (closed_list[x2][y2] == 0 && map[x2][y2] == 0)
                        {
                            // set it as the next_state
                            A_STAR::Grid next_grid;
                            next_grid.x = x2;
                            next_grid.y = y2;
                            next_grid.g = g + costs[1];
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

    // return the search result
    A_STAR::Result search_result;
    search_result.closed = closed_list;
    search_result.expand = expand_list;
    search_result.action = action;
    return search_result;
}

void A_STAR::print_search_result(A_STAR::Result &search_result, vector<int> &start, vector<int> &goal)
{
    /* print the expansion result */
    for (int i = 0; i < search_result.expand.size(); i++)
    {
        std::cout << search_result.expand[i][0];
        for (int j = 1; j < search_result.expand[0].size(); j++)
        {
            std::cout << ", " << search_result.expand[i][j];
        }
        std::cout << std::endl;
    }

    /* print path arrows on the map */
    vector<vector<int>> policy((int)search_result.action.size(),
                               vector<int>((int)search_result.action[0].size()));
    int x = goal[0];
    int y = goal[1];
    policy[x][y] = '*';

    // while haven't reached the starting cell
    while (x != start[0] || y != start[1])
    {
        // write arrows into the previous grid cells based on the next grid cells
        int x2 = x - motion_[search_result.action[x][y]][0];
        int y2 = y - motion_[search_result.action[x][y]][1];
        policy[x2][y2] = motion_name_[motion_[x][y]];
        x = x2;
        y = y2;
    }

    // print arrows
    for (int i = 0; i < policy.size(); i++)
    {
        std::cout << policy[i][0];
        for (int j = 1; j < policy[0].size(); j++)
        {
            std::cout << ", " << policy[i][j];
        }
        std::cout << std::endl;
    }
}