
#include "../header/myheader.h"

class LT2541
{
public:

    // D

    // If n1[i] < n2[i], we need to increase it using n2[i] - n1[i]) / k operations. 
    //
    // ... ��/�����ˣ������ һ�β��� ���� add k*N�� ���һ�β��� ֻ�� add k��

    // �� 30% ͨ������ɵ�ˡ�����


    // g


    // ��ôƥ�䣿
    // 3 -3 �ǿ϶��ġ�
    // 6 [4,3,3,1,1].  �� [3,3] ����[4,1,1] �� ��������ν��
    // [3 3 6] [4 3 3 1 1]  3-3, 3-3, 6-4 1 1    5op
    //      6-3 3, 3-4, 3-1 1 1     6op
    // [2 2 2 6] [4 3 3 1 1]  2-1 1, 2-4, 2-4, 6-3 3   6
    //      2-3,2-3,2-1 1, 6-4 1 1      7
    long long lt2541a(vector<int>& nums1, vector<int>& nums2, int k)
    {
        long long ans = 0;
        int sz1 = nums1.size();

        vector<int> vi(sz1);
        long long t2 = 0LL;
        for (int i = 0; i < sz1; ++i)
        {
            if ((nums2[i] - nums1[i]) % k != 0)
                return -1LL;
            vi[i] = (nums2[i] - nums1[i]) / k;
            t2 += vi[i];
        }
        if (t2 != 0LL)
            return -1LL;



    }

};

int main()
{

    LT2541 lt;


    return 0;
}
