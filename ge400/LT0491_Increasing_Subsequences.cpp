
#include "../header/myheader.h"

class LT0491
{
public:

    vector<vector<int>> lt0491a(vector<int>& nums)
    {
        vector<vector<int>> ans;
        int sz1 = nums.size();
        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {

            }
        }

    }
};

int main()
{
    vector<int> v = {4,6,7,7};

    LT0491 lt;

    vector<vector<int>> r = lt.lt0491a(v);

    for (auto p : r)
    {
        for (int i : p)
        {
            cout<<i<<", ";
        }
        cout<<endl;
    }

    return 0;
}
