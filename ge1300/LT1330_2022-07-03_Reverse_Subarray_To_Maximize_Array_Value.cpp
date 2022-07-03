
#include "../header/myheader.h"

class LT1330
{
public:

    // D


    // ��������
    // Ҫôǰ��η�ת��Ҫô���η�ת��Ҫômax min��ת�� �õ��� 2*(max,min) ����

    // �������



    // a b c d e f ,,,,,  b-a c-b d-c e-d f-d       e-d,f-d,
    // a b e d c f ,,,,,  b-a e-b d-e c-d f-c       e-b,f-c
    // ���˽��紦��  for for
    // 2 3 1 5 4    2 5 1 3 4       2 3 5 1 4
    //  1 2 4 1      3 4 2 1         1 2 4 3
    // 1 2 3 4 5    
    // min-diff ?
    // 2 4 9 24 2 1 10   2 2 24 9 4 1 10  
    // 0 22 15 5 3 9  != 68
    // 
    // abs(a-b) = max(a-b,a+b,-a-b,-a+b)
    // ����ȷ����a����Ȼ�Ǻ� max/min ���ܻ��abs��� ���� subarr ��ĳ�� ��Ȼ�� max��min��
    // 2 4 24 9 2 1 10
    //  2 20 15 7 1 9  22 22 10... no
    // 
    int lt1330a(vector<int>& nums)
    {
        int sz1 = nums.size();
        int sum2 = 0;
        for (int i = 1; i < sz1; ++i)
        {
            sum2 += abs(nums[i] - nums[i - 1]);
        }
        int ans = 0;
        for (int i = 0; i < sz1; ++i)           // aaaa[i,j]aaa
        {
            for (int j = i + 1; j < sz1; ++j)
            {
                int t2 = sum2 - (i == 0 ? 0 : abs(nums[i] - nums[i - 1])) - (j == (sz1 - 1) ? 0 : abs(nums[j + 1] - nums[j]))
                    + (i == 0 ? 0 : abs(nums[j] - nums[i - 1])) + (j == (sz1 - 1) ? 0 : abs(nums[j + 1] - nums[i]));
#ifdef __test
                cout << i << ", " << j << " - - " << t2 << ", " << ans << endl;
#endif
                ans = max(ans, t2);
            }
        }
        return ans;
    }

};

int main()
{

    LT1330 lt;

    //myvi v = { 2,3,1,5,4 };

    myvi v = { 2,4,9,24,2,1,10 };       // 2 4 9 2 24 1 10  .. . ��max �� min ��һ��  ���� ������ ������С�����ʹ�С�� �δ����С���δ�ʹ�С
                        // ���-��С �� ���diff�� ����ô����Ҳ�����ܱ����diff ���� ���� ���-��С+0-0 �� �� �δ�-��С+���-��С�� ��֪��˭���ġ�
                            // ������Ҫ ���԰��� ���ٴΣ� ʲô����������

    cout << lt.lt1330a(v) << endl;

    return 0;
}
