#ifndef A_STAR_H_
#define A_STAR_H_

# include <vector>

using std::vector;

namespace a_star{
class A_STAR {
private:
    bool found  = false;
    bool resign = false;
    int count = 0;

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
        //int h;
        int f;
    };
    
    vector<vector<int>> closed;
    vector<grid> closed;
    vector<vector<int>> expand;
    vector<vector<int>> action;

    // A_STAR functions
    inline int huristic_cost();
    void search();


};

} // namespace a_star
#endif // A_STAR_H_