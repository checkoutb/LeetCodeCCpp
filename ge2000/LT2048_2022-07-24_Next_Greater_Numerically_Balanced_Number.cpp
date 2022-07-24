
#include "../header/myheader.h"

class LT2048
{
public:

// D

    // a ?: b is short for a ? a : b.      this operator is non-standard (only supported in GCC).




// g


// 1 1  2 2 3 3 4 4 5 5
// 6  666666   444422  15555
// n < 1000000
// 7  124   16   25 34          7c1 * 6c2 ,     7
// 6  24  15  123       6
// 5  14 23     5
// 4  13        4
// 3  12        3
// 2  2     2
// 1  1         1
    int lt2048a(int n)
    {
        string ns = to_string(n);

        vector<int> chose(8, 0);



    }


    string finda1(string& ns, vector<int>& chose, int idx, int sz2)
    {
        if (sz2 > ns.size())
            return "";

        if (sz2 == ns.size())
        {
            vector<int> vi;
            for (int i = 1; i < chose.size(); ++i)
            {
                if (chose[i] == 0)
                    continue;

                for (int a = 0; a < i; ++a)
                    vi.push_back(i);
            }



        }

        string ans = "";
        for (int i = idx; i < chose.size(); ++i)
        {
            chose[i] = 1;
//            sz2 += i;
            string s2 = finda1(ns, chose, i + 1, sz2 + i);
            chose[i] = 0;
//            sz2 -= i;
            if (ans.empty() || s2 < ans)
                ans = s2;
        }
        return ans;
    }

};

int main()
{

    LT2048 lt;


    return 0;
}
