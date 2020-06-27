
#include "../header/myheader.h"

class LT0970
{
public:


// D
//        unordered_set<int> s;
//        for (int i = 1; i <= bound; i *= x) {
//            for (int j = 1; i + j <= bound; j *= y) {
//                s.insert(i + j);
//                if (y == 1) break;
//            }
//            if (x == 1) break;
//        }



//Runtime: 4 ms, faster than 24.30% of C++ online submissions for Powerful Integers.
//Memory Usage: 6.6 MB, less than 48.03% of C++ online submissions for Powerful Integers.
    vector<int> lt0970a(int x, int y, int bound)
    {
        vector<int> ans;
        vector<int> vx;
        vector<int> vy;

        int t1 = 1;
        if (x != 1)
            while (t1 <= bound)
            {
                vx.push_back(t1);
                t1 *= x;
            }
        else
            vx.push_back(t1);

        t1 = 1;
        if (y != 1)
            while (t1 <= bound)
            {
                vy.push_back(t1);
                t1 *= y;
            }
        else
            vy.push_back(t1);

        unordered_set<int> set2;

        for (int i = 0; i < vx.size(); i++)
        {
            int t3 = vx[i];
            for (int j = 0; j < vy.size(); j++)
            {
                int t2 = vy[j] + t3;
                if (t2 > bound)
                    break;
                set2.insert(t2);
            }
        }
        ans = vector<int>(begin(set2), end(set2));
        return ans;
    }

};

int main()
{

//    int x = 2, y = 3, b = 10;
    int x = 3, y = 5, b = 15;

    LT0970 lt;

    vector<int> v = lt.lt0970a(x, y, b);

    for_each(begin(v), end(v), fun_cout);
    cout<<endl;

    return 0;
}
