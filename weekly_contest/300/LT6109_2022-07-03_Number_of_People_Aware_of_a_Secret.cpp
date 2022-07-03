
#include "../../header/myheader.h"

class LT6109
{
public:




    // vi ������� ������ ���� ���ܹ� ������ȥ��
    // 

    //   1  2  3  4  5  6   day
    //show vector<int> :
    //0, 1, 0, 1, 1, 0, 0,          // ��һ���ʱ��ֻ��һ����֪��������delay��forget�� ������3��4����
    //    show vector<int> :
    //0, 1, 0, 1, 1, 0, 0,          // �ڶ��죬 ����ֻ��һ����֪���� ���� û������
    //    show vector<int> :
    //0, 1, 0, 1, 1, 1, 1,          // ������   ����һ�ˣ�������2����֪�������� ���������˻��� 5.6����
    //    show vector<int> :
    //0, 1, 0, 1, 1, 1, 2,          // 4�� ����һ�ˣ� ��3����֪���� ���ҽ����������˻��� 6����
    //    show vector<int> :
    //0, 1, 0, 1, 1, 1, 2,          // 5�� ����һ�ˣ�����һ�ˣ� ���� 3��֪���� ���ҽ����������� ���ᴫ���ˡ�
    //    show vector<int> :
    //0, 1, 0, 1, 1, 1, 2,          // 6�� ����2�ˣ�û���������� ���� 5���ˡ�
    //    5

    // �������ڣ�Ϊʲô �� �ۼ� ���� forget ��ֵ��  Ҳ�� ans��

    // Ӧ���� vi ���� [i]���쿪ʼ�ǵ� -  [i] ���쿪ʼ����   ���� ��  Ȼ�� һ��int ���� [i] ����� ��������
    // ���Եģ� ��Ϊ����������� ����� ���� û���������ܵ��ˣ�  ��Ϊ ���� ������������2���ˣ� �����ڵ�6���ǲ�֪�����ܵģ���8��Ż�ǵá�
    // �о������ĿҪ�����ˡ���

    // ������ share�� ���Ǽǵá��� ���� �������� ��֪���ģ�ֻ���� ��share��

    // �������� forget ��ֵ ��û������ģ� forget֮ǰ��ֵ �����Ѿ������ˡ�

    // �ԶԶԣ����� û�����⡣  ���� ���ǵ����ܵ��� ���� ��� forget�� �� �� share���ˡ�





    // AC ��������++���е�� �ˡ�����  ��֪��Ϊʲô�ԡ�����
    // fibonacci
    // ���������첻��share .. delay��ǰ �� forget��Ϊֹ��
    // ����һ�� sliding window?
    // �������㣬���� ����ǰ��  ���� ������� ��ɢ�� ��Щ�졣
    // ....no
    int lta(int n, int delay, int forget)
    {

        vector<int> vi(n + 1);
        vi[1] = 1;
        const int MOD = 1e9 + 7;
        
        int t2 = 0;

        for (int i = 1; i <= n; ++i)
        {
            int st = i + delay;
            int en = i + forget - 1;
            //st = min(st, n);
            
            en = min(en, n);

            int t2 = vi[1];

            for (int j = st; j <= en; ++j)
            {
                vi[j] = (vi[i] + vi[j]) % MOD;
            }
#ifdef __test
        showVectorInt(vi);
#endif
        }

        int ans = 0;

        for (int i = 0; i < forget; ++i)
        {
            ans = (ans + vi[n - i]) % MOD;
        }

        return ans;


//        vector<int> vi(n + 1);
//        vi[1] = 1;
//        const int MOD = 1e9 + 7;
//        int ans = 0;
//        for (int i = 1; i <= n; ++i)
//        {
//            int st = i + delay;
//            int en = i + forget;
//            st = min(st, n);
//            en = min(en, n);
//
//            for (int j = st; j < en; ++j)
//            {
//                vi[j] = (vi[i] + vi[j]) % MOD;
//            }
//        }
//
//#ifdef __test
//        showVectorInt(vi);
//#endif
//
//        return vi[n];


        //vector<int> vi(n + 1);
        //vi[1] = 1;

        //for (int i = 2; i <= n; ++i)
        //{

        //}
        //return vi[n];
    }

};

int main()
{

    LT6109 lt;

    myvi v = { 6,2,4 };
    //myvi v = { 4,1,3 };

    cout << lt.lta(v[0], v[1], v[2]) << endl;

    return 0;
}
