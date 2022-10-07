
#include "../header/myheader.h"

class LT2399
{
public:


    // D

    // 记录 第一次出现的下标， 然后在第二次出现时 算下距离

    // 记录最后一次出现。



//Runtime: 10 ms, faster than 62.09 % of C++ online submissions for Check Distances Between Same Letters.
//Memory Usage : 13.2 MB, less than 83.16 % of C++ online submissions for Check Distances Between Same Letters.
    bool lt2399a(string s, vector<int>& distance)
    {
        int sz1 = s.size();
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] == 'A')
                continue;

            int t2 = distance[s[i] - 'a'] + 1;
            
            //for (int j = t2 + i; j < sz1; j += t2)
            //{
            int j = i + t2;
                if (j >= sz1 || s[j] != s[i])
                {
                    return false;
                }
                s[j] = 'A';
            //}
        }
        return true;
    }

};

int main()
{

    LT2399 lt;

    string s = "abaccb";
    myvi v = { 1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

    cout << lt.lt2399a(s, v) << endl;

    return 0;
}
