
#include "../header/myheader.h"

class LT1585
{
public:

    // D
    // .... ��û���ƶ��� ֻ�ǣ� �ж��� �´γ��� �� �����±� �� ��û�� �� ����Ҫ�� С�ġ�


    // g

    // hint : swap ������ sort��
    // ���� sort �� ���ƻ� vvi��
    // ���� vvi �� tle��
    bool lt1585b(string s, string t)
    {
        int sz1 = s.size(), sz2 = t.size();

        vector<vector<int>> vvi(10, vector<int>());

        for (int i = 0; i < sz1; ++i)
        {
            vvi[s[i] - '0'].push_back(i);
        }

        int arr[10] = { 0 };
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] != t[i])
            {
                t2 = t[i] - '0';
                while (arr[t2] < vvi[t2].size() && vvi[t2][arr[t2]] <= i)
                {
                    ++arr[t2];
                }
                if (arr[t2] == vvi[t2].size())
                    return false;



                //sort(begin(s) + i, begin(s) + vvi[t2][arr[t2]] + 1);
                ++arr[t2];
            }
        }
        return true;
    }


    // .......
    // ��Ҫһ��2�� ���������ҵ������2�� Ȼ�� ��� substr  sort��  ��� �м���1�� ��ô return false��
    bool lt1585a(string s, string t)
    {
        int sz1 = s.size(), sz2 = t.size();
        
        vector<vector<int>> vvi(10, vector<int>());

        for (int i = 0; i < sz1; ++i)
        {
            vvi[s[i] - '0'].push_back(i);
        }

        int arr[10] = { 0 };
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] != t[i])
            {
                t2 = t[i] - '0';
                while (arr[t2] < vvi[t2].size() && vvi[t2][arr[t2]] <= i)
                {
                    ++arr[t2];
                }
                if (arr[t2] == vvi[t2].size())
                    return false;

                sort(begin(s) + i, begin(s) + vvi[t2][arr[t2]] + 1);
                ++arr[t2];
            }
        }
        return true;
    }

};

int main()
{

    LT1585 lt;

    string s = "84532";
    string t = "34852";

    cout << lt.lt1585a(s, t) << endl;

    return 0;
}
