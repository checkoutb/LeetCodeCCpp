
#include "../header/myheader.h"

class LT0842
{
public:


// gg...

    vector<int> lt0842a(string S)
    {
        int sz1 = S.size();
        vector<int> ans;
        for (int i = 1; i < sz1 / 2; i++)
        {
            for (int j = 1; j < sz1 / 2; j++)
            {
                if (isfib(S, 0, i, j))
                {

                }
            }
        }
        return ans;
    }

    void dfsa1(string S, int start1, int start2)
    {

    }

    bool isfib(string S, int start, int len1, int len2)
    {
        if (S[start] == '0' || S[start + len1 + 1] == '0' || S[start + len1 + len2 + 1] == '0')
            return false;
        int i1 = std::atoi(S.substring(start, len1));
        int i2 = std::atoi(S.substring(start + len1, len2));
        int i3 = std::atoi(S.substring(start + len1 + len2, std::max(len1, len2)));
        #ifdef __test
        cout<<i1<<", "<<i2<<", "<<i3<<endl;
        #endif // __test
        return i1 + i2 == i3;
    }

};

int main()
{

    LT0842 lt;


    return 0;
}
