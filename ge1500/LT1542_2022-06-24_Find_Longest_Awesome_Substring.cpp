
#include "../header/myheader.h"

class LT1542
{
public:

    // D D

    // int arr[2^10]





    // ����Ҫ�ж� �������ȡ��� Ӧ���������Ĵ����µġ���Ӧ������� map2[flag] = i - 1 ���µġ���
//Runtime: 424 ms, faster than 28.29 % of C++ online submissions for Find Longest Awesome Substring.
//Memory Usage : 10.9 MB, less than 43.82 % of C++ online submissions for Find Longest Awesome Substring.
    // ����һ�� substring������ ����Ϊ������char�� ���� <= 1��
    // ���� tle��  ������ 10����ĸ��  ^ xor .   ��һ�γ��֡� ok��
    // ��ȫ�����һλ�� ������ ����
    int lt1542a(string s)
    {
        unordered_map<int, int> map2;
        int flag = 0;
        int ans = 1;
        map2[0] = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            flag ^= (1 << (s[i] - '0'));
            if (map2.find(flag) == map2.end())
            {
                map2[flag] = i;
            }
            else
            {
                ans = max(ans, i - map2[flag]);
            }

            for (int a = 0; a <= 9; ++a)
            {
                int t2 = flag ^ (1 << a);
                if (map2.find(t2) != map2.end())
                {
#ifdef __test
                    //cout << "2        " << i << ", " << t2 << ", " << map2[t2] << endl;
#endif
                    if ((i - map2[t2]) % 2 == 1)
                        ans = max(ans, i - map2[t2]);
                }
            }
        }
        return ans;
    }

};

int main()
{

    LT1542 lt;

    //string s = "3242415";

    //string s = "1234567";

    string s = "213123";

    cout << lt.lt1542a(s) << endl;

    return 0;
}
