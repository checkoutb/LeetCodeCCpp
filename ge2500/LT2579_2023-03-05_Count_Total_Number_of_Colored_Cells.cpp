
#include "../header/myheader.h"

class LT2579
{
public:

    // D D

    // lee215 �� cut and combine ���㡣�� ��ȫû�п��ǹ����֡�
    // ���� n=3 ��ʱ�� ���� �и���� ��  һ�� 3*3 �� һ�� 2*2
    //                      ���� 2�� 2*3�� һ�� 1*1



    //Runtime3 ms
    //    Beats
    //    66.67 %
    //    Memory6 MB
    //    Beats
    //    66.67 %
    // 1 3 5 3 1
    long long lt2579a(int n)
    {
        return 1LL * (2 * n - 1 + 1) / 2 * (n) * 2 - (2 * n - 1);
    }

};

int main()
{

    LT2579 lt;


    return 0;
}
