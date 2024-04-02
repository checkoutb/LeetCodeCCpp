
#include "../header/myheader.h"

class LT3081
{
public:

    // D D

        // // d[i] = c[x]
        // for( int i = 0; i < qsi ; i++ ){
        //     int min_ch = 0;
        //     for( int ch = 0 ; ch < 26 ; ch++ ){
        //         if( c[min_ch] > c[ch] ) min_ch = ch;
        //     }
        //
        //     d[min_ch]++;
        //     c[min_ch]++;
        // }




// Runtime
// 89ms
// Beats70.19%of users with C++
// Memory
// 21.03MB
// Beats68.45%of users with C++

    // 会影响后面，所以要整体最少，平均
    string minimizeStringValue(string s)
    {
        int sz1 = s.size();
        int arr[123] = {0};

        for (char ch : s)
            if (ch != '?')
                ++arr[static_cast<int>(ch)];

        int cnt2 = 0;
        for (int i = 'a'; i <= 'z'; ++i)
            cnt2 += arr[i];

        int st = 0, en = sz1 / 26 + 1;
        int avg = -1;
        while (st <= en)
        {
            int md = (st + en) / 2;
            int cnt3 = 0;
            for (int i = 'a'; i <= 'z'; ++i)
            {
                cnt3 += std::max(md, arr[i]);
            }
            if (cnt3 >= sz1)
            {
                avg = md;
                en = md - 1;
            }
            else
            {
                st = en + 1;
            }
        }
        avg -= 1;

        std::priority_queue<pair<int, int>, std::vector<pair<int, int>>, std::greater<>> priq;
        int cnt4 = 0;
        int arr2[123] = {0};
        for (int i = 'a'; i <= 'z'; ++i)
        {
            arr2[i] = std::max(0, avg - arr[i]);
            priq.push(std::make_pair(arr[i] + arr2[i], i));
            cnt4 += arr[i] + arr2[i];
        }

        while (cnt4 < sz1)
        {
            std::pair<int, int> p = priq.top();
            priq.pop();
            ++arr2[p.second];
            p.first += 1;
            priq.push(p);
            ++cnt4;
        }

        int idx2 = 'a';
        for (int i = 0; i < sz1; ++i)
        {
            if (s[i] == '?')
            {
                while (arr2[idx2] == 0)
                    ++idx2;

                s[i] = static_cast<char>(idx2);
                --arr2[idx2];
            }
        }

        return s;
    }


};

int main()
{

    LT3081 lt;


    return 0;
}
