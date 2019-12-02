
#include "../header/myheader.h"

class LT0451
{
public:

// discuss && detial
// priority_queue
// vector<pair<int, int>>....&& . 先map，然后map的第二个作为pair的第一个。直接sort

// vector<string> bucket(s.size()+1, "");           // s.size() + 1
//        for(auto& it:freq) {
//            int n = it.second;
//            char c = it.first;
//            bucket[n].append(n, c);
//        }
// n是次数。所以次数越多，在bucket的位置越后。反序遍历。

//Runtime: 16 ms, faster than 75.57% of C++ online submissions for Sort Characters By Frequency.
//Memory Usage: 10.7 MB, less than 76.47% of C++ online submissions for Sort Characters By Frequency.

    // only a-z A-Z ?
    string lt0451a(string s)
    {
        int arr[256] = {0};
        for (char ch : s)
        {
            arr[ch]++;
        }
        int arr2[256] = {0};
        std::iota(begin(arr2) + 1, end(arr2), 1);

        #ifdef __test
//        for_each(begin(arr2), end(arr2), fun_cout);
        #endif // __test

                                    //   [&] ye keyi
        std:sort(begin(arr2), end(arr2), [arr](const int& a, const int& b) { return arr[a]>arr[b]; });

        #ifdef __test
//        for_each(begin(arr2), end(arr2), fun_cout);
        #endif // __test


        //Memory Limit Exceeded
//        string ans = "";
//        for (int i = 0; i < 256; i++)
//        {
//            int cnt = arr[arr2[i]];
//            if (cnt == 0)
//                break;
//            char ch = (char) (arr2[i]);
//            while (cnt-- > 0)
//                ans = ans + ch;
//        }


        char ans[s.length() + 1] = {};
        int t = 0;
        for (int i = 0; i < 256; i++)
        {
            int cnt = arr[arr2[i]];
            if (cnt == 0)
                break;
            char ch = (char) (arr2[i]);
            while (cnt-- > 0) {
                ans[t++] = ch;
            }
        }
        ans[t] = '\0';
//        string ans2(ans);
        return ans;
    }
};

int main()
{
    string s = "AAccaAAAccabb";

    LT0451 lt;
    string s2 = lt.lt0451a(s);
    cout<<endl<<s2<<endl;

    return 0;
}
