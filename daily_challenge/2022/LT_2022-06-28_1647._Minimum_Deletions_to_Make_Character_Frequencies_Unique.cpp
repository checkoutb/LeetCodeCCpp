
#include "../../header/myheader.h"

class LT
{
public:

    // D D




//Runtime: 56 ms, faster than 89.38% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.
//Memory Usage: 17.3 MB, less than 81.59% of C++ online submissions for Minimum Deletions to Make Character Frequencies Unique.
    int lta(string s)
    {
        int arr[123] = {0};
        for (char ch : s)
            arr[ch]++;
        int ans = 0;
        unordered_set<int> set2;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            int t2 = arr[i];
            if (t2 == 0)
                continue;
            while (t2 > 0 && set2.find(t2) != set2.end())
                t2--;
            ans += (arr[i] - t2);
            set2.insert(t2);
        }
        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
