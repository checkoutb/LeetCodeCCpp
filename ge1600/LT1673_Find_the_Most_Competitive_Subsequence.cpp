
#include "../header/myheader.h"

class LT1673
{
public:

// D

//    for (auto i = 0; i < n.size(); ++i) {
//        while (!s.empty() && s.back() > n[i] && s.size() + n.size() - i > k)
//            s.pop_back();
//        if (s.size() < k)
//            s.push_back(n[i]);
//    }

// 区间最大就要用 stack。


// error.  虽然不是整个数组的最小，但是 是 前 sz1-k 里的 最小。
    vector<int> lt1673b(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        vector<int> ans(k);
        vector<int> arr(nums.size());
        arr[sz1 - 1] = nums[sz1 - 1];
        for (int i = sz1 - 2; i >= 0; --i)
        {
            arr[i] = min(nums[i], arr[i + 1]);
        }
        int i = 0;
        int k3 = k;
        while (k-- > 0)
        {
            for (; i < sz1 - k; i++)
            {
                if (arr[i] == nums[i])
                {
                    ans[k3 - k - 1] = nums[i];
//                    i++;
                    break;
                }
            }
            if (i == sz1 - k)
            {
                ans[k3 - k - 1] = nums[i - 1];
            }
            else
            {
                i++;
            }
        }
        return ans;
    }


// tle.
// 前 sz1 - k 个 最小值 第一次出现的地方。
    vector<int> lt1673a(vector<int>& nums, int k)
    {
        vector<int> ans(k);
//        unordered_map<int, int> map2;
        int st = 0;
        int sz1 = nums.size();
        while (k-- > 0)
        {
//            map2.clear();
            int mn = INT_MAX;
            int mni = -1;
            for (int i = st; i < sz1 - k; i++)
            {
//                if (map2.find(nums[i]) == map2.end())
//                    map2[nums[i]] = i;
//                mn = min(mn, nums[i]);
                if (nums[i] < mn)
                {
                    mn = nums[i];
                    mni = i;
                }
            }
//            cout<<mni<<", "<<st<<", "<<k<<endl;
            ans[k] = mn;
            nums[mni] = INT_MAX;
            st = mni + 1;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }

};

int main()
{
//    myvi v = {3,5,2,6};
//    int k = 2;

//    myvi v = {2,4,3,3,5,4,9,6};
//    int k = 4;

//    myvi v = {71,18,52,29,55,73,24,42,66,8,80,2};
//    int k{3};

    myvi v = {84,10,71,23,66,61,62,64,34,41,80,25,91,43,4,75,65,13,37,41,46,90,55,8,85,61,95,71};
    int k{24};


    LT1673 lt;

    vector<int> vi = lt.lt1673b(v, k);

    showVectorInt(vi);

    return 0;
}
