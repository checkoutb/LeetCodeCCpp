
#include "../header/myheader.h"

class LT2423
{
public:





//Runtime: 3 ms, faster than 58.77% of C++ online submissions for Remove Letter To Equalize Frequency.
//Memory Usage: 5.9 MB, less than 98.46% of C++ online submissions for Remove Letter To Equalize Frequency.
    bool lt2423a(string word)
    {
        int arr[123] = {0};
        for (char ch : word)
            arr[ch]++;

        vector<int> vi;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (arr[i] != 0)
            {
                vi.push_back(arr[i]);
            }
        }

        sort(begin(vi), end(vi));

        if (vi[0] == 1)
        {
            for (int i = 2; i < vi.size(); ++i)
            {
                if (vi[i] != vi[i - 1])
                    goto AAA;
            }
            return true;
        }
        AAA:
        --vi[vi.size() - 1];

        for (int i = 1; i < vi.size(); ++i)
        {
            if (vi[i] != vi[i - 1])
                return false;
        }
        return true;
    }

};

int main()
{

    LT2423 lt;

    string s = "aazz";

    cout<<lt.lt2423a(s)<<endl;

    return 0;
}
