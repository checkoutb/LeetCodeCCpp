
#include "../header/myheader.h"

class LT0890
{
public:

// D D
//    vector<string> findAndReplacePattern(vector<string> words, string p) {
//        vector<string> res;
//        for (string w : words) if (F(w) == F(p)) res.push_back(w);
//        return res;
//    }
//    string F(string w) {
//        unordered_map<char, int> m;
//        for (char c : w) if (!m.count(c)) m[c] = m.size();
//        for (int i = 0; i < w.length(); ++i) w[i] = 'a' + m[w[i]];
//        return w;
//    }


//Runtime: 8 ms, faster than 70.27% of C++ online submissions for Find and Replace Pattern.
//Memory Usage: 8.1 MB, less than 92.86% of C++ online submissions for Find and Replace Pattern.
    vector<string> lt0890a(vector<string>& words, string pattern)
    {
        int arr[125] = {0};
        for (char ch : pattern)
        {
            arr[ch] = 1;
        }
        int sum2 = accumulate(begin(arr), end(arr), 0);
        vector<string> ans;
        for (string w : words)
        {
            for (int i = 'A'; i <= 'z'; i++)
            {
                arr[i] = 0;
            }
            bool eq = true;
            int sum3 = 0;
            for (int i = 0; i < w.size(); i++)
            {
                char ch1 = w[i];
                char ch2 = pattern[i];
                if (ch1 != ch2)
                {
                    if (arr[ch1] == 0)
                    {
                        arr[ch1] = ch2;
                        sum3++;
                    }
                    if (arr[ch1] != ch2)
                    {
                        eq = false;
                        break;
                    }
                }
                else
                {
                    if (arr[ch1] == 0)
                    {
                        arr[ch1] = '1';
                        sum3++;
                    }
                }
            }

            if (eq && (sum2 == sum3))
                ans.push_back(w);
        }

        return ans;
    }

};

int main()
{

    vector<string> v = {"abc","deq","mee","aqq","dkd","ccc"};
    string p = "abb";

    LT0890 lt;

    vector<string> v2 = lt.lt0890a(v, p);

    for_each(begin(v2), end(v2), [](string& s){cout<<s<<endl;});

    return 0;
}
