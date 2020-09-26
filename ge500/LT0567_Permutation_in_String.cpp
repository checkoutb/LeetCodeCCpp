
#include "../header/myheader.h"

class LT0567
{
public:

// D D

//        int[] count = new int[128];
//        for(int i = 0; i < s1.length(); i++) count[s1.charAt(i)]--;
//        for(int l = 0, r = 0; r < s2.length(); r++) {
//            if (++count[s2.charAt(r)] > 0)
//                while(--count[s2.charAt(l++)] != 0) { /* do nothing */}
//            else if ((r - l + 1) == s1.length()) return true;
//        }
//        return s1.length() == 0;
//.. 这个好像是 保证 count中 始终都是0， 然后看 这个substr的长度。。。。


//Runtime: 8 ms, faster than 99.42% of C++ online submissions for Permutation in String.
//Memory Usage: 7.4 MB, less than 38.77% of C++ online submissions for Permutation in String.
// chuangkouhuadong... haoxiang jiao huadongchuangkou...
    bool lt0567a(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;

        int arr[26] = {0};
        int diffNum = 0;
        for (char ch : s1)
        {
            if (arr[ch - 'a'] == 0)
                diffNum++;
            arr[ch - 'a']++;
        }

        for (int i = 0; i < s1.size(); i++)
        {
            if (arr[s2[i] - 'a'] == 0)
                diffNum++;
            arr[s2[i] - 'a']--;
            if (arr[s2[i] - 'a'] == 0)
                diffNum--;
        }
        if (diffNum == 0)
            return true;

        for (int i = s1.size(); i < s2.size(); i++)
        {
            if (s2[i] == s2[i - s1.size()])         // ..
                continue;
            if (arr[s2[i] - 'a'] == 0)
                diffNum++;
            if (arr[s2[i - s1.size()] - 'a'] == 0)
                diffNum++;
            int t1 = --arr[s2[i] - 'a'];
            int t2 = ++arr[s2[i - s1.size()] - 'a'];
            if (t1 == 0)
                diffNum--;
            if (t2 == 0)
                diffNum--;
            if (diffNum == 0)
                return true;
        }

        return false;
    }

};

int main()
{

//    string s1 = "ab", s2 = "eidbqaooo";

    string s1 = "ky";
//    string s2 = "ainwkckifykxlribaypk";
    string s2 = "kfky";


    LT0567 lt;

    cout<<lt.lt0567a(s1, s2)<<endl;

    return 0;
}
