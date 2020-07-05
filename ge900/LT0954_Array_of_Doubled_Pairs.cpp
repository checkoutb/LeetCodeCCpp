
#include "../header/myheader.h"



// 有点问题。
// 这里2个if 都注释掉，就会[4，-2，2，-4]这个测试案例，就会爆出 signed integer overflow: 1073741824 * 2 cannot be represented in type 'int' 在最后一个else 的 int t3 = val * 2; 行
// 可能是 map2[t2] -= cnt 的问题？ 不。
// 估计是影响到了 iterator，但不知道为什么。 key都变了。。
// 这2个if 有任意一个就可以accept了。所以这段代码并不正确。
// 本地不会有问题。。。
// 。。。md。打印了下，就是 cnt==0时出了问题。 导致 map[1024] = 0, 然后 map[2048] = 0...
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {

        map<int, int> map2;
        for (int a : A)
            map2[a]++;

        for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            int val = it->first;
            int cnt = it->second;
//            if (cnt == 0)
//                continue;
//            if (val > 100000 || val < -100000)
//                continue;

            if (val < 0)
            {
                int t3 = val / 2;
                if (map2[t3] >= cnt)
                    map2[t3] -= cnt;
                else
                    return false;
            }
            else if (val == 0)
            {
                if (cnt % 2 != 0)
                    return false;
            }
            else
            {
                int t3 = val * 2;
                if (map2[t3] >= cnt)
                    map2[t3] -= cnt;
                else
                    return false;
            }
        }

        return true;
    }
};




class LT0954
{
public:


//Runtime: 228 ms, faster than 72.76% of C++ online submissions for Array of Doubled Pairs.
//Memory Usage: 57.9 MB, less than 72.83% of C++ online submissions for Array of Doubled Pairs.
    bool lt0954a(vector<int>& A)
    {
        map<int, int> map2;
        for (int a : A)
            map2[a]++;

        for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            int val = it->first;
            int cnt = it->second;

            cout<<val<<" : "<<cnt<<endl;

            if (cnt == 0)
                continue;
            if (val < 0)
            {

                int t3 = val / 2;
                if (t3 % 2 != 0)
                    return false;
                if (map2[t3] >= cnt)
                    map2[t3] -= cnt;
                else
                    return false;
            }
            else if (val == 0)
            {
                if (cnt % 2 != 0)
                    return false;
            }
            else
            {
                int t3 = val * 2;
                if (map2[t3] >= cnt)
                    map2[t3] -= cnt;
                else
                    return false;
            }

            for(auto& p : map2)
            {
                cout<<p.first<<", "<<p.second<<";  ";
            }
            cout<<endl;
        }

        return true;
    }

};

int main()
{

    vector<int> v = {4,-2,2,-4};
//    vector<int> v = {3,1,3,6};
//    vector<int> v = {1,2,4,16,8,4};

    LT0954 lt;

    cout<<lt.lt0954a(v)<<endl;


    cout<<"\n\n----------------\n\n";


    Solution sol;

    cout<<sol.canReorderDoubled(v)<<endl;



    return 0;
}
