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
    struct Grid
    {
        int x;
        int y;
        int g;
        int f;
    };

    struct Result
    {
        vector<vector<int> > closed;
        vector<vector<int> > expand;
        vector<vector<int> > action;
    };

    // A_STAR functions
    Result search(vector<vector<int> > &map, vector<int> &start, vector<int> &goal, int cost);
    void print_search_result(Result &search_result, vector<int> &start, vector<int> &goal);

private:
    vector<vector<int> > motion_ = {
        {-1, 0}, // go up
        {0, -1}, // go left
        {1, 0},  // go down
        {0, 1},  // go right
    };

    vector<char> motion_name_ = {
        '^', '<', 'v', '>'
    };

    // A_STAR functions
    inline int huristic_cost(int x, int y, vector<int> &goal);
    inline bool compare_f_cost(const Grid a, const Grid b);
};

#endif // A_STAR_H_