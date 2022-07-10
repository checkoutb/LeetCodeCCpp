
#include "../header/myheader.h"

class LT2338
{
public:

    // D

    // https://cp-algorithms.com/algebra/module-inverse.html


        //N = The number of ways to create a ideal array of length len2 from a strictly increasing ideal array of length len1
        //N = nChooseK(len2 - 1, len1 - 1)
        //There are len2 - 1 of potential places to put the bars
        //There are len1 - 1 bars to place


        //Just find number of sequences having all numbers unique such that a[i] is divisible by a[i - 1].
        //This count is conntained in tot array.Multiplying this count with the number of ways to expand this array into a N sized array.This ways is stored in dp[i][j] where i refers to number of unique elementsand j refers to size of the array.

        //Also the maximum length of sequence having a[i] divisible by a[i - 1] is just 14(1, 2, 4, 8, ...., 2 ^ 13).

        //For calculating dp[i][j]:-
        //Number of ways to fill j sized array with i unique elements is sum of number of ways to fill 1 to j - 1 sized array with i - 1 unique elements as we can add the remainig space with current element.


    // ����ôһ����ˣ�  ��Ҫ���� Ҫunique�� ��Ϊ  1,1,1,x,x �ĸ��� �Ǻ� 1,x,x ��һ���ģ����� ���Լ��ٺܶࡣ
    // ��չ�� ֱ�� ÿ��Ԫ�س���һ��ֵ����չ�ģ� ���� ������ 2^n �η���
    // Ϊ��unique������ ������ ȫ��Ԫ�س���ĳ��ֵ�� {1,2} -> {1,2}+{3,6}/{4,8}/{5,10} ... ����2���У� �������ô�޳��ģ�
    //      {1,5} -> {1,5}+{10,50} .   ���� ������ڣ����� �����ĵ�һ��Ԫ�� ������� ǰ��� ���һ��Ԫ�أ� Ȼ����� �ҵ� ������ ����ֱ�� ���һ��Ԫ��*2/3/4/5 �������죿       ���Լ����



    // tle

/*


1 1 1 1 1 1
1 1 1 1 1 2
1 1 1 1 1 3
...
1 1 1 1 1 10

1 1 1 1 2 2/4/6/8/10

1 1 1 1 3 3/6/9

1 1 1 1 4 4/8
1 1 1 1 5 5/10
1 1 1 1 6 6


1 1 1 2 2 2/4/6/8/10
1 1 1 2 4 4/8
1 1 1 2 6 6
1 1 1 2 8 8


[ֵ��Ϊ��һ��][����]
���� �ڴ��ը��  �����¡�  
���� map��Ӧ����ϡ��ģ����� top-down

��ӣ�����ǰ����ӣ���ô��ı� vvi��  ������Ӳ��У���֪�����һ��Ԫ���Ƕ��١�

����û�а취 top-down �� ��Ϊvvi�Ĳ������ս��  ���� �������� һά���飬����ը�ڴ档

����3��for������֪���ܲ��ܹ��� ��Ȼ�������Ӧ���� log(maxValue)? ���ǣ�Ӧ�� ��log �� �� n С�� 
2��for�ǣ�  v + v/2 + v/3 + v/4 + v/5 ... + 1 = ? �� 1+0.5+0.333+0.25+0.2+0.166+  ��� 2.?v��,�����϶����ڹ̶�ֵc��ʹ��ǰ��� �ӷ���ֵ < cv , ���� �������� for �� O(maxValue) ������ ����tle��
    �������Ļ��� ���ڲ���� С�� log(maxValue) ��


*/
    int lt2338a(int n, int maxValue)
    {
//        vector<vector<int>> vvi(maxValue + 1, vector<int>(n, -11));

        vector<int> vi(maxValue + 1, 1);

        const int MOD = 1e9 + 7;

        for (int i = 1; i < n; ++i)
        {
            vector<int> vi2(maxValue + 1, 0);

            for (int i = 1; i <= maxValue; ++i)
            {
                //for (int j = 1; i * j <= maxValue; ++j)
                for (int j = i; j <= maxValue; j += i)
                {
                    vi2[i] = (vi2[i] + vi[j]) % MOD;
                }
            }

            swap(vi, vi2);
        }
        
        int ans = 0;
        for (int i : vi)
        {
            ans = (ans + i) % MOD;
        }
        return ans;

    }

    //int dfsa1(int mxl, int len, int mxv, int v, vector<vector<int>>& vvi)
    //{
    //    if (vvi[len][v] > -11)
    //        return vvi[len][v];

    //}

};

int main()
{

    LT2338 lt;

    //myvi v = { 2,5 };

    myvi v = { 5,3 };

    cout << lt.lt2338a(v[0], v[1]) << endl;

    return 0;
}
