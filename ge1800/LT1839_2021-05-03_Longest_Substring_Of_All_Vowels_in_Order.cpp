
#include "../header/myheader.h"

class LT1839
{
public:

// D D

//    for (int i = 0, j = 0; i < w.size(); ++i) {
//        if (w[i] == 'a') {
//            int cnt = 0;
//            for (j = i + 1; j < w.size() && w[j - 1] <= w[j]; ++j)
//                cnt += w[j - 1] < w[j];
//            if (cnt == 4)
//                res = max(res, j - i);
//            i = j - 1;
//        }
//    }



//So this problem is to find the length of the longest non-decreasing substring that has five different chars.
//        for (int i = 1; i != n; ++i) {
//            if (word[i - 1] == word[i]) {
//                ++len;
//            } else if (word[i - 1] < word[i]) {
//                ++len;
//                ++cnt;
//            } else {
//                cnt = 1;
//                len = 1;
//            }
//
//            if (cnt == 5) {
//                max_len = max(max_len, len);
//            }
//        }


//Runtime: 100 ms, faster than 76.92% of C++ online submissions for Longest Substring Of All Vowels in Order.
//Memory Usage: 26.7 MB, less than 69.18% of C++ online submissions for Longest Substring Of All Vowels in Order.
    int lt1839a(string word)
    {
        int ans = 0;
//        int t2 = word[0] == 'a';
        int st = INT_MAX >> 1;
        char nxt = 'a';
//        word.push_back('a');
        for (int i = 0; i < word.size(); ++i)
        {
            switch(word[i])
            {
            case 'a':
                if (nxt != 'e')
                {
                    st = i;
                    nxt = 'e';
                }
//                if (nxt == 'a')
//                {
////                cout<<"."<<i<<endl;
////                    ans = max(ans, i - st);
//                    st = i;
//                    nxt = 'e';
//                }
//                else if (nxt != 'e')
//                {
//                    st = INT_MAX >> 1;
//                    nxt = 'a';
//                }
                break;
            case 'e':
                if (nxt == 'e' || nxt == 'i')
                {
                    nxt = 'i';
                }
                else
                {
                    st = INT_MAX >> 1;
                    nxt = 'a';
                }
                break;
            case 'i':
                if (nxt == 'i' || nxt == 'o')
                {
                    nxt = 'o';
                }
                else
                {
                    st = INT_MAX >> 1;
                    nxt = 'a';
                }
                break;
            case 'o':
                if (nxt == 'o' || nxt == 'u')
                {
                    nxt = 'u';
                }
                else
                {
                    st = INT_MAX >> 1;
                    nxt = 'a';
                }
                break;
            case 'u':
                if (nxt == 'u' || nxt == 'a')
                {
                    ans = max(ans, i - st + 1);
                    nxt = 'a';
                }
                else
                {
                    st = INT_MAX >> 1;
                    nxt = 'a';
                }
                break;
            }
//            if (word[i] == 'a')
//            {
//                if (i == 0 || word[i] != 'a')
//                    st = i;
//            }
//            else
        }
        return ans;
    }

};

int main()
{
    string s{"aeiaaioaaaaeiiiiouuuooaauuaeiu"};
//    string s = "aeeeiiiioooauuuaeiou";
//    string s = "a";

    LT1839 lt;

    cout<<lt.lt1839a(s)<<endl;

    return 0;
}
