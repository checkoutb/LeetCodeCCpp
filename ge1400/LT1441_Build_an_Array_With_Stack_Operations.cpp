
#include "../header/myheader.h"

class LT1441
{
public:

// D D





//Runtime: 4 ms, faster than 50.96% of C++ online submissions for Build an Array With Stack Operations.
//Memory Usage: 8.1 MB, less than 90.30% of C++ online submissions for Build an Array With Stack Operations.
//  1, 4  ,      2,3 is     push push pop pop   or  push pop push pop
    vector<string> lt1441a(vector<int>& target, int n)
    {
        string push = "Push";
        string pop = "Pop";
        vector<string> ans;
        int idx = 0;
        for (int i = 1, mxi = target[target.size() - 1]; i <= mxi; ++i)
        {
            ans.push_back(push);
            if (i != target[idx])
                ans.push_back(pop);
            else
                ++idx;
        }
        return ans;
    }

};

int main()
{
    vector<int> v = {2,3};
    int n{3};

    LT1441 lt;

    vector<string> vs = lt.lt1441a(v, n);

    for (string& s : vs)
        cout<<s<<", ";

    return 0;
}
