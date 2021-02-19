
#include "../header/myheader.h"

class LT1681
{
public:

// D

// dp ...  bit ,  O(n*n*2^n) ....

// brute force

// dfs

// python的代码 相比其他，真的短


// error    6,3,8,1,3,1,2,2   11223368  12 12 36 38
// 感觉是sort，然后 k个bucket， 螺旋赋值。 但这是hard啊。  不，不是横者螺旋，要竖着。 ans是 每个set的最大差的和。 但是hard。。。
    int lt1681a(vector<int>& nums, int k)
    {
        map<int, int> map2;     // value : count
        for (int i : nums)
            map2[i]++;
        int ans = 0;
        int szmx = nums.size() / k;
        while (!map2.empty())
        {
            int fst = -1;
            int lst = -1;
            int t2 = szmx;
            for (map<int, int>::iterator it = map2.begin(); it != map2.end();)
            {
                #ifdef __test
                cout<<it->first<<" = = "<<it->second<<endl;
                #endif // __test
                if (fst == -1)
                    fst = it->first;
                lst = it->first;
                if (it->second == 1)
                    map2.erase(it++);
                else
                {
                    it->second = it->second - 1;
                    it++;
                }
//                    map2[it->first] = it->second - 1;
                t2--;
                if (t2 == 0)
                    break;
            }
            ans += (lst - fst);
            #ifdef __test
            cout<<lst<<" - "<<fst<<endl;
            #endif // __test

            if (map2.size() < szmx && map2.size() != 0)
                return -1;

//            int t2 = szmx;
//            for (map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
//            {
//
//                t2--;
//                if (t2 == 0)
//                    break;
//            }
//            if (t2 != 0)
//                return -1;

//            map<int, int>::iterator it = map2.begin();
////            vector<int> del;
//            for (int i = 0; i < szmx; ++i)
//            {
//                if (it == map2.end())
//                    return -1;
//                val = it.second;
//                if (val == 1)
//                {
//
//                }
//                else
//                {
//                    it.second -= 1;
//                }
//            }
        }
        return ans;
    }

};

int main()
{
    map<int, int> map2 = {{2,3},{4,5},{7,8}};
    for (map<int, int>::iterator it = map2.begin(); it != map2.end();)
    {
        cout<<it->first<<" : "<<it->second<<endl;
        if (it->first == 2)
        {
            map2.erase(it++);
        }
        else
        {
            it->second = -1;
            it++;
        }
    }
    // ....
    for (auto& p : map2)
    {
        cout<<p.first<<" :-: "<<p.second<<endl;
    }
    cout<<endl<<endl<<endl;

//    myvi v = {1,2,1,4};
//    int k = 2;

    myvi v = {6,3,8,1,3,1,2,2};
    int k = 4;

    LT1681 lt;

    cout<<lt.lt1681a(v, k)<<endl;

    return 0;
}
