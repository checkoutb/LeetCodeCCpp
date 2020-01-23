
#include "../header/myheader.h"

class LT0710
{
public:



};


// discuss

// HashMap 做一个映射，把bklst中的数字 映射到 可用的数字。 先全部放入map，然后遍历bklst，一个指针从N-1开始，while指针在map中，就--. map[bk]=指针

// 自建class Interval 代表区间，包含low,high,preCount(保存了之前的interval的有效长度之和)。 while (low <= high) 二分搜索 List<Interval> intervals。

// hage 有一手，看不懂。全抄了。
//class Solution {
//public:
//    vector<int> v;
//    std::mt19937 gen;
//    std::uniform_int_distribution<> dis;
//    Solution(int N, vector<int> blacklist) {
//        v = blacklist;
//        sort(v.begin(), v.end());
//        v.push_back(N);
//        for (int i = 0; i < v.size(); i++) v[i] -= i;
//
//        std::random_device rd;  //Will be used to obtain a seed for the random number engine
//        gen = std::mt19937(rd()); //Standard mersenne_twister_engine seeded with rd()
//        dis = std::uniform_int_distribution<>(0, N - v.size());
//    }
//
//    int pick() {
//        int rnd = dis(gen);
//        auto it = upper_bound(v.begin(), v.end(), rnd) - 1;
//        int idx = it - v.begin();
//        return idx + rnd + 1;
//    }
//};

// v[i] -= i; 这样就不需要 63/67 的while循环了。6。





// 63 / 67 tle... 。。反向优化。。
class Solution {
    int sz;
    vector<int>* bklst;
public:
    Solution(int N, vector<int>& blacklist) {
        srand(time(NULL));
        sort(blacklist.begin(), blacklist.end());
        sz = N - blacklist.size();
        bklst = &blacklist;
    }

    int pick() {
        int index = rand() % sz;
        int ans = index;
        int bk = 0;

        vector<int>::iterator it = upper_bound(bklst->begin() + bk, bklst->end(), ans + bk);
        while (it != bklst->begin() + bk)
        {
            bk = it - bklst->begin();
            it = upper_bound(bklst->begin() + bk, bklst->end(), ans + bk);
        }

        return ans + bk;
    }
};



// 66 / 67 tle
class Solution3 {

    int sz;
    vector<int>* bklst;

public:
    Solution3(int N, vector<int>& blacklist) {
        srand(time(NULL));
        sort(blacklist.begin(), blacklist.end());
        sz = N - blacklist.size();
        bklst = &blacklist;
    }

    int pick() {
        int index = rand() % sz;
        int ans = 0;
        int bk = 0;
        for (int i = 0; i <= index;)
        {
            if (bk < bklst->size())
            {
                int t1 = bklst->operator[](bk);
                if (t1 > ans + index - i)
                {
                    ans += (index - i);
                    i = index + 1;
                }
                else
                {
                    bk++;
                    i += (t1 - ans);
                    ans = t1 + 1;
                }
            }
            else
            {
                ans += (index - i);
                i = index + 1;
            }
        }
        return ans;
    }
};


class Solution2 {

    int sz;
    vector<int>* bklst;

public:

    // 65 / 67 . tle.
    // blacklist 元素会不会重复？ 是否有序？..无序的。
    Solution2(int N, vector<int>& blacklist) {
        srand(time(NULL));
        std::sort(blacklist.begin(), blacklist.end());
        sz = N - blacklist.size();
        bklst = &blacklist;
    }

    int pick() {
        int index = rand() % sz;
        int ans = 0;
        int bk = 0;
        for (int i = 0; i <= index;)
        {
            if (bk < bklst->size() && ans == bklst->operator[](bk))
            {
                ans++;
                bk++;
            }
            else
            {
                ans++;
                i++;
            }
        }
        return ans - 1;
    }
};


int main()
{

    int n = 4;
    vector<int> bklst;
    bklst.push_back(2);
    bklst.push_back(1);
//    cout<<bklst.front()<<endl;

    Solution sol(n, bklst);

    for (int i = 0; i < 10; i++)
    {
        cout<<"   "<<sol.pick()<<endl;
    }
    cout<<endl;


    LT0710 lt;


    return 0;
}
