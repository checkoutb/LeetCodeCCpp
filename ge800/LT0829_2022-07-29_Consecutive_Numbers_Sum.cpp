
#include "../header/myheader.h"

class LT0829
{
public:




    // ... D
    // ... ��Ϊ1�ĵȲ����С� �ĺ� ���� ����n��


/*



1: {1}
2: {2}
3: {1,2}  {3}
4: {4}
5: {2,3} {5}
6: {1,2,3}
7: {3,4}
8: {8}

... �ܱ��������� ���ж����ַ���������

9 �ܱ� 3���������� ��Ȼ��  a * ���� == 9

A �ܱ� Q ������ ��Ȼ�� Q * ���� == A == Q + Q + Q + ... + Q
== (Q-x1) + (Q-x2) + ... + Q + ... + (Q + x2) + (Q + x1)
== (Q-x1) + (Q-x2) + (Q-2) + (Q-1) + Q + (Q + 1) + (Q + 2) + .. Q+x2 + Q+x1


A = A * 1 = 1 + 1 +...+1  != (1-x1)...


A = A/2 + A/2+1     A����


4 �� ���� ��ż�� / ����Ҫ �õ� x.5     ������ A*2 �ܱ� ż�� ���� ��  �� A �޷��� ż������
A / ż�� == Z �� Z-0.5 + (Z+0.5)
  Z-1.5 + Z-0.5 + Z+0.5 + Z+1.5





*/
    int lt0829a(int n)
    {

    }

};

int main()
{

    LT0829 lt;


    return 0;
}