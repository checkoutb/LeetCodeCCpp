
#include "../header/myheader.h"

class LT1869
{
public:

// D D

//	for(int i=0;i<s.length();i++)
//		if(s.charAt(i) == '0') {
//			longestZeros = Math.max(longestZeros, ++currentZeros);
//			currentOnes = 0;
//		} else {
//			longestOnes = Math.max(longestOnes, ++currentOnes);
//			currentZeros = 0;
//		}


//    for (auto ch : s) {
//        int v = ch - '0';
//        m_cnt[v] = max(m_cnt[v], ++cnt[v]);
//        cnt[1 - v] = 0;
//    }

//    for (int i = 0, j = 0; i < s.size(); j = i)
//        while(i < s.size() && s[i] == s[j])
//            m_cnt[s[j] - '0'] = max(m_cnt[s[j] - '0'], ++i - j);



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longer Contiguous Segments of Ones than Zeros.
//Memory Usage: 6.2 MB, less than 25.86% of C++ online submissions for Longer Contiguous Segments of Ones than Zeros.
    bool lt1869a(string s)
    {
        int mx0 = 0;
        int mx1 = 0;
        int t2 = 1;
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] != s[i - 1])
            {
                if (s[i - 1] == '0')
                {
                    mx0 = max(mx0, t2);
                }
                else
                {
                    mx1 = max(mx1, t2);
                }
                t2 = 1;
            }
            else
            {
                t2++;
            }
        }
        if (s[s.size() - 1] == '0')
            mx0 = max(mx0, t2);
        else
            mx1 = max(mx1, t2);
        return mx1 > mx0;
    }

};

int main()
{
//    string s = "1101";
//    string s = "111000";
    string s = "110100010";

    LT1869 lt;

    cout<<lt.lt1869a(s)<<endl;

    return 0;
}
