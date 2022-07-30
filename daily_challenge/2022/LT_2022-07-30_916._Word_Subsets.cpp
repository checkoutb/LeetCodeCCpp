
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //tmp = counter(a);
    //for (i = 0; i < 26; ++i)
    //    if (tmp[i] < count[i])
    //        break;
    //if (i == 26) res.push_back(a);






//Runtime: 126 ms, faster than 97.75 % of C++ online submissions for Word Subsets.
//Memory Usage : 57.5 MB, less than 80.67 % of C++ online submissions for Word Subsets.
    // 这道还没有做出来过。。。
    // 应该是把 words2 压缩成一个。
    vector<string> lta(vector<string>& words1, vector<string>& words2)
    {
        int arr[123] = { 0 };
        for (string& s : words2)
        {
            int arr2[123] = { 0 };
            for (char ch : s)
                arr2[ch]++;

            for (int i = 'a'; i <= 'z'; ++i)
            {
                arr[i] = max(arr[i], arr2[i]);
            }
        }
        vector<string> ans;
        for (string& s : words1)
        {
            int arr2[123] = { 0 };
            for (char ch : s)
                arr2[ch]++;

            for (int i = 'a'; i <= 'z'; ++i)
            {
                if (arr2[i] < arr[i])
                    goto AAA;
            }
            ans.push_back(s);

            AAA:
            continue;
        }
        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
