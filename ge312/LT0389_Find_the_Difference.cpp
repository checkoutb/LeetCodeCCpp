
#include "../header/myheader.h"

class LT0389
{
public:



// details:
// 1. 第二个for中，如果arr2[] < 0, 可以直接return
// 2. 使用^

//        char c = s[0];
//        for(int i=1;i<s.length();i++)
//            c = c^s[i];
//        for(int i=0;i<t.length();i++)
//            c = c^t[i];
//        return c;

//        char ch=0;
//        int i;
//        for(i=0;i<s.size();i++)
//        {
//            ch=ch^(s[i]^t[i]);
//        }
//        ch^=t[i];
//        return ch;


// discuss

//    def findTheDifference(self, s, t):
//        diff = 0
//        for i in range(len(s)):
//            diff -= ord(s[i])
//            diff += ord(t[i])
//        diff += ord(t[-1])
//        return chr(diff)
// 累加t，累减s，结果就是char的ascii码。

//    public char findTheDifference(String s, String t) {
//        int charCode = t.charAt(s.length());
//        // Iterate through both strings and char codes
//        for (int i = 0; i < s.length(); ++i) {
//              charCode -= (int)s.charAt(i);
//              charCode += (int)t.charAt(i);
//        }
//        return (char)charCode;
//    }

// StefanPochmann   August 29, 2016 5:03 AM
//public char findTheDifference(String s, String t) {
//    return (char) (s + t).chars().reduce(0, (c, d) -> c ^ d);
//}
//
//char findTheDifference(string s, string t) {
//    return accumulate(begin(s), end(s += t), 0, bit_xor<int>());
//}
//
//char findTheDifference(string s, string t) {
//    return accumulate(begin(t), end(t), accumulate(begin(s), end(s), 0, bit_xor<int>()), bit_xor<int>());
//}
//
//char findTheDifference(string s, string t) {
//    return accumulate(begin(t), end(t), 0) - accumulate(begin(s), end(s), 0);
//}
//
//char findTheDifference(string s, string t) {
//    char x = 0;
//    for (char c : s + t)
//        x ^= c;
//    return x;
//}







//    Runtime: 4 ms, faster than 92.03% of C++ online submissions for Find the Difference.
//    Memory Usage: 9 MB, less than 47.52% of C++ online submissions for Find the Difference.

    char lt0389a(string s, string t)
    {
        int arr2[26] = {0};
        for (char ch : s)
        {
            arr2[ch - 'a']++;
        }
        for (char ch : t)
        {
            arr2[ch - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr2[i] < 0)
            {
                return (char) (i + 'a');
            }
        }
        return 'A';
    }
};

int main()
{
    string s = "asdf";
    string t = "sdfwa";

    LT0389 lt;
    cout<<lt.lt0389a(s, t)<<endl;
}
