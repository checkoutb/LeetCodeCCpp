
#include "../header/myheader.h"
#include <iomanip>

class LT0679
{
public:

// D D

//    private boolean dfs(List<Double> list) {
//        if (list.size() == 1) {
// list 不停地兼并，直到剩一个。


//def judgePoint24(self, nums):
//    if len(nums) == 1:
//        return math.isclose(nums[0], 24)
//    return any(self.judgePoint24([x] + rest)
//               for a, b, *rest in itertools.permutations(nums)
//               for x in {a+b, a-b, a*b, b and a/b})

//bool judgePoint24(vector<int>& nums){ return judge24({nums.begin(), nums.end()}); }
//
//static bool judge24(vector<double> nums) {
//    auto n = nums.size();
//    if(n == 1) return abs(nums[0] - 24) < 1e-10;
//
//    sort(nums.begin(), nums.end());
//    // For each permutation,
//    do {
//        // merge the last two numbers.
//        vector<double> temp(nums.begin(), nums.end()-1);
//        auto a = nums[n-1], b = nums[n-2];
//        for(auto num: {a+b, a-b, a*b, a?b/a:0}){
//            // For each merged number, combine with the rest and test it
//            temp.back() = num;
//            if(judge24(temp)) return true;
//        }
//    } while(next_permutation(nums.begin(), nums.end()));
//
//    return false;
//}



//Runtime: 28 ms, faster than 41.16% of C++ online submissions for 24 Game.
//Memory Usage: 14.2 MB, less than 31.16% of C++ online submissions for 24 Game.
    bool lt0679c(vector<int>& cards)
    {
        for (int i = 0; i < cards.size(); ++i)
        {
            int t2 = cards[i];
            cards[i] = -1;
            unordered_map<double, int> map2;
            map2[t2]++;
            if (dfsc1(cards, map2, 1))
                return true;
            cards[i] = t2;
        }

        // .
        #ifdef __test
        cout<<"half"<<endl;
        #endif // __test

        return func1(cards);
    }

    bool func1(vector<int>& vi)
    {
        unordered_map<double, int> map3;
        double d1 = vi[0];
        for (int i = 1; i < vi.size(); ++i)
        {
            map3.clear();
            double d2 = vi[i];
//            map3[d1 * d2]++;
            map3[d1 + d2]++;
            map3[d1 - d2]++;
//            map3[d1 / d2]++;
            map3[d2 - d1]++;
//            map3[d2 / d1]++;
            double d3 = -1;
            double d4 = -1;
            for (int j = 1; j < vi.size(); ++j)
            {
                if (j == i)
                    continue;
                if (d3 == -1)
                {
                    d3 = vi[j];
                }
                else
                {
                    d4 = vi[j];
                }
            }
            double d5 = d3 + d4;
            for (unordered_map<double, int>::iterator it = begin(map3); it != end(map3); it++)
            {
                if (d5 * it->first == 24)
                    return true;
                if (it->first != 0 && d5 / it->first == 24)
                    return true;
                if (d5 != 0 && it->first / d5 == 24)
                    return true;
            }
            d5 = d3 - d4;
            for (unordered_map<double, int>::iterator it = begin(map3); it != end(map3); it++)
            {
                if (d5 * it->first == 24)
                    return true;
                if (it->first != 0 && (d5 / it->first) == 24)
                    return true;
                if (d5 != 0 && (it->first / d5) == 24)
                    return true;
            }
            d5 = d4 - d3;
            for (unordered_map<double, int>::iterator it = begin(map3); it != end(map3); it++)
            {
                if (d5 * it->first == 24)
                    return true;
                if (it->first != 0 && (d5 / it->first) == 24)
                    return true;
                if (d5 != 0 && (it->first / d5) == 24)
                    return true;
            }
        }
        return false;
    }

