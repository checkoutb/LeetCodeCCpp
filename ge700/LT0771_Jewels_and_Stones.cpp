
#include "../header/myheader.h"

class LT0771
{
public:


// discuss
// java.String.contains()
// c++ set<char> a(J.begin(), J.end())

// details 0ms 的是for {for { }}....

//Runtime: 4 ms, faster than 64.94% of C++ online submissions for Jewels and Stones.
//Memory Usage: 6 MB, less than 100.00% of C++ online submissions for Jewels and Stones.
    int lt0771a(string J, string S)
    {
        int ans = 0;
        int arr[128] = {0};
        for (char ch : S)
        {
            arr[ch]++;
        }
        for (char ch : J)
        {
            ans += arr[ch];
        }

        return ans;
    }

};

int main()
{

    string J = "aA", S = "aAAbbbb";

    LT0771 lt;

    cout<<lt.lt0771a(J, S)<<endl;

    return 0;
}
