
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        sort(nums.begin(), nums.end());
//        for(int i=0; i<n; i++){
//            int low=i+1;
//            int high = n-1;
//            while(low<high){
//                int sum = nums[i] + nums[low]+nums[high];
//                if(abs(target-sum) < abs(closest)){
//                    closest = abs(target-sum);
//                    ans = sum;
//                }
//                if(sum<target)
//                    low++;
//                else
//                    high--;
//                if(target==sum)
//                    return ans;
//            }
//        }
//


//        for(int i=0;i<n;i++)
//        {
//            for(int j=i+1;j<n-1;j++)
//            {
//                int x=t-v[i]-v[j];
//                int r=upper_bound(v.begin()+j+1,v.end(),x)-v.begin();
//                int l=r-1;
//                if(r<n && abs(x-v[r])<abs(d)) d=x-v[r];
//                if(l>j && abs(x-v[l])<abs(d)) d=x-v[l];
//            }
//        }
//        return t-d;

//    int diff = INT_MAX, sz = nums.size();
//    sort(begin(nums), end(nums));
//    for (int i = 0; i < sz && diff != 0; ++i) {
//        int lo = i + 1, hi = sz - 1;
//        while (lo < hi) {
//            int sum = nums[i] + nums[lo] + nums[hi];
//            if (abs(target - sum) < abs(diff))
//                diff = target - sum;
//            if (sum < target)
//                ++lo;
//            else
//                --hi;
//        }
//    }
//    return target - diff;



