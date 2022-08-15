
#include "../header/myheader.h"

class LT2374
{
public:

    // D D

    //vector<long long> score(edges.size());
    //for (int i = 0; i < edges.size(); ++i)
    //    score[edges[i]] += i;
    //return max_element(begin(score), end(score)) - begin(score);



//Runtime: 315 ms, faster than 57.14 % of C++ online submissions for Node With Highest Edge Score.
//Memory Usage : 109.9 MB, less than 42.86 % of C++ online submissions for Node With Highest Edge Score.
    // 一个出度
    // 是一条边指向， 还是 可以多条边指向。。 就是 是可达 还是 相邻？
    // 相邻
    int lt2374a(vector<int>& edges)
    {
        int sz1 = edges.size();
        vector<long long> vi(sz1);              // ...
        int ans = 0;

        for (int i = 0; i < sz1; ++i)
        {
            vi[edges[i]] += i;
        }
        for (int i = 1; i < sz1; ++i)
        {
            if (vi[i] > vi[ans])
            {
                ans = i;
            }
        }
        return ans;
    }

};

int main()
{

    LT2374 lt;


    return 0;
}
