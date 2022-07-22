
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    // ֱ��forѭ�� words��Ȼ�� �� s[index of last char (in word) : -1]�� �������� ��һ���ַ���λ�á�

    // Ԥ�Ƚ�s���±� ���� char ���飬 Ȼ�� for words�� upper_bound(c-'a'.begin, c-'a'.end, lstIdx) �����ַ�λ�á�

    // ��words�����ַ����飬 for s {���ַ���Ӧ������word clear��Ȼ�� �޳����ַ���Ȼ�� �ŵ� �µ����ַ����ڵ�����}
    //   �Զ���Node���ͣ� ���� word �� index�� �������޳����ַ��Ĳ�����


//https://leetcode.com/problems/number-of-matching-subsequences/discuss/117634/Efficient-and-simple-go-through-words-in-parallel-with-explanation
    //vector<const char*> waiting[128];
    //for (auto& w : words)
    //    waiting[w[0]].push_back(w.c_str());
    //for (char c : S) {
    //    auto advance = waiting[c];
    //    waiting[c].clear();
    //    for (auto it : advance)
    //        waiting[*++it].push_back(it);
    //}
    //return waiting[0].size();

    //vector<pair<int, int>> waiting[128];
    //for (int i = 0; i < words.size(); i++)
    //    waiting[words[i][0]].emplace_back(i, 1);
    //for (char c : S) {
    //    auto advance = waiting[c];
    //    waiting[c].clear();
    //    for (auto it : advance)
    //        waiting[words[it.first][it.second++]].push_back(it);
    //}
    //return waiting[0].size();

    //import java.text.StringCharacterIterator;
    //List<StringCharacterIterator>[] waiting = new List[128];
    //for (int c = 0; c <= 'z'; c++)
    //    waiting[c] = new ArrayList();
    //for (String w : words)
    //    waiting[w.charAt(0)].add(new StringCharacterIterator(w));
    //for (char c : S.toCharArray()) {
    //    List<StringCharacterIterator> advance = waiting[c];
    //    waiting[c] = new ArrayList();
    //    for (StringCharacterIterator it : advance)
    //        waiting[it.next() % it.DONE].add(it);
    //}
    //return waiting[0].size();



    // ������
//Runtime: 1321 ms, faster than 7.66 % of C++ online submissions for Number of Matching Subsequences.
//Memory Usage : 387.3 MB, less than 5.20 % of C++ online submissions for Number of Matching Subsequences.
    int lta(string s, vector<string>& words)
    {
        int sz1 = s.size();
        vector<vector<int>> nxt(sz1, vector<int>(26, -1));          // ����ǣ�����һ����������⡣

        vector<int> vi(26, -1);

        for (int i = sz1 - 1; i >= 0; --i)
        {
            for (int j = 0; j < 26; ++j)
            {
                nxt[i][j] = vi[j];
            }
            vi[s[i] - 'a'] = i;
        }

#ifdef __test
        showVectorInt(vi);
        cout << " ------------ " << endl;
        for (int i = 0; i < nxt.size(); ++i)
        {
            for (int j = 0; j < nxt[0].size(); ++j)
            {
                cout << nxt[i][j] << ", ";
            }
            cout << endl;
        }
#endif

        int ans = 0;
        for (string& wd : words)
        {
            int t2 = 0;
            for (int i = 0; i < wd.size(); ++i)
            {
                t2 = i == 0 ? vi[wd[0] - 'a'] : nxt[t2][wd[i] - 'a'];
                if (t2 == -1)
                {
#ifdef __test
                    cout << wd << ",goto " << i << endl;
#endif
                    goto AAA;
                }
            }
            ans++;

            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{

    LT lt;

    //string s = "abcde";
    //vector<string> vs = { "a","bb","acd","ace" };

    string s = "dsahjpjauf";
    vector<string> vs = { "ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax" };


    cout << lt.lta(s, vs) << endl;

    return 0;
}
