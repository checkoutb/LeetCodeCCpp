
#include "../../header/myheader.h"

class LT
{
public:


    // D D

    // ����ǰ���������Ԫ���Ƿ�������á�
    // �����ڼ����Լ���ʱ��45�ȣ�90�ȣ�135�ȣ��鿴�Ϸ��Ƿ���Q��
    // ��������ֻ�޸�һ��ֵ���ع�Ҳֻ��Ҫ�ع�һ��ֵ��




    // ��������int����bool������Ҫcopy��& vvi��  1<<row
    // ������ĳ��ȫ��false/��0������ǰ�˳���
//Runtime: 134 ms, faster than 5.06 % of C++ online submissions for N - Queens.
//Memory Usage : 39.7 MB, less than 17.58 % of C++ online submissions for N - Queens.
    vector<vector<string>> ltb(int n)
    {
        vector<vector<bool>> vvb(n, vector<bool>(n, true));
        vector<vector<string>> ans;
        vector<int> vi;
        dfsb1(vvb, n, vi, ans);
        return ans;
    }

    void dfsb1(vector<vector<bool>> vvb, int n, vector<int>& vi, vector<vector<string>>& ans)
    {
        if (vi.size() == n)
        {
            vector<string> vs;
            for (int i = 0; i < n; ++i)
            {
                string s(n, '.');
                s[vi[i]] = 'Q';
                vs.push_back(s);
            }
            ans.push_back(vs);
            return;
        }
        int row = vi.size();
        for (int i = 0; i < n; ++i)
        {
            if (vvb[row][i])
            {
                vector<vector<bool>> v(begin(vvb), end(vvb));

                //std::copy(begin(vvb), end(vvb), std::back_inserter(v));
#ifdef __test
                cout << &v[0] << ", " << &vvb[0] << endl;     // 2�ֶ��ǲ�ͬ��ַ�� ����150ms���ҡ���copy���ڴ����Ĵ�30% (27mb vs 39mb)��
#endif
                for (int j = row + 1; j < n; ++j)
                {
                    v[j][i] = false;
                }
                int ii{ row }, jj{ i };
                while (ii < n && jj >= 0)
                {
                    v[ii++][jj--] = false;
                }
                ii = row, jj = i;
                while (ii < n && jj < n)
                {
                    v[ii++][jj++] = false;
                }
                vi.push_back(i);
                dfsb1(v, n, vi, ans);
                vi.pop_back();
            }
        }
    }


    // ��������
    //vector<vector<string>> lta(int n)
    //{
    //    std::bitset<9> bs;      // can set?
    //    bs.set();       // or flip
    //    vector<vector<string>> ans;
    //    vector<int> vi;

    //}

    //void dfsa1(bitset<9> bs, vector<int>& vi, vector<vector<int>>& ans, int n)
    //{
    //    if (vi.size() == n)
    //    {
    //        vector<string> vs;
    //        for (int i = 0; i < n; ++i)
    //        {
    //            string s(n, '.');
    //            s[vi[i]] = 'Q';
    //            vs.push_back(s);
    //        }
    //        ans.push_back(vs);
    //        return;
    //    }

    //    for (int i = 0; i < n; ++i)
    //    {
    //        if (bs[i])
    //        {

    //        }
    //    }
    //}

};

int main()
{

    LT lt;

    int n = 4;

    vector<vector<string>> ans = lt.ltb(n);

    for_each(begin(ans), end(ans), [](vector<string>& vs) {
        for_each(begin(vs), end(vs), [](string& s) {
            cout << s << endl;
        });
        cout << endl << endl;
    });

    return 0;
}
