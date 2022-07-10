
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    // ��β�Ϳ�ʼ��sliding window, monodeque/multiset��
    // ��ǰ�±������ֵ���϶��� �Լ���ֵ + ����k���е���������ֵ��

    //deque<int> d{ 0 };
    //for (int i = 1; i < nums.size(); ++i) {
    //    if (d.front() + k < i)
    //        d.pop_front();
    //    nums[i] += nums[d.front()];
    //    while (!d.empty() && nums[d.back()] <= nums[i])
    //        d.pop_back();
    //    d.push_back(i);
    //}




//Runtime: 300 ms, faster than 53.67 % of C++ online submissions for Jump Game VI.
//Memory Usage : 156.9 MB, less than 5.05 % of C++ online submissions for Jump Game VI.
    // ������Զ�˿�ʼ������ÿ��ֵֻ����һ�Ρ�
    // tle  [-1,-1,-1...-1]
    // �����Χ������������ô�϶����������������
    // ���û����������
    // ���� top-down ?
    int lta(vector<int>& nums, int k)
    {
        int sz1 = nums.size();
        vector<int> vi(sz1, INT_MIN);
        vi[sz1 - 1] = nums[sz1 - 1];

        vector<int> nxt(sz1, -1);
        int idx = -1;
        for (int i = sz1 - 1; i >= 0; --i)
        {
            nxt[i] = idx;
            if (nums[i] >= 0)
                idx = i;
        }

        dfsa1(nums, vi, k, 0, nxt);

#ifdef __test
        showVectorInt(vi);
#endif

        return vi[0];
    }

    int dfsa1(vector<int>& nums, vector<int>& vi, int k, int idx, vector<int>& nxt)
    {
        if (idx >= nums.size())
            return INT_MIN;
        if (vi[idx] != INT_MIN)
            return vi[idx];

        if (nxt[idx] != -1 && (nxt[idx] - idx <= k))
        {
            return vi[idx] = nums[idx] + dfsa1(nums, vi, k, nxt[idx], nxt);
        }
        else
        {
            int mx = INT_MIN;
            unordered_set<int> set2;
            for (int i = k; i >= 1; --i)
            {
                if ((i + idx) < nums.size() && set2.find(nums[i + idx]) == set2.end())
                {
                    mx = max(mx, dfsa1(nums, vi, k, idx + i, nxt));
                    set2.insert(nums[i + idx]);
                }
            }
            return vi[idx] = mx + nums[idx];
        }

    }

};

int main()
{

    LT lt;

    //myvi v = { 1,-1,-2,4,-7,3 };
    //int k = 2;

    //myvi v = { 10,-5,-2,4,0,3 };
    //int k = 3;

    myvi v = { 1,-5,-20,4,-1,3,-6,-3 };
    int k = 2;

    cout << lt.lta(v, k) << endl;

    return 0;
}