    bool dfsc1(vector<int>& vi, unordered_map<double, int>& map2, int depth)
    {
        if (depth == 4)
        {
            #ifdef __test
            for (auto& p : map2)
                if (p.first > 23.99 && p.first < 24.02)
                {
//                    cout<<p.first<<", "<<p.second<<endl;
//                    printf("%.15f\n", p.first);
//                    cout<<map2[24.0]<<endl;
//                    cout<<setiosflags(ios::fixed)<<setprecision(15)<<p.first<<endl;          // include iomanip
                }
            #endif // __test
            for (auto& p : map2)
                if (p.first > 23.99999 && p.first < 24.00001)
                    return true;
//            return map2[24] != 0;
            return false;
        }
//            return map2.find(24) != map2.end();
//        vector<double> vd;
        for (int i = 0; i < vi.size(); ++i)
        {
            if (vi[i] == -1)
                continue;
            unordered_map<double, int> map3;
            double t2 = vi[i];
            int x2 = vi[i];
            vi[i] = -1;

            for (unordered_map<double, int>::iterator it = begin(map2); it != end(map2); it++)
            {
                map3[it->first * t2]++;
                map3[it->first + t2]++;
                map3[it->first - t2]++;
                if (t2 != 0)
                    map3[it->first / t2]++;
                map3[t2 / it->first]++;
                if (it->first != 0)
                    map3[t2 - it->first]++;
            }

            if (dfsc1(vi, map3, depth + 1))
                return true;

            vi[i] = x2;

//            vd.clear();
//            if (vi[i] == -1)
//                continue;
//            double t2 = vi[i];
//            int x2 = vi[i];
//            vi[i] = -1;
//            for (unordered_map<double, int>::iterator it = begin(map2); it != end(map2); it++)
//            {
//                vd.push_back(it->first * t2);
//                vd.push_back(it->first + t2);
//                vd.push_back(it->first - t2);
//                vd.push_back(it->first / t2);
//                vd.push_back(t2 / it->first);
//            }
//            for (double d : vd)
//            {
//                map2[d]++;
//            }
//            dfsc1(vi, map2, depth + 1);
//
//
//
//            vi[i] = x2;
        }
        return false;
    }



//// error
//    bool lt0679b(vector<int>& cards)
//    {
//        int sz1 = cards.size();
//        unordered_map<double, int> map2;
//        for (int i = 0; i < sz1; ++i)
//        {
//            double t1 = cards[i];
//            int x1 = cards[i];
//            map2[t1]++;
//            cards[i] = -1;
//            for (int i2 = 0; i2 < sz1; ++i2)
//            {
//                if (cards[i2] == -1)
//                    continue;
//                double t2 = cards[i2];
//                int x2 = cards[i2];
//
//                // ....
//                // 需要和所有的数做一个加减乘除。。
//
//                for (int i3 = 0; i3 < sz1; ++i3)
//                {
//                    if (cards[i3] == -1)
//                        continue;
//                    double t3 = cards[i3];
//                    int x3 = cards[i3];
//                    for (int i4 = 0; i4 < sz1; ++i4)
//                    {
//
//                    }
//                }
//                cards[i2] = x2;
//                map2[t2]--;
//                if (map2[t2] == 0)
//                    map2.erase(t2);
//            }
//            cards[i] = x1;
//            map2.erase(t1);
//        }
//    }
//
//    bool dfsb1(vector<int>& vi, unordered_map<double, int> map2, double result, int depth)
//    {
//        if (depth == 4)
//        {
//            return result == 24.0;
//        }
//        for (int i = 0 ; i < vi.size(); ++i)
//        {
//            if (vi[i] == -1)
//                continue;
//            int t2 = vi[i];
//            vi[i] = -1;
//            for ()
//            dfsb1(vi, map2, result, depth + 1);
//            vi[i] = t2;
//        }
//    }



// .... 4 1 7 8  这里有括号的。。
//4 / (1 - 2 / 3) = 4 / (1 / 3) = 12
// 和之前一道差不多，把自己传递到下一层。
    bool lt0679a(vector<int>& cards)
    {
        for (int i = 0; i < cards.size(); ++i)
        {
            int t2 = cards[i];
            cards[i] = -1;
            if (dfsa1(cards, cards[i], 0.0, 1))
                return true;
            cards[i] = t2;
        }

        return false;
    }

    bool dfsa1(vector<int>& vi, double prev, double result, int depth)
    {
        if (depth == 4)
        {
            #ifdef __test
            cout<<result<<", "<<prev<<endl;
            #endif // __test
            return (result + prev) == 24.0;          // > 0.0001 ?
        }
        for (int i = 0; i < vi.size(); ++i)
        {
            if (vi[i] == -1)
                continue;
            int t2 = vi[i];
            vi[i] = -1;

            // 全加。

            dfsa1(vi, t2, result + prev, depth + 1);
            dfsa1(vi, -t2, result + prev, depth + 1);
            dfsa1(vi, prev * t2, result, depth + 1);
            dfsa1(vi, prev / t2, result, depth + 1);

            vi[i] = t2;
        }
        return false;
    }

};

int main()
{
//    cout<<(4.0 / (1.0 - (2.0 / 3.0)))<<endl;

//    myvi v = {4,1,8,7};       // 7-4 * 8 * 1    流
//    myvi v = {1,2,1,2};
//    myvi v = {2,12,2,1};
//    myvi v = {6,6,6,6};
//    myvi v = {1,9,1,2};     // 9-1  *   1+2     分开合并。。mergeSort？
    myvi v = {3,3,8,8};

    LT0679 lt;

    cout<<lt.lt0679c(v)<<endl;

    return 0;
}
