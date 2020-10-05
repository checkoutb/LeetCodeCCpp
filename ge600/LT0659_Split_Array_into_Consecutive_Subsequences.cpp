
#include "../header/myheader.h"

class LT0659
{
public:



// D D

//        unordered_map<int, int> left, end;
//        for (int i: A) {
//            left[i]++;
//        }
//        for (int i: A) {
//            if (left[i] == 0) continue;
//            left[i]--;
//            if (end[i - 1] > 0) {
//                end[i - 1]--;
//                end[i]++;
//            } else if (left[i + 1] > 0 && left[i + 2] > 0) {
//                left[i + 1]--;
//                left[i + 2]--;
//                end[i + 2]++;
//            } else {
//                return false;
//            }
//        }
//        return true;

// end[i] 是否能作为结束，如果 -1值能作为结束，那么自己也可以作为结束，并且 -1结束的subseq数量 减少1。
// 如果 没有subseq以 -1作为结束，则判断 自己能否作为一个subseq的 起始点。



//Runtime: 136 ms, faster than 99.58% of C++ online submissions for Split Array into Consecutive Subsequences.
//Memory Usage: 54.7 MB, less than 90.91% of C++ online submissions for Split Array into Consecutive Subsequences.
    bool lt0659a(vector<int>& nums)
    {
        vector<int> v;
        int lstN = nums[0] - 1;
        for (int i = 0; i < nums.size();)
        {
            int j = i;
            if (lstN + 1 != nums[i])
            {
                for (int t3 : v)
                {
                    if (t3 < 3)
                        return false;
                }
                v.clear();
            }
//            cout<<i<<", ";
            while (j < nums.size() && nums[j] == nums[i])
            {
                j++;
            }
            int cnt = j - i;
            if (cnt > v.size())
            {
                for (int m = 0; m < v.size(); m++)
                {
                    v[m] = v[m] + 1;
                }
                while (v.size() < cnt)
                {
                    v.push_back(1);
                }
            }
            else if (cnt < v.size())
            {
                int del = 0;
                for (int m = 0; m < v.size(); m++)
                {
                    if (v[m] >= 3)
                    {
                        v.erase(v.begin() + m);
                        del++;
                        m--;
                    }
                    if (v.size() == cnt)
                        break;
                }
                if (v.size() != cnt)
                    return false;
                for (int m = 0; m < v.size(); m++)
                {
                    v[m] = v[m] + 1;
                }
            }
            else
            {
                for (int m = 0; m < v.size(); m++)
                {
                    v[m] = v[m] + 1;
                }
            }
            lstN = nums[i];
            i = j;
        }
        for (int n : v)
        {
            if (n < 3)
                return false;
        }
        return true;
    }

};

int main()
{

//    vector<int> v = {1,2,3,3,4,5};
//    vector<int> v = {1,2,3,3,4,4,5,5};
    vector<int> v = {1,2,3,4,4,5};

    LT0659 lt;

    cout<<lt.lt0659a(v)<<endl;

    return 0;
}
