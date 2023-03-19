
#include "../header/myheader.h"

class LT1546
{
public:

    // D D


    //unordered_map<int, int> um;
    //um[0] = -1;
    //int sum = 0, right = -1, ans = 0;
    //for (int i = 0; i < nums.size(); i++) {
    //    sum += nums[i];
    //    if (um.count(sum - target)) {
    //        int left = um[sum - target];
    //        if (right <= left) {
    //            ans++;
    //            right = i;
    //        }
    //    }
    //    um[sum] = i;
    //}


    //Map<Integer, Integer> map = new HashMap<>();
    //map.put(0, 0);

    //int res = 0;
    //int sum = 0;

    //for (int i = 0; i < nums.length; ++i) {
    //    sum += nums[i];
    //    if (map.containsKey(sum - target)) {
    //        res = Math.max(res, map.get(sum - target) + 1);
    //    }
    //    map.put(sum, res);
    //}



    //Runtime309 ms
    //    Beats
    //    20.33 %
    //    Memory89.3 MB
    //    Beats
    //    20.73 %
    int lt1546b(vector<int>& nums, int target)
    {
        int sz1 = nums.size();
        map<int, int> map2 = { {0,-1} };
        vector<int> vi(sz1);
        int sum2 = 0;
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            sum2 += nums[i];
            t2 = sum2 - target;
            if (map2.find(t2) != map2.end())
            {
                vi[i] = max(i == 0 ? 0 : vi[i - 1], (map2[t2] >= 0 ? vi[map2[t2]] : 0) + 1);
            }
            else
            {
                vi[i] = i == 0 ? 0 : vi[i - 1];
            }
            map2[sum2] = i;
        }
        return vi[sz1 - 1];
    }


    // error, ÓÐ¸ºÊý¡£
    int lt1546a(vector<int>& nums, int target)
    {
        int sz1 = nums.size();
        vector<int> vi(sz1);
        int st = 0;
        int sum2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            sum2 += nums[i];
            while (sum2 > target)
            {
                sum2 -= vi[st++];
            }
            if (sum2 == target)
            {
                vi[i] = max(i == 0 ? 0 : vi[i - 1], (st == 0 ? 0 : vi[st - 1]) + 1);
            }
            else
            {
                vi[i] = vi[i - 1];
            }
        }

        return vi[sz1 - 1];
    }

};

int main()
{

    LT1546 lt;

    //myvi v = { 1,1,1,1,1 };
    //int t = 2;

    myvi v = { -1,3,5,1,4,2,-9 };
    int t = 6;

    cout << lt.lt1546b(v, t) << endl;

    return 0;
}
