
#include "../header/myheader.h"

class LT3085
{
public:

    // D D

    // cnt += vi[j] < a ? a : (max(0, vi[j] - a - k));



// Runtime
// 47ms
// Beats62.30%of users with C++
// Memory
// 18.14MB
// Beats55.06%of users with C++

    // delete to 0
    // delete to k+mincnt
    int minimumDeletions(string word, int k)
    {
        int arr[123] = {0};
        for (char ch : word)
        {
            ++arr[ch];
        }
        std::vector<int> vi;
        for (int i = 'a'; i <= 'z'; ++i)
        {
            if (arr[i] != 0)
                vi.push_back(arr[i]);
        }
        std::sort(std::begin(vi), end(vi));
        int mn = word.size();
        for (int i = 0; i < vi.size(); ++i)
        {
            int cnt = 0;
            for (int j = 0; j < i; ++j)     // delete to 0
                cnt += vi[j];

            for (int j = vi.size() - 1; j > i && vi[j] > (vi[i] + k); --j)  // delete to k + vi[i]
                cnt += (vi[j] - (vi[i] + k));

            mn = min(mn, cnt);
        }
        return mn;
    }

};

int main()
{

    LT3085 lt;


    return 0;
}
