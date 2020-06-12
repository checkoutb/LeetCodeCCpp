
#include "../header/myheader.h"

class LT0854
{
public:


//https://leetcode.com/problems/k-similar-strings/discuss/140099/JAVA-BFS-32-ms-cleanconciseexplanationwhatever

// gg

    int lt0854a(string A, string B)
    {
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            char cha = A[i];
            char chb = B[i];
            if (cha != chb)
            {
                for (int j = i + 1; j < A.size(); j++)
                {
                    if (cha == B[j] && A[j] != cha)
                    {
                        ans++;
                        B[i] = cha;
                        B[j] = chb;
                        break;
                    }
                }
            }
        }
        return ans;
    }

};

int main()
{

//    string A = "abac", B = "baca";

// 8                难道不同的个数 / 2？  不，好长的。。
    string A = "abcdeabcdeabcdeabcde";
    string B = "aaaabbbbccccddddeeee";


    LT0854 lt;

    cout<<lt.lt0854a(A, B)<<endl;

    return 0;
}
