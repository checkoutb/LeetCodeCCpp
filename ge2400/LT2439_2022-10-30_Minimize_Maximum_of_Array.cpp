
#include "../header/myheader.h"

class LT2439
{
public:

    // D D


    //long long sum = 0;
    //int ans = 0;
    //for (int i = 0; i < nums.size(); i++) {
    //    sum += nums[i];
    //    ans = fmax(ans, (sum + i) / (i + 1));
    //}
    //return ans;


    // The best we can do is to reduce nums[i] to the average of array nums[0, i].



    // Sorry forget to explain (a + i) / (i + 1), I used integer division to calculate ceil(double(sum) / (i + 1))




    // [1, n)  & >0�� [i]-1,   [i-1]+1
    // min max
    // ���� ��ֵ ������ǰ�ߣ� ���������� ���� Ҫ min max�� ��ô ���� 
    //      �Ӻ���ǰ�� ��� ��ǰ ���� ƽ��ֵ����ô--���ŵ�ǰ��ȥ��
    //      С��ƽ��ֵ���������� ���� ���� ��ǰ С���� ƽ��ֵ�� �ᵼ�� ƽ��ֵ ������
    //          �� ����϶�С�ڵ���ƽ��ֵ����������ν��
    int lt2439a(vector<int>& nums2)
    {
        int sz1 = nums2.size();

        vector<long long> nums(sz1);

        for (int i = 0; i < sz1; ++i)
        {
            nums[i] = nums2[i];
        }

        long long sum2 = 0LL;
        for (int i : nums)
            sum2 += i;

        int avg = sum2 / sz1;
        if (sum2 % sz1)
            ++avg;
        
        long long ans = 0LL;
        for (int i = sz1 - 1; i > 0; --i)
        {
            if (nums[i] > avg)
            {
                nums[i - 1] += nums[i] - avg;           // > INT_MAX ...
                nums[i] = avg;
                sum2 -= nums[i];
            }
            else
            {
                sum2 -= nums[i];
                avg = (sum2 / i) + ((sum2 % i) ? 1 : 0);

            }
            avg = max(0, avg);
            sum2 = max(0LL, sum2);
            ans = max(ans, nums[i]);
        }
        ans = max(ans, nums[0]);
        return ans;
    }

};

int main()
{

    LT2439 lt;

    //myvi v = { 3,7,1,6 };
    myvi v = { 10,1 };

    cout << lt.lt2439a(v) << endl;

    return 0;
}
