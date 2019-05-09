
#include "../header/myheader.h"

class LT0344
{
public:

// discuss
// 看来这个题目改过。。

// c++
//    string reverseString(string s) {
//        return { s.rbegin(), s.rend() };
//    }

// 老忘记这种i<j，每次都是for。。。。
//        while(i < j){
//            swap(s[i++], s[j--]);
//        }



// java
//return new StringBuilder(s).reverse().toString();

//        if (length <= 1) return s;
//        String leftStr = s.substring(0, length / 2);
//        String rightStr = s.substring(length / 2, length);
//        return reverseString(rightStr) + reverseString(leftStr);

//        while (i < j) {
//            word[i] = (char) (word[i] ^ word[j]);
//            word[j] = (char) (word[i] ^ word[j]);
//            word[i] = (char) (word[i] ^ word[j]);
//            i++;
//            j--;
//        }
// 异或有点猛。。第二条赋值等于  i ^ j ^ j == i ^ 0, 结果就是i。。第三条等于 i ^ j ^ i, 最后一个i就是 第二条的。



//    Runtime: 64 ms, faster than 34.37% of C++ online submissions for Reverse String.
//Memory Usage: 15.1 MB, less than 99.59% of C++ online submissions for Reverse String.

    void lt0344a(vector<char>& s)
    {
        int sz1 = s.size();
        int sz2 = sz1 / 2;
        char ch;
        for (int i = 0; i < sz2; i++)
        {
            ch = s[i];
            s[i] = s[sz1 - i - 1];
            s[sz1 - i - 1] = ch;
        }
    }
};

int main()
{
    char arr[] = {'H','e','l','l','o'};
    vector<char> v;
    for (int i = 0; i < 5; i++)
    {
        v.push_back(arr[i]);
    }

    LT0344 lt;
    lt.lt0344a(v);

    for (int i = 0; i < 5; i++)
    {
        cout<<v[i]<<", ";
    }

    return 0;
}
