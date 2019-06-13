
#include "../header/myheader.h"

class LT0383
{
public:




// 数组替代map。。。ransomNote长度<magazine的长度。。。


//Runtime: 52 ms, faster than 8.93% of C++ online submissions for Ransom Note.
//Memory Usage: 11 MB, less than 56.33% of C++ online submissions for Ransom Note.

    bool lt0383a(string ransomNote, string magazine)
    {
        map<char, int> map2;
        for (string::iterator it2 = magazine.begin(); it2 != magazine.end(); it2++)
        {
            map2[*it2] = map2[*it2] + 1;
        }
        for (string::iterator it2 = ransomNote.begin(); it2 != ransomNote.end(); it2++)
        {
            int t1 = map2[*it2];
            if (t1 == 0)
                return false;
            map2[*it2] = t1 - 1;
        }
        return true;
    }
};

int main()
{
    string a = "aa";
    string b = "ab";
    LT0383 lt;

    cout<<lt.lt0383a(a, b)<<endl;
}
