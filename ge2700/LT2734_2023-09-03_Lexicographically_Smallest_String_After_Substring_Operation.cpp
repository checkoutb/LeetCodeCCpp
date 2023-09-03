
#include "../header/myheader.h"

class LT2734
{
public:


// D D

//        while(j<N && s[j]=='a') { ++j; }
//        for(; j<N && s[j]!='a'; ++j, ++found) { s[j] = (s[j]-'a'-1+26)%26 + 'a'; }
//        if(!found) { s.back() = 'z'; }





//Runtime112 ms
//Beats
//62.76%
//Memory40.3 MB
//Beats
//26%

    // op 1
    string smallestString(string s)
    {
        int sz1 = s.size();
        bool hasStart = false;
        for (int i = 0; i < sz1; ++i)
        {
            if (hasStart)
            {
                if (s[i] != 'a')
                {
                    --s[i];
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (s[i] != 'a')
                {
                    --s[i];
                    hasStart = true;
                }
            }
        }
        if (!hasStart)      // ... must one operation
        {
            s[sz1 - 1] = 'z';
        }
        return s;
    }

};

int main()
{

    LT2734 lt;


    return 0;
}
