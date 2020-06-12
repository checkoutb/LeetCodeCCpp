
#include "../header/myheader.h"

class LT0836
{
public:


//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Rectangle Overlap.
//Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Rectangle Overlap.
    bool lt0836a(vector<int>& rec1, vector<int>& rec2)
    {
        return rec1[0] < rec2[2] && rec1[2] > rec2[0] && rec1[1] < rec2[3] && rec1[3] > rec2[1];
    }

};

int main()
{

    vector<int> v1 = {0,0,1,1};
    vector<int> v2 = {1,0,2,1};

    LT0836 lt;

    cout<<lt.lt0836a(v1, v2)<<endl;

    return 0;
}
