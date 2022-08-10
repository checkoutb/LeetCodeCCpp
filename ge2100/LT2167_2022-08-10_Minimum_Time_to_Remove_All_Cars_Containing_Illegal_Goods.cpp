
#include "../header/myheader.h"

class LT2167
{
public:

    // D D

    //int pre = 0, ans = 1e9;
    //for (int i = 0; i < s.size(); ++i) {
    //    if (s[i] == '1') {
    //        ans = min(ans, pre + (int)s.size() - i);
    //        pre = min(pre + 2, i + 1);
    //    }
    //}
    //return min(ans, pre);

    //for (int i = 0; i < n; i++) {
    //    left = min(left + 2 * (s[i] - '0'), i + 1);
    //    res = min(res, left + n - i - 1);
    //}
    // ������ok�������ǣ� left �� ���pop + �м��Ƴ� �ġ�  ʣ�µľ��� �Ҳ�pop �� n-i-1.


//Runtime: 328 ms, faster than 32.56 % of C++ online submissions for Minimum Time to Remove All Cars Containing Illegal Goods.
//Memory Usage : 75.9 MB, less than 51.04 % of C++ online submissions for Minimum Time to Remove All Cars Containing Illegal Goods.
    // 1-�Ƿ���
    int lt2167a(string s)
    {
        int sz1 = s.size();
        vector<int> vi(sz1);
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] == '1')
            {
                vi[i] = min((i + 1), 2 + (i == 0 ? 123 : vi[i - 1]));
            }
            else
            {
                vi[i] = i == 0 ? 0 : vi[i - 1];
            }
        }

        vector<int> vi2(sz1);
        for (int i = sz1 - 1; i >= 0; --i)
        {
            if (s[i] == '1')
            {
                vi2[i] = min((sz1 - i), 2 + ((i == sz1 - 1) ? 123 : vi2[i + 1]));
            }
            else
            {
                vi2[i] = (i == sz1 - 1) ? 0 : vi2[i + 1];
            }
        }

        //int ans = INT_MAX;
        int ans = vi2[0];               // ...���Ӧ���� min(vi[sz1-1],vi2[0]) ... ����ͨ���ˡ��� 00001 Ӧ�ù����ˡ� ��������û�����⡣ ��Ϊ2�࣬��Ȼ�� ֱ�� pop ���ġ�
        for (int i = 1; i < sz1; ++i)
        {
            ans = min(ans, vi[i - 1] + vi2[i]);
        }
        //return ans == INT_MAX ? 0 : ans;          // ..       // ..
        return ans;
    }

};

int main()
{

    LT2167 lt;

    //string s = "1100101";
    string s = "0010";

    cout << lt.lt2167a(s) << endl;

    return 0;
}
