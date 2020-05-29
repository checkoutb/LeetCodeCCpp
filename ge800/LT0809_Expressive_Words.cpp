
#include "../header/myheader.h"

class LT0809
{
public:


// discuss
//    bool check(string S, string W) {
//        int n = S.size(), m = W.size(), i = 0, j = 0;
//        for (int i2 = 0, j2 = 0; i < n && j < m; i = i2, j = j2) {
//            if (S[i] != W[j]) return false;
//            while (i2 < n && S[i2] == S[i]) i2++;
//            while (j2 < m && W[j2] == W[j]) j2++;
//            if (i2 - i != j2 - j && i2 - i < max(3, j2 - j)) return false;
//        }
//        return i == n && j == m;
//    }
// i是char的开始，i2是该连续char的结束后的下一个char。i2-i就是长度。



//Runtime: 12 ms, faster than 48.71% of C++ online submissions for Expressive Words.
//Memory Usage: 7.6 MB, less than 100.00% of C++ online submissions for Expressive Words.
    int lt0809a(string S, vector<string>& words)
    {
        int ans = 0;
        vector<char> chArr;
        vector<int> numArr;
        chArr.push_back(S[0]);
        numArr.push_back(1);

        for (int i = 1; i < S.size(); i++)
        {
            char ch = S[i];
            if (ch == chArr.back())
            {
                numArr.back()++;
            }
            else
            {
                chArr.push_back(ch);
                numArr.push_back(1);
            }
        }

        #ifdef __test
        for_each(chArr.begin(), chArr.end(), fun_cout);
        cout<<endl;
        for_each(numArr.begin(), numArr.end(), fun_cout);
        cout<<endl;
        #endif // __test

        for (string w : words)
        {
            if (checka1(w, chArr, numArr))
                ans++;
        }

        return ans;
    }

    bool checka1(string& word, vector<char>& arr1, vector<int>& arr2)
    {
        char lastCh = word[0];
        int chNum = 1;
        int chCnt = 0;
        for (int i = 1; i < word.size(); i++)
        {
            char ch = word[i];
            if (ch == lastCh)
            {
                chNum++;
            }
            else
            {
                if (chCnt >= arr1.size())
                    return false;
                char sCh = arr1[chCnt];
                int sNum = arr2[chCnt];

                #ifdef __test
//                cout<<sCh<<", ch "<<lastCh<<endl;
//                cout<<sNum<<", num "<<chNum<<endl;
                #endif // __test

                if (sCh != lastCh)
                    return false;
                if (sNum < chNum || (sNum != chNum && sNum == 2))
                    return false;

                lastCh = ch;
                chNum = 1;
                chCnt++;
            }
        }

        if (chCnt != arr1.size() - 1)
            return false;
        char sCh = arr1[chCnt];
        int sNum = arr2[chCnt];
        if (sCh != lastCh)
            return false;
        if (sNum < chNum || (sNum != chNum && sNum == 2))
            return false;

        #ifdef __test
        cout<<word<<endl;
        #endif // __test

        return true;
    }

};

int main()
{

//    string S = "heeellooo";
//    vector<string> words = {"hello", "hi", "helo"};


// 是扩展一个组到3个。 不是一个char必须扩展>=3个。
//dinnssoo, ddiinnso, ddiinnssoo
    string S = "dddiiiinnssssssoooo";
    vector<string> words = {"dinnssoo","ddinso","ddiinnso","ddiinnssoo","ddiinso","dinsoo","ddiinsso","dinssoo","dinso"};

    LT0809 lt;

    cout<<lt.lt0809a(S, words);

    return 0;
}
