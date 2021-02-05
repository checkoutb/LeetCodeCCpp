
#include "../header/myheader.h"

class LT1425
{
public:

// D D

// deque


// decreasing deque
//We need to know the maximum in the window of size k.
//Use heqp will be O(NlogN)
//Use TreeMap will be O(NlogK)
//Use deque will be O(N)
// hepq ? heap?

//        deque<int> q;
//        int res = A[0];
//        for (int i = 0; i < A.size(); ++i) {
//            A[i] += q.size() ? q.front() : 0;
//            res = max(res, A[i]);
//            while (q.size() && A[i] > q.back())
//                q.pop_back();
//            if (A[i] > 0)
//                q.push_back(A[i]);
//            if (i >= k && q.size() && q.front() == A[i - k])
//                q.pop_front();
//        }
//        return res;




//Runtime: 184 ms, faster than 39.59% of C++ online submissions for Constrained Subsequence Sum.
//Memory Usage: 76.9 MB, less than 20.23% of C++ online submissions for Constrained Subsequence Sum.
    int lt1425c(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
                goto AAA;
            mx = max(mx, nums[i]);
        }
        return mx;

        AAA:
        vector<int> vi(sz1);
        map<int, int> map2;
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (map2.empty())
                mx = 0;
            else
            {
                while (map2.rbegin()->second + k < i)
                {
                    map2.erase(map2.rbegin()->first);
                }
                mx = map2.rbegin()->first;
            }
            mx += nums[i];
            vi[i] = max(0, mx);
            map2[vi[i]] = i;
        }
        return *max_element(begin(vi), end(vi));
    }


// error, multiset.erase   remove all ....
    int lt1425b(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
                goto AAA;
            mx = max(mx, nums[i]);
        }
        return mx;

        AAA:
//        priority_queue<int> priq;
        vector<int> vi(sz1);
//        map<int, int> map2;
        multiset<int> mset2;
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
//            vi[i] = max(0, nums[i]);
            mx = mset2.empty() ? 0 : *mset2.rbegin();
            mx += nums[i];
            #ifdef __test
            cout<<mx<<", "<<nums[i]<<endl;
            #endif // __test
            vi[i] = max(0, mx);
            mset2.insert(vi[i]);
            if (i >= k)
            {
//                #ifdef __test
//                cout<<mset2.size();
//                cout<<",   "<<vi[i - k]<<endl;
//                #endif // __test
                mset2.erase(vi[i - k]);
//                cout<<" . "<<mset2.size()<<endl;
            }

//            mx = 0;
//            if (map2.empty())
//            {
//
//            }


//            if (i - k > 0)
//            {
//                priq.pop(vi[i - k]);
//            }
//            int fnt = priq.front();


        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        return *max_element(begin(vi), end(vi));
    }


// tle
    int lt1425a(vector<int>& nums, int k)
    {
        vector<int> vi(nums.size());
        int ans = 0;
        int mx = INT_MIN;
        for (int i = 0; i < nums.size(); ++i)
        {
            mx = max(mx, nums[i]);
            vi[i] = max(0, nums[i]);
//            for (int j = i, m = 0; j >= 0 && m < k; --j,)
            for (int j = max(0, i - k); j < i; ++j)
            {
                vi[i] = max(vi[i], vi[j] + nums[i]);
            }
            ans = max(ans, vi[i]);
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        return ans > 0 ? ans : mx;
    }

};

int main()
{
    multiset<int> mset2({1,1,1,1,2,2});
    cout<<mset2.size()<<endl;
    mset2.erase(1);
    cout<<mset2.size()<<endl;           // ri, remove all...

    myvi v = {10,2,-10,5,20};     // 37
    int k{2};

//    myvi v = {-1,-2,-3};
//    int k{1};

//    myvi v = {10,-2,-10,-5,20};       // 23
//    int k{2};

//    myvi v = {-5266,4019,7336,-3681,-5767};
//    int k = 2;

//    myvi v = {10,0,0,5,20};     // 35
//    int k = 2;


    LT1425 lt;

    cout<<lt.lt1425c(v, k)<<endl;

    return 0;
}
