
#include "../../header/myheader.h"

class LT
{
public:


    // D D

    //def longestConsecutive(self, nums) :
    //    nums = set(nums)
    //    best = 0
    //    for x in nums :
    //if x - 1 not in nums :
    //y = x + 1
    //    while y in nums :
    //y += 1
    //    best = max(best, y - x)
    //    return best
    //
    // �����о���hash�Ĺ̶����ĵ�O(n) ��ʵ������£����ܱ� �����O(nlogn)�������
    // ����Ӧ��û�� �ҵ� uf �� sort �����ֲ�ࡣ


    //if (valToIndex.containsKey(nums[i])) {
    //    continue;
    //}
    //
    //if (valToIndex.containsKey(nums[i] - 1)) {
    //    uf.union(i, valToIndex.get(nums[i] - 1));
    //}
    //
    //if (valToIndex.containsKey(nums[i] + 1)) {
    //    uf.union(i, valToIndex.get(nums[i] + 1));
    //}



    //int num = nums[i];
    //while (set.contains(--num)) {
    //    count++;
    //    set.remove(num);
    //}
    // remove ������ set��������ײ�� ���������о��ȶ���set�����á� ��ѯ�ܿ�ġ� �޸ĵĻ����ʱ�ࡣ �ÿ�ʵ�ʲ��������


    //unordered_map<int, int> m;
    //int r = 0;
    //for (int i : num) {
    //    if (m[i]) continue;
    //    r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
    //}



    // O(n) ������ʲô����
//Runtime: 75 ms, faster than 96.78 % of C++ online submissions for Longest Consecutive Sequence.
//Memory Usage : 33.8 MB, less than 85.63 % of C++ online submissions for Longest Consecutive Sequence.
    /// .. ���ظ�ֵ����
    int ltb(vector<int>& nums)
    {
        if (nums.size() <= 1)
            return nums.size();

        sort(begin(nums), end(nums));
        int ans = 0;
        int t2 = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                ;
            }
            else if (nums[i] == nums[i - 1] + 1)
            {
                t2++;
            }
            else
            {
                ans = max(ans, t2);
                t2 = 1;
            }
        }
        ans = max(ans, t2);
        return ans;
    }




    // ���ظ�ֵ������ if (uf.find(n) != uf.end()) {continue;} ��
//Runtime: 255 ms, faster than 54.42 % of C++ online submissions for Longest Consecutive Sequence.
//Memory Usage : 54.8 MB, less than 6.88 % of C++ online submissions for Longest Consecutive Sequence.
//
//Runtime: 479 ms, faster than 41.01 % of C++ online submissions for Longest Consecutive Sequence.
//Memory Usage : 54.8 MB, less than 6.91 % of C++ online submissions for Longest Consecutive Sequence.
    // sort + for ... 
    // uf. ���� map �㲻�� O(1) ? �����Ļ��� ֱ�� for ��ӵ�map��Ȼ�� ����map Ҳ�����ˡ������������unordered_map��
    //      unordered_map Ӧ����O(1)�� mapӦ�ò��㡣
    int lta(vector<int>& nums)
    {
        unordered_map<int, int> uf;
        for (int n : nums)
        {
            if (uf.find(n) != uf.end())
                continue;
            int t2 = ufa(uf, n - 1);
            int t3 = ufa(uf, n + 1);
            if (t2 != INT_MIN)
            {
                uf[t2] = n;
            }
            if (t3 != INT_MIN)
                uf[t3] = n;
            uf[n] = INT_MAX;
        }
        unordered_map<int, int> map2;
        for (auto& p : uf)
        {
            map2[ufa(uf, p.first)]++;
        }
        int ans = 0;
        for (auto& p : map2)
        {
            ans = max(ans, p.second);
        }
        return ans;
    }

    int ufa(unordered_map<int, int>& uf, int idx)
    {
        if (uf.find(idx) == uf.end())
            return INT_MIN;
        if (uf[idx] == INT_MAX)
            return idx;
        int t2 = ufa(uf, uf[idx]);
        uf[idx] = t2;
        return t2;
    }

};

int main()
{

    LT lt;

    myvi v = { 0,-1 };

    cout << lt.lta(v) << endl;

    return 0;
}
