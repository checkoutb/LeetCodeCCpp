
#include "../header/myheader.h"

class LT2024
{
public:

// D D

//        for(j;j<n;j++)
//        {
//            ct += (s[j]=='T');
//            cf += (s[j]=='F');
//
//            while(i<j && min(ct,cf)>k)
//            {
//                ct -= (s[i]=='T');
//                cf -= (s[i]=='F');
//                i++;
//            }
//            ans=max(ans,j-i+1);
//        }



//Runtime: 28 ms, faster than 79.98% of C++ online submissions for Maximize the Confusion of an Exam.
//Memory Usage: 10.1 MB, less than 72.37% of C++ online submissions for Maximize the Confusion of an Exam.
// sliding window
    int lt2024a(string answerKey, int k)
    {
        int ans = 0;
        int chg = 0;
        int st = 0;
        // all T
        for (int i = 0; i < answerKey.size(); i++)
        {
            if (answerKey[i] != 'T')
                ++chg;
            while (chg > k)
            {
                if (answerKey[st] != 'T')
                    chg--;
                st++;
            }
            ans = max(ans, i - st + 1);
        }

        // all F
        st = 0;
        chg = 0;
        for (int i = 0; i < answerKey.size(); i++)
        {
            if (answerKey[i] != 'F')
                ++chg;
            while (chg > k)
            {
                if (answerKey[st++] != 'F')
                    --chg;
            }
            ans = max(ans, i - st + 1);
        }

        return ans;
    }

};

int main()
{

    LT2024 lt;


    return 0;
}
