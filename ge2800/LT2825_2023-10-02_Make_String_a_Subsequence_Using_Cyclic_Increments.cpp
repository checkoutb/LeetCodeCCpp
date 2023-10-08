
#include "../header/myheader.h"

class LT2825
{
public:

// D D

//    for(auto c: str2){
//        char t = (c == 'a')?'z': c - 1;
//        while(i < str1.size() && (str1[i] != c && str1[i] != t) ) i++;
//        if(i >= str1.size()) return false;
//        i++;
//    }



//Runtime40 ms
//Beats
//27.95%
//Memory14.4 MB
//Beats
//9.67%
    bool canMakeSubsequence(string str1, string str2)
    {
        int sz1 = str1.size();
        int sz2 = str2.size();
        int idx = 0;
        int t2, t3;
        for (int i = 0; i < sz1 && idx < sz2; ++i)
        {
            t2 = str1[i] - 'a';
            t3 = str2[idx] - 'a';

//            if (abs(t2 - t3) <= 1 || abs(t2 - t3) == 25)
            if (t3 == t2 + 1 || t3 == t2 || (t2 == 25 && t3 == 0))
                ++idx;
        }
        return idx == sz2;
    }

};

int main()
{

    LT2825 lt;


    return 0;
}
