
#include "../header/myheader.h"

class LT0859
{
public:

// D D
//if (A == B && set<char>(A.begin(), A.end()).size() < A.size()) return true;
//return dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Buddy Strings.
//Memory Usage: 6.9 MB, less than 66.00% of C++ online submissions for Buddy Strings.
    bool lt0859a(string A, string B)
    {
        if (A.size() != B.size())
            return false;
        vector<int> diffv;
        int arr[26] = {0};
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] != B[i])
            {
                diffv.push_back(i);
            }
            arr[A[i] - 'a']++;
        }
        if (diffv.size() == 0)
        {
            for (int i = 0; i < 26; i++)
            {
                if (arr[i] >= 2)
                    return true;
            }
            return false;
        }
        if (diffv.size() != 2)
            return false;

        int i1 = diffv[0];
        int i2 = diffv[1];
        if (A[i2] != B[i1] || A[i1] != B[i2])
        {
            return false;
        }
        return true;
    }

};

int main()
{

//    string a = "ab", b = "ba";
//    string a = "ab", b = "ab";

//    string a = "aa", b = "aa";

    string a = "aaaaabc", b = "aaaaacb";

    LT0859 lt;

    cout<<lt.lt0859a(a, b)<<endl;

    return 0;
}
