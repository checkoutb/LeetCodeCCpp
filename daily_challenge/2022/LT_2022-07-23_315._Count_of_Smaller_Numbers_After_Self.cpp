
#include "../../header/myheader.h"

class LT
{
public:


    // D

    // merge sort
    // ��Ϊ��merge������ left[]�Ķ��� right[]��ǰ�档
    // ��Ϊ sort������ ������left[i] С��ֵ���±�ʱ�� ���Ը��� left[i-1] �������ı���С��ֵ���±�








    // wrong answer
    // tle
    vector<int> lta(vector<int>& nums)
    {
        int sz1 = nums.size();
        vector<int> ans(sz1, 0);
        vector<int> vi;
        vector<int>::iterator it = begin(vi);

        for (int i = sz1 - 1; i >= 0; --i)
        {
#ifdef __test
            cout << i << endl;
#endif

            int t2 = nums[i];
            if (i < sz1 - 1)
            {
                if (nums[i] == nums[i + 1])
                {
                    ans[i] = ans[i + 1];
                    continue;
                }
                else if (nums[i] > nums[i + 1])
                {
                    it = std::lower_bound(begin(vi) + ans[i + 1], end(vi), t2);
                }
                else
                {
                    it = std::lower_bound(begin(vi), end(vi) - (vi.size() - ans[i + 1]), t2);
                }
            }
            else
            {
                it = std::lower_bound(begin(vi), end(vi), t2);
            }
            ans[i] = distance(begin(vi), it);
            //if (it == end(vi))
            //    vi.emplace_back(t2);
            //else
                vi.insert(it, t2);
        }
        return ans;
    }

};

int main()
{

    LT lt;

    myvi v = { 5,2,6,1 };
    //myvi v = { -1,-1 };

    myvi v2 = lt.lta(v);

    showVectorInt(v2);

    return 0;
}
