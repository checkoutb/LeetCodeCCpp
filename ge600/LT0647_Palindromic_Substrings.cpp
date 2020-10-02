
#include "../header/myheader.h"

class LT0647
{
public:


// D D
//    private void extendPalindrome(String s, int left, int right) {
//        while (left >=0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
//            count++; left--; right++;
//        }
//    }


//        for(int i = 0; i < n; i++){
//            for(int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)res++; //substring s[i-j, ..., i+j]
//            for(int j = 0; i-1-j >= 0 && i+j < n && s[i-1-j] == s[i+j]; j++)res++; //substring s[i-1-j, ..., i+j]
//        }
//        return res;



// 基本都是[0,40]ms的，调用个方法这么耗时吗。。
//Runtime: 536 ms, faster than 9.24% of C++ online submissions for Palindromic Substrings.
//Memory Usage: 384.9 MB, less than 6.63% of C++ online submissions for Palindromic Substrings.
    int lt0647a(string s)
    {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans += lena1(s, i);
            ans += lena1(s, i, i + 1);
        }
        return ans;
    }

    int lena1(string s, int i)
    {
        int m = 1;
        int ans = 1;
        while (isEqual(s, i - m, i + m))
        {
            ans++;
            m++;
        }
        return ans;
    }

    int lena1(string s, int i, int j)
    {
        int m = 0;
        int ans = 0;
        while (isEqual(s, i - m, j + m))
        {
            ans++;
            m++;
        }
        return ans;
    }

    bool isEqual(string s, int i, int j)
    {
        if (i < 0 || i >= s.size() || j < 0 || j >= s.size())
            return false;
        return s[i] == s[j];
    }

};

int main()
{

    string arr[] = {"aaa","abc"};

    LT0647 lt;

    for (string s : arr)
    {
        cout<<lt.lt0647a(s)<<endl;
    }

    return 0;
}
