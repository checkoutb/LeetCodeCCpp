
#include "../header/myheader.h"

class LT1585
{
public:

    // D

    // ǰ�治���б��Լ�С�ġ�

    //vector<vector<int>> idx(10);
    //vector<int> pos(10);
    //for (int i = 0; i < s.size(); ++i)
    //    idx[s[i] - '0'].push_back(i);
    //for (auto ch : t) {
    //    int d = ch - '0';
    //    if (pos[d] >= idx[d].size())
    //        return false;
    //    for (auto i = 0; i < d; ++i)
    //        if (pos[i] < idx[i].size() && idx[i][pos[i]] < idx[d][pos[d]])
    //            return false;
    //    ++pos[d];
    //}
    // ��������6


    // tle  134/138


    // ����Ҫ���䡣����ֱ���ң��ҵ� ����취�ƶ�����������������Ļ��� ��������һ�� ���� t[i]��ֻ��Ҫ�ƶ� [idx]֮ǰ�ġ�
    bool lt1585d(string s, string t)
    {
        int sz1 = s.size();
        for (int i = 0; i < sz1; ++i)
        {
#ifdef __test
            cout << s << ", " << t << " -=-- " << i << endl;
#endif
            if (s[i] != t[i])
            {
                if (s[i] < t[i])
                    return false;
                for (int j = i + 1; j < sz1; ++j)
                {
                    if (s[j] == t[i])
                    {
                        for (int k = j; k > i; --k)
                        {
                            s[k] = s[k - 1];
                        }
                        s[i] = t[i];
                        goto AAA;
                    }
                    else if (s[j] < t[i])
                    {
                        return false;
                    }
                }
                return false;
                AAA:
                continue;
            }
        }
        return true;
    }


    // 136/138   "99...999888...88777...77...5..44..33...22...1.." "111...22...333...44...5...66...7...88...9.."   excepted: true
    // ����hint�����������ְ������������ԡ�����
    bool lt1585c(string s, string t)
    {
        int sz1 = s.size();

        for (int i = 0; i < sz1; ++i)
        {
#ifdef __test
            cout << i << endl;
            cout << " -   " << s << " - " << t << endl;
#endif
            if (s[i] != t[i])
            {
                int arr[10] = { 0 };
                int diff = 0;
                int idx = -1;
                for (int j = i; j < sz1; ++j)
                {
                    int sj = s[j] - '0';
                    int tj = t[j] - '0';
                    arr[sj]++;
                    arr[tj]--;

                    if (sj < (t[i] - '0') && (idx == -1))            // ... ����ֱ��sort������ ��С�ڵ� Ҳ����ν��... ���ǡ���  ���� �ڿ����� �� t[i] С�ģ����� ����� С��t[i] �� ǰ�棬������һ�� t[i]
                        return false;

                    if (s[j] == t[i] && idx == -1)
                        idx = j;

                    for (int a = 0; a < 10; ++a)
                    {
                        if (arr[a] != 0)
                        {
                            goto AAA;
                        }
                    }
                    s[idx] = s[j];
                    for (int k = j; k > i; k--)
                    {
                        s[k] = s[k - 1];
                    }
                    s[i] = t[i];
                    goto BBB;

                    AAA:
                    continue;
                }
                return false;
                BBB:
                continue;
            }
        }

        return true;
    }


    // gg

    // error

    // Ӧ���� �ҵ�һ��ǰ׺������ ����char���� ��ȡ�  Ȼ���� ������� char  һ��һ����ǰ�ơ� �Ͼ� һ��һ���Ļ������л��ᣬһ��sort���Ͷ����ˡ�
    // �������� ��ƥ�䣬�����char��ʼ������ң�ֱ�� һ�� ���䣬 s��t ����������е� ����char ��������ȣ� �Ұ��� �����char��
    //          �� �����ڲ����� �� �����char С�ģ�  Ȼ�� �� �����char �ŵ���һλ������������һλ��

    // ���� �о� �϶� tle ������ ���ԣ�tle Ӯһ��
    // ��û�� һ�����䲻�У����� �����������Եģ�
    bool lt1585b(string s, string t)
    {
        int sz1 = s.size();

        for (int i = 0; i < sz1; ++i)
        {
#ifdef __test
            cout << i << endl;
            cout << " -   " << s << " - " << t << endl;
#endif
            if (s[i] != t[i])
            {
                int arr[10] = { 0 };
                int diff = 0;
                int idx = 0;
                for (int j = i; j < sz1; ++j)
                {
                    int sj = s[j] - '0';
                    int tj = t[j] - '0';
                    arr[sj]++;
                    arr[tj]--;

                    if (sj < (t[i] - '0'))
                        return false;

                    if (s[j] == t[i])
                        idx = j;

                    for (int a = 0; a < 10; ++a)
                    {
                        if (arr[a] != 0)
                        {
                            goto AAA;
                        }
                    }
                    s[idx] = s[j];
                    for (int k = j; k > i; k--)
                    {
                        s[k] = s[k - 1];
                    }
                    s[i] = t[i];
                    goto BBB;

                    AAA:
                    continue;
                }
                return false;
                BBB:
                continue;
            }
        }

        return true;
    }



    // ...error ...  ��ͷ��ʼ ���еġ�
    // ��ƥ��ʱ���ӵ�ǰλ�ã��� ƥ���char ��λ�ã� ��� substring �У�ƥ���char �ǲ��� ��С�ġ�
    // �е��ʱ�䰡��tle�� �������� sliding window ? �Եģ���Ϊ�� sort������ ���� ����Ҫ��С�ġ�
    bool lt1585a(string s, string t)
    {
        priority_queue<char, vector<char>, std::greater<char>> priq;
        int idx = 0;
        for (int i = 0; i < s.size(); ++i)
        {
#ifdef __test
            cout << i << endl;
#endif
            if (priq.empty())
            {
                if (s[i] != t[i])
                {
                    int tar = t[i];
                    idx = i;
                    while (idx < s.size())
                    {
                        priq.push(s[idx]);
                        if (s[idx++] == t[i])
                        {
                            break;
                        }
                    }
                    if (priq.top() != t[i])
                        return false;
                    priq.pop();
                }
            }
            else
            {
                int t2 = priq.top();
                
                if (t2 != t[i])
                {
                    while (idx < s.size())
                    {
                        priq.push(s[idx]);
                        if (s[idx++] == t[i])
                        {
                            break;
                        }
                    }
                    if (priq.top() != t[i])
                        return false;
                    priq.pop();
                }
                else
                {
                    priq.pop();
                }
            }

            //if (s[i] != t[i])
            //{
            //    
            //}
        }
        return true;
    }

};

int main()
{

    LT1585 lt;

    //string s = "84532", t = "34852";

//    string s = "34521", t = "23415";

    //string s = "12345", t = "12435";


    string s = "999888777666555444333222111000";
    string t = "111222333444555666000777888999";


    // error C2026: �ַ���̫���ѽض�β���ַ�
    //cout << s.size() << endl;

    cout << lt.lt1585d(s, t) << endl;

    return 0;
}
