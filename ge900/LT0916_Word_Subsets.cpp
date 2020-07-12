
#include "../header/myheader.h"

class LT0916
{
public:


// D
// a要包含每个b，所以只需要找到 B中每个 lowercase的 最大次数。 然后 a 中char的次数 和 B最大次数比较。



// tle
    vector<string> lt0916a(vector<string>& A, vector<string>& B)
    {
        std::sort(begin(B), end(B), [](string& s1, string& s2){ return s1.size() > s2.size();});
        #ifdef __test
        for_each(begin(B), end(B), fun_cout_s); cout<<endl;
        #endif // __test

        vector<vector<int>> vv(B.size(), vector<int>(26, 0));

        for (int i = 0; i < B.size(); i++)
        {
            string sb = B[i];
            for (char& ch : sb)
            {
                vv[i][ch - 'a']++;
            }
        }

        vector<string> ans;
        int arr[26] = {0};
        for (string& s : A)
        {
            std::fill(begin(arr), end(arr), 0);
            for (char& ch : s)
            {
                arr[ch - 'a']++;
            }
            bool can = true;
            for (vector<int>& v : vv)
            {
                for (int i = 0; i < 26; i++)
                {
                    if (arr[i] < v[i])
                    {
                        can = false;
                        goto AAA;
                    }
                }
            }
            AAA:
            if (can)
            {
                ans.push_back(s);
            }
        }
        return ans;
    }

};

int main()
{

    vector<string> a = {"amazon","apple","facebook","google","leetcode"};
    vector<string> b = {"ec","oc","ceo"};

    LT0916 lt;

    vector<string> ans = lt.lt0916a(a, b);

    for_each(begin(ans), end(ans), fun_cout_s);
    cout<<endl;

    return 0;
}
