
#include "../header/myheader.h"



//        for(int i=0;i<n;++i) {
//            int random = rand() % n;
//            swap(shuff[i], shuff[random]);
//        }

//        while( k > 0) {
//            int val = rand() % k;
//            swap(shuffled[k-1], shuffled[val]);
//            k--;
//        }

// 。。。。。。。。。。。。。。。。。。。。。。



//Runtime: 204 ms, faster than 88.19% of C++ online submissions for Shuffle an Array.
//Memory Usage: 30.4 MB, less than 13.01% of C++ online submissions for Shuffle an Array.


// Any permutation of [1,2,3] must equally likely to be returned.
// 1.每次 rand % sz1..如果这个下标有值，就往后。不过这种不是 平均。当数值出现聚集以后，每次rand%sz1 落在这个聚集中的几率大于其他空节点。聚集越来越大。
// 2.每次 rand % (sz1 - i) == a, 从头开始跳过已有值的节点，第a个节点就是 值的点。

class Solution {
    vector<int> v2;
    int sz1;
public:
    Solution(vector<int>& nums) {
        v2 = nums;
        sz1 = v2.size();
        srand(time(NULL));
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v2;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> v3(sz1, INT_MIN);

        #ifdef __test
//        for_each(v3.begin(), v3.end(), fun_cout);
        cout<<endl;
        #endif // __test

        for (int i = 0; i < sz1; i++)
        {
            int t1 = v2[i];
            int t2 = (rand() % (sz1 - i));

            #ifdef __test
            cout<<"  "<<i<<", "<<t2;
//            cout<<"      "<<rand()<<"..."<<rand()<<","<<rand()<<"."<<rand();
            #endif // __test

            int j = -1;
            while (t2 >= 0)         // t2 == 0,也要进入while循环，因为第一个已有值的话，需要后移。
            {
                j++;
                if (v3[j] == INT_MIN)
                {
                    t2--;
                }
            }

            #ifdef __test
            cout<<"   "<<t2<<", "<<j<<", "<<t1<<""<<endl;
            #endif // __test

            v3[j] = t1;
        }
        return v3;
    }
};

int main()
{
    int nums[] = {1,2,3};
//    vector<int> v1 = {1,2,3};
    vector<int> v1(begin(nums), end(nums));
    Solution s(v1);
    cout<<endl;

    v1 = s.shuffle();
    for_each(v1.begin(), v1.end(), fun_cout);
    cout<<endl;

    v1 = s.reset();
    for_each(v1.begin(), v1.end(), fun_cout);
    cout<<endl;

    v1 = s.shuffle();
    for_each(v1.begin(), v1.end(), fun_cout);
    cout<<endl;

    return 0;
}
