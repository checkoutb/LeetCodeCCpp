
#include "../header/myheader.h"

class LT1531
{
public:





    // g

    int lt1531b(string s, int k)
    {

    }



    // error ... aabbaa ->  aaaa   a4
    // 
    // "a" -> ""        - 1
    // a2 -> a      -1
    // a10 -> a9
    // a100 -> a99  a9 ...
    int lt1531a(string s, int k)
    {
        int sz1 = s.size();
        //vector<int> vi;
        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> priq;
        int t2 = 0;
        for (int i = 0; i < sz1; ++i)
        {
            t2 = i;
            while (i + 1 < sz1 && s[i + 1] == s[t2])
                ++i;
            
            t2 = i - t2 + 1;

            if (t2 <= 2 || t2 == 100)
                priq.emplace(std::make_pair(1, t2));
            else if (t2 < 10)
            {
                priq.emplace(std::make_pair(t2 - 1, t2));
            }
            else
            {
                // >= 10     <=99
                priq.emplace(std::make_pair(t2 - 9, t2));
            }

            //vi.push_back(i - t2 + 1);
        }
        //sort(begin(vi), end(vi));

        //for (int i = 0; i < vi.size(); ++i)
        //{
        //    
        //}

        while (!priq.empty() && priq.top().first <= k)
        {
            pair<int, int> p2 = priq.top();
            priq.pop();

            t2 = p2.second - p2.first;
            k -= p2.first;

            if (t2 == 0)
                continue;

            if (t2 <= 2 || t2 == 100)
                priq.emplace(std::make_pair(1, t2));
            else if (t2 < 10)
            {
                priq.emplace(std::make_pair(t2 - 1, t2));
            }
            else
            {
                // >= 10     <=99
                priq.emplace(std::make_pair(t2 - 9, t2));
            }

        }
        int ans = 0;
        while (!priq.empty())
        {
            if (priq.top().second == 1)
            {
                ans += 1;
            }
            else if (priq.top().second < 10)
            {
                ans += 2;
            }
            else if (priq.top().second < 100)
            {
                ans += 3;
            }
            else
            {
                ans += 4;
            }
            priq.pop();
        }
        return ans;
    }

};

int main()
{

    LT1531 lt;

    //string s = "aaabcccd";
    //int k = 2;

    string s = "aabbaa";
    int k = 2;

    cout << lt.lt1531a(s, k) << endl;

    return 0;
}
