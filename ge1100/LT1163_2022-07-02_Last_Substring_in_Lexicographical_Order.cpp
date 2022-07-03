
#include "../header/myheader.h"

class LT1163
{
public:

    // D D

    // hint4 : Use suffix array.

    //char maxi = s[0];
    //int maxIdx = 0;
    //for (int i = 1; i < s.length(); i++)
    //{
    //    if (s[i] > maxi)
    //    {
    //        maxi = s[i];
    //        maxIdx = i;
    //    }
    //    else if (s[i] == maxi)
    //    {
    //        int j = 1;
    //        while (s[i + j] == s[maxIdx + j] && maxIdx + j < i) j++;
    //        if (s[i + j] > s[maxIdx + j]) maxIdx = i;
    //        i = i + j - 1;
    //    }
    //}


    //The ultimate solution for this problem is to build a sufix arrayand the answer would be the last element of that array.That way, we can reach O(n log n) (or even O(n)) complexity.
    //I gambled - for the contest a suffix array would be too hard to implement, unless they want us to copy / paste some implementation from the internet.



    //int n = s.length(), i = 0, j = 1, k = 0;
    //while (j + k < n)
    //{
    //    if (s[i + k] == s[j + k]) k++;
    //    else if (s[i + k] < s[j + k]) i = max(i + k + 1, j), j = i + 1, k = 0;
    //    else j += k + 1, k = 0;
    //}
    //return s.substr(i);



//Runtime: 69 ms, faster than 50.32 % of C++ online submissions for Last Substring in Lexicographical Order.
//Memory Usage : 19.8 MB, less than 20.65 % of C++ online submissions for Last Substring in Lexicographical Order.
    // �Ǿ������������ ��һ�� �������� mxch
    string lt1163c(string s)
    {
        char mxch = *max_element(begin(s), end(s));
        string mxs = "A";
        int mxsi = -1;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == mxch)
            {
                int st = i;
                while (i < s.size() && s[i] == mxch)
                    i++;

                while (i < s.size() && s[i] != mxch)
                    i++;

                // now i is next not-continued mxch or s.size()

                string ss = s.substr(st, i - st + 1);       // +1? same? .���� no  "xxbbxxbx"

                if (ss > mxs)
                {
                    mxs = ss;
                    mxsi = st;
                }

                i--;

                //bool allmx = true;
                //while (allmx && i < s.size())
                //{
                //    if ()
                //}
            }
        }
        string ans = s.substr(mxsi);
        return ans;
    }


    // ȫa ��ʱ�� memory ը�ˡ���
    // ������ ���ǿ��Բ�ˢ�� lstmx����������
    // ������ǰ���� aaaaaa
    // ... ����������mxch���ǿ��Ե��ӵġ��� �������������mxch����ôҪȡ�������mxch�������û�У��� mxch֮�䡣������ mxs �ĳ�ʼֵ��
    //
    // hint1 : [i,j+1] > [i,j]
    // ���֮ǰ�� substr��  ���Խ�����ǵ�stringβ�ġ�
    // ���� mxch�� ���ԱȽϵ��� 2�� mxch֮��� substr���ĸ���� ����ֻ��Ҫ һ�顣
    string lt1163b(string s)
    {
        string mxs = "A";
        int mxsst = -1;
        int lstmx = -1;
        char mxch = *max_element(begin(s), end(s));

        //int ctnst = -1;
        //int ctnln = 0;

        //for (int i = 1; i < s.size(); ++i)
        //{

        //}



        for (int i = 0; i < s.size(); ++i)
        {
#ifdef __test
            cout << i << endl;
#endif
            if (s[i] == mxch)
            {
                if (lstmx == -1)
                {
                    lstmx = i;
                }
                else
                {
                    string ss = s.substr(lstmx, i - lstmx + 1);             // ������ asdazzasda
#ifdef __test
                    cout << ss << " ------" << endl;
#endif
                    if (ss > mxs)
                    {
                        mxs = ss;
                        mxsst = lstmx;
                    }
                    if (s[i] != s[i - 1])       // ������
                        lstmx = i;
                }
            }
        }

        string ss = s.substr(lstmx);
#ifdef __test
        cout << ss << ", " << mxs << endl;
#endif
        if (ss > mxs)
        {
            mxs = ss;
            mxsst = lstmx;
        }

        string ans = s.substr(mxsst);
        return ans;
    }




    // ����ababababab��
    // 25 / 30 .. 1���a�� 
    // ��û��һ���a�����ֲ��԰�����abababab������
    string lt1163a(string s)
    {
        //char mxch = *max_element(begin(s), end(s));
        char mxch = 'a', mnch = 'z';
        for (char ch : s)
        {
            mxch = max(mxch, ch);
            mnch = min(mnch, ch);
        }
        if (mxch == mnch)
            return s;

        vector<pair<int, int>> vp;              // start, last+1
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == mxch)
                vp.push_back(make_pair(i, i + 1));
        }
        while (vp.size() > 1)
        {
            vector<pair<int, int>> vp2;

            char mx = getcha1(s, vp[0].second);

            for (int i = 0; i < vp.size(); ++i)
            {
                char ch = getcha1(s, vp[i].second);
                if (ch == mx)
                {
                    vp2.push_back({ vp[i].first, vp[i].second + 1 });
                }
                else if (ch > mx)
                {
                    mx = ch;
                    vp2.clear();
                    vp2.push_back({ vp[i].first, vp[i].second + 1 });
                }
            }

            swap(vp, vp2);
        }
        string ans = s.substr(vp[0].first);
        return ans;
    }

    char getcha1(string& s, int idx)
    {
        if (idx >= s.size())
            return 'A';
        return s[idx];
    }

};

int main()
{

    LT1163 lt;

    //string s = "abab";
    //string s = "leetcode";
    //string s = "asdzzaaazxczzzvs";

    string s = "xxbbxxbx";

    cout << lt.lt1163c(s) << endl;

    return 0;
}
