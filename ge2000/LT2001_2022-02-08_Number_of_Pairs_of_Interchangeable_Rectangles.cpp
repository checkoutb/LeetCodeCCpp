
#include "../header/myheader.h"

class LT2001
{
public:


// D D

//__gcd(w,h);

//        for(auto &x : rectangles){
//            double width = x[0];
//            double height = x[1];
//            double ratio = width/height;
//            ans += h[ratio]++;
//        }

//        for(int i = 0;i<rectangles.size();i++)
//        {
//            mp[((double)rectangles[i][0])/((double)rectangles[i][1])]++;
//        }


//    map<pair<int,int>,long long int> m;
//    for(int i = 0;i < rec.size();i++)
//    {
//         int x = __gcd(rec[i][0],rec[i][1]);
//         m[{rec[i][0]/x,rec[i][1]/x}]++;
//    }


// 应该直接 (double) 强转，而不是 1.0 *
//Runtime: 713 ms, faster than 48.95% of C++ online submissions for Number of Pairs of Interchangeable Rectangles.
//Memory Usage: 140.5 MB, less than 46.86% of C++ online submissions for Number of Pairs of Interchangeable Rectangles.
//Runtime: 1012 ms, faster than 16.38% of C++ online submissions for Number of Pairs of Interchangeable Rectangles.
//Memory Usage: 140.4 MB, less than 62.86% of C++ online submissions for Number of Pairs of Interchangeable Rectangles.
// 10^5 , 除法，double 精度应该够吧？ 不够的话，得 GCD。
// 1 < , no zero
// ; := for(pair<>)   ctrl+/
    long long lt2001a(vector<vector<int>>& rectangles)
    {
        unordered_map<double, int> map2;
        for (vector<int>& vi : rectangles)
        {
            double div = 1.0 * vi[0] / vi[1];
            map2[div]++;
        }
        long long ans = 0LL;
        for (auto& p : map2)
        {
            ans += 1L * (p.second - 1) * p.second / 2;
        }
        return ans;
    }

};

int main()
{

    LT2001 lt;

//    myvvi vv = {{4,8},{3,6},{15,30},{10,20}};
    myvvi vv = {{1,3},{2,8},{8,8},{2,8},{1,7},{2,5}};         // 2/8 != 2/8 ? 本地是1。  不， ans =  ans += 。。。 map的顺序不一致。

    cout<<lt.lt2001a(vv)<<endl;

    return 0;
}
