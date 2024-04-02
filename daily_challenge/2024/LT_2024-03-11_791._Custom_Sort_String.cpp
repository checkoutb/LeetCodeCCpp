
#include "../../header/myheader.h"

class LT
{
public:



    // AC
    string customSortString(string order, string s)
    {
        std::array<int, 123> arr;
        for (char ch : s)
            ++arr[ch];
        std::string ans;
        for (char ch : order)
        {
            ans.append(arr[ch], ch);
            arr[ch] = 0;
        }
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (arr[i] != 0)
            {
                ans.append(arr[i], char(i));
            }
        }
        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
