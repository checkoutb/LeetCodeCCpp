
#include "../header/myheader.h"

class LT2078
{
public:

// D D

//The first and the last house can be one of the furthest houses.

//        int n = A.size(), i = 0, j = n - 1;
//        while (A[0] == A[j]) j--;
//        while (A[n - 1] == A[i]) i++;
//        return max(n - 1 - i, j);




//Runtime: 4 ms, faster than 61.32% of C++ online submissions for Two Furthest Houses With Different Colors.
//Memory Usage: 9.3 MB, less than 19.26% of C++ online submissions for Two Furthest Houses With Different Colors.
    int lt2078a(vector<int>& colors)
    {
        unordered_set<int> set2;
        int ans = 0;
        for (int i = 0; i < colors.size(); ++i)
        {
            if (set2.find(i) != end(set2))
                continue;
            for (int j = colors.size() - 1; j >= i; --j)
            {
                if (colors[j] != colors[i])
                {
                    ans = max(ans, j - i);
                    break;
                }
            }
            set2.insert(i);
        }
        return ans;
    }

};

int main()
{

    LT2078 lt;


    return 0;
}
