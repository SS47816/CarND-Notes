#ifndef A_STAR_H_
#define A_STAR_H_

# include <vector>

using std::vector;

class A_STAR {
public:
    // Constructor
    A_STAR();

    // Destructor
    virtual ~A_STAR();
    
    // A_STAR structs
    struct grid
    {
        int x;
        int y;
        int g;
        int f;
    };

    struct result
    {
        vector<vector<int>> closed;
        vector<vector<grid>> came_from;
        grid final_state;
    };

    // A_STAR functions
    inline int huristic_cost(int x, int y, vector<int> &goal);
    inline bool compare_f_cost(const grid a, const grid b);
    result search(vector<vector<int>> &map, vector<int> &start, vector<int> &goal, int cost);

private:
    vector<vector<int>> motion = {
        {-1, 0}, // go up
        {0, -1}, // go left
        {1, 0},  // go down
        {0, 1},  // go right
    };

    vector<char> motion_name = {
        '^', '<', 'v', '>',
    };

    
};

#endif // A_STAR_H_