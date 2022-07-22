
#include "../header/myheader.h"

class LT1224
{
public:

    // D D



    //One bucket(all elements have the same frequency) :
    //    Single number repeats many times.
    //    All numbers repeat one time.
    //Two buckets(all elements have either frequency count 1 or count 2) :
    //    One bucket has frequency of 1, and only one element.
    //    One bucket has frequency of n + 1 and only one element.All other elements repeat n times.



        //all elements appear exact once.
        //all elements appear max_F times, except one appears once.
        //all elements appear max_F - 1 times, except one appears max_F.
    //if maxF* freq[maxF] == i or (maxF - 1) * (freq[maxF - 1] + 1) == i or maxF == 1:





    // 单元素，key=1，说明 所有的数 都只出现了一次， 所以随便删除一个数， 剩余的数 都是出现1次，符合
    // 单元素+ value=1， 说明 只有一个数([1,1,1])，  也是符合的
//Runtime: 95 ms, faster than 93.44 % of C++ online submissions for Maximum Equal Frequency.
//Memory Usage : 43.7 MB, less than 89.62 % of C++ online submissions for Maximum Equal Frequency.
    // 前缀，移除一个后，所有的数的次数相同。
    // 双map，  2个元素，且一个key是另一个key+1， 且value=1
    int lt1224a(vector<int>& nums)
    {
        unordered_map<int, int> map2;           // num:count
        map<int, int> map3;                 // count:count

        for (int i : nums)
            map2[i]++;

        for (pair<const int, int>& p : map2)
        {
            //cout<<to_string(decltype(p));     // ...
            map3[p.second]++;
        }

        for (int i = nums.size() - 1; i >= 0; --i)
        {
            if (map3.size() == 2)
            {
#ifdef __test
                cout << i << " -- [";
                for (auto& p : map2)
                {
                    cout << p.first << ":" << p.second << ", ";
                }
                cout << "]]]]      [";
                for (auto& p : map3)
                {
                    cout << p.first << ":" << p.second << ", ";
                }
                cout << "] \n";
#endif
                if (map3.begin()->first == 1 && map3.begin()->second == 1)
                {
                    return i + 1;
                }
                if (map3.rbegin()->first == map3.begin()->first + 1 && map3.rbegin()->second == 1)
                    return i + 1;
            }
            if (map3.size() == 1 && (map3.begin()->first == 1 || map3.begin()->second == 1))
            {
                return i + 1;
            }

            int t2 = nums[i];
            map3[map2[t2]]--;
            if (map3[map2[t2]] == 0)
            {
                map3.erase(map2[t2]);
            }
            map2[t2]--;
            if (map2[t2] != 0)
                map3[map2[t2]]++;
        }
        return 0;
    }

};

int main()
{

    LT1224 lt;

    //myvi v = { 2,2,1,1,5,3,3,5 };
    //myvi v = { 1,1,1,2,2,2,3,3,3,4,4,4,5 };
    //myvi v = { 1,1,1,1,3,3 };
    //myvi v = {10,2,8,9,3,8,1,5,2,3,7,6};
    //myvi v = { 1,2 };
    myvi v = { 1,1 };

    cout << lt.lt1224a(v) << endl;

    return 0;
}
