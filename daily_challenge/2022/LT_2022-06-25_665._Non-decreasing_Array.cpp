
#include "../../header/myheader.h"

class LT
{
public:

    // D D



//Runtime: 32 ms, faster than 78.06 % of C++ online submissions for Non - decreasing Array.
//Memory Usage : 27 MB, less than 81.98 % of C++ online submissions for Non - decreasing Array.
    // <=    ����� a>b ���֣���a����b�� ��aΪ aǰ�� ��������У���ô��Ҫ��bΪa.
    // b �� aǰ �Ա� b>=aǰ�� a=aǰ�� else b=a;
    // ���ߣ�ǰ����2��������� or ����2��Ԫ��(��2��Ԫ��ǰ���б������) �Ͳ��С� bu,4,2,3���� 4>2, 3>2
    bool lta(vector<int>& nums)
    {
        nums.insert(begin(nums), INT_MIN);
        nums.push_back(INT_MAX);
        int sz1 = nums.size();
        bool chg = false;
        for (int i = 2; i < sz1; ++i)
        {
            if (nums[i - 1] > nums[i])
            {
                if (chg)
                    return false;
                chg = true;

                if (nums[i] >= nums[i - 2])
                {
                    ;
                }
                else
                {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return true;
    }

};

int main()
{

    LT lt;

    //myvi v = { 4,2,3 };

    myvi v = { 4,2,1 };

    cout << lt.lta(v) << endl;

    return 0;
}
