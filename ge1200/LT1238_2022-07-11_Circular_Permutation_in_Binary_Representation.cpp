
#include "../header/myheader.h"

class LT1238
{
public:


    // D D

    //vector<int> res;

    //for (int i = 0; i < (1 << n); i++)
    //{
    //    res.push_back(start ^ (i ^ (i >> 1)));
    //}


    //for (int i = 0; i < 1 << n; ++i) {
    //    int temp = start ^ i ^ i >> 1;
    //    res.push_back(temp);
    //}






//Runtime: 39 ms, faster than 30.95 % of C++ online submissions for Circular Permutation in Binary Representation.
//Memory Usage : 16.4 MB, less than 95.63 % of C++ online submissions for Circular Permutation in Binary Representation.
    vector<int> lt1238b(int n, int start)
    {
        vector<int> ans(1 << n);
        for (int i = 0; i < n; ++i)
        {
            int st = 1 << i;
            int t2 = st;
            int add = 1 << i;
            for (int i = 0; i < t2; ++i)
            {
                ans[t2 * 2 - i - 1] = ans[i] + add;
            }
            if ((start & add) == 0)         // & µÍÓÚ ==
            {
                ;
            }
            else
            {
                reverse(begin(ans), begin(ans) + t2 * 2);
            }
        }

        return ans;
    }


    // tle
    // 0, 1 -> 00,01,11,10
    // 000 001 011 010 110 111 101 100
    // reverse
    vector<int> lt1238a(int n, int start)
    {
        vector<int> ans(1 << n);
        for (int i = 0; i < n; ++i)
        {
            int st = 1 << i;
            int t2 = st;
            int add = 1 << i;
            for (int i = 0; i < t2; ++i)
            {
                ans[t2 * 2 - i - 1] = ans[i] + add;
            }
        }
        while (ans[0] != start)
        {
            ans.push_back(ans[0]);
            ans.erase(begin(ans));
        }
        return ans;
    }

};

int main()
{

    LT1238 lt;

    

    return 0;
}