// AC ...  tu le....
// 3个值是唯一的。所以不能计算2sum，然后二分，  map压缩下。
    int lta(vector<int>& nums, int target)
    {
        map<int, int> map2;
        for (int n : nums)
            map2[n]++;
        int ans = 1000'0000;        // wangji shibushi '
        #ifdef __test
        for (auto p : map2)
            cout<<p.first<<", "<<p.second<<endl;
        #endif // __test
        for (map<int, int>::iterator it = begin(map2); it != end(map2); it++)
        {
            if (it->second > 2)
            {
                if (abs(ans - target) > abs(it->first * 3 - target))
                {
                    ans = it->first * 3;
                }
            }
            if (it->second > 1)
            {
                int tar = target - it->first * 2;
                map<int, int>::iterator it2 = map2.lower_bound(tar);
                #ifdef __test
                cout<<it2->first<<endl;
                #endif // __test
                if (it2 != end(map2) && (it2->first != it->first) && (abs(ans - target) > abs(it2->first - tar)))
                {
                    ans = it->first * 2 + it2->first;
                }
                if (it2 != end(map2) && it2->first == it->first)
                {
                    map<int, int>::iterator it3 = it2;
                    it3++;
                    if (it3 != end(map2) && (abs(ans - target) > abs(it2->first - tar)))
                    {
                        ans = it->first * 2 + it3->first;
                    }
                }
                if (it2 != begin(map2))
                {
                    it2--;
                    #ifdef __test
                    cout<<" . .. ? "<<endl;
                    #endif // __test
                    if ((it2->first != it->first) && (abs(ans - target) > abs(it2->first - tar)))
                    {
                        ans = it->first * 2 + it2->first;
                    }
//                    if (it2 != begin(map2) && it2->first == it->first)        // lower_bound --   << key
//                    {
//                        it2--;
//                        if (it2 != begin(map2) && (abs(ans - target) > abs(it->first - tar)))
//                        {
//                            ans = it->first * 2 + it2->first;
//                        }
//                    }
                }
            }
        }
        #ifdef __test
        cout<<" ==============                    "<<ans<<endl;
        for (auto p : map2)
            cout<<p.first<<", "<<p.second<<endl;
        #endif // __test
        for (map<int, int>::iterator it = begin(map2); it != end(map2); it++)
        {
            map<int, int>::iterator it2 = it;           // copy or ref ?
//            if (it2->second == 1)
//            {
                it2++;
//            }


            int t1 = target - it->first;
            #ifdef __test
            cout<<" . . ..start  .      ."<<it->first<<", "<<it2->first<<", "<<t1<<endl;            // different..   so clone.
            #endif // __test
            for (; it2 != end(map2); it2++)
            {
                int tar = t1 - it2->first;
                map<int, int>::iterator it3 = map2.lower_bound(tar);
                if (it3 != end(map2))
                {
                    if (it3->first <= it2->first)
                    {
                        map<int, int>::iterator it4 = it2;
                        it4++;
                        if (it4 != end(map2))
                        {
                            if (abs(target - ans) > abs(it4->first - tar))
                            {
                                #ifdef __test
                                cout<<"zz   "<<target<<", "<<ans<<", "<<(it4->first)<<", "<<tar<<endl;
                                #endif // __test
                                ans = it->first + it2->first + it4->first;
                            }
                        }
                        break;

//                        cout<<it3->first<<endl;
//                        break;
//                        continue;
                    }
                }
                #ifdef __test
                cout<<"  1     "<<tar<<", "<<((bool) (it3 == end(map2)))<<",       "<<(it->first)<<", "<<(it2->first)<<", "<<(it3->first)<<endl;
//                cout<<map2[it3->first]<<endl;
                #endif // __test
                #ifdef __test
                cout<<target<<", "<<ans<<", "<<tar<<", "<<(it3->first)<<endl;
                #endif // __test
                if (it3 != end(map2) && (it3->first != it2->first) && (it3->first != it->first) && abs(target - ans) > abs(it3->first - tar))
                {

                #ifdef __test
                cout<<"  2     "<<tar<<", "<<((bool) (it3 == end(map2)))<<",       "<<(it->first)<<", "<<(it2->first)<<", "<<(it3->first)<<endl;
//                cout<<map2[it3->first]<<endl;
                #endif // __test
                    ans = it->first + it2->first + it3->first;
                }
                it3--;      // it3 > it2 > it1
                if ((it3->first != it2->first) && (it3->first != it->first) && (abs(target - ans) > abs(it3->first - tar)))
                {

                #ifdef __test
                cout<<"   3    "<<tar<<", "<<((bool) (it3 == end(map2)))<<",       "<<(it->first)<<", "<<(it2->first)<<", "<<(it3->first)<<endl;
//                cout<<map2[it3->first]<<endl;
                #endif // __test
                    ans = it->first + it2->first + it3->first;
                }

        #ifdef __test
        cout<<" - - -- "<<endl;
//        for (auto p : map2)
//            cout<<p.first<<", "<<p.second<<endl;
        cout<<" - -+++---------------------+ -- "<<ans<<endl;
        #endif // __test

                // tai fan le...
//                map<int, int>::iterator it3 = map2.lower_bound(tar);
//                int t3 = it3->first;
//                if (t3 < t2)
//                {
//                    break;
//                }
//                if (t3 == t1)
//                {
//                    if (t3 == t2)
//                    {
//                        if (it2->second > 2)
//                        {
//                            if (abs(ans - target) > abs(tar - t3))
//                            {
//                                ans = it->first + it2->first + t3;
//                            }
//                        }
//                    }
//                    else
//                    {
//
//                    }
//                }
//                else if (t3 == t2)
//                {
//                    if (it2->second > 1)
//                    {
//                        if (abs(ans - target) > abs(tar - t3))
//                        {
//                            ans = it->first + it2->first + t3;
//                        }
//                    }
//                }
//                else
//                {
//                    if (abs(ans - target) > abs(tar - t3))
//                    {
//                        ans = it->first + it2->first + t3;
//                    }
//                    if (it3 != begin(map2))
//                    {
//                        it3--;          // ..       // .. == it ?
//                        int t4 = it3->first;
//                        if (abs(ans - target) > abs(tar - t4))
//                        {
//                            ans = it->first + it2->first + t4;
//                        }
//                    }
//                }

//                if (std::distance...)                // it2 < it3 ?  operator< ?

//                map<int, int>::iterator it3 = it2;
//                if (it3->second == 1)
//                    it3++;
//                std::lower_bound(it3, end(map2), )
//                map2.lower_bound(key...);         // ...

                // 不需要，只要判断下， 第三个数 是不是 == it2 。 是就break。
//                if (abs(2 * (it2->first) + it->first - target) > abs(ans - target))
//                if (abs((t1 - 2 * (it2->first))) > abs(ans - target))
//                {
//                    break;
//                }
//                if ((it2->first - tar) > ())       // 只搜后面的。 map有序
//                {
//
//                }
//                int tar = target - t1
//                int t2 = it2->first;
//                if (t1 + t2 >)
            }
        }
        return ans;
    }

};

int main()
{
//    myvi v = {-1,2,1,-4};
//    int tar = 1;

//    myvi v = {1,2,0};
//    int tar = 0;

//    myvi v = {1,1,-1};
//    int tar = 2;

    myvi v = {0,2,1,-3};
    int tar = 1;

    LT lt;

    cout<<lt.lta(v, tar)<<endl;

    return 0;
}
