
#include "../header/myheader.h"

class LT0488
{
public:

// D

// 。。。RRWWRRBBRR + WB 还是用户提出的。。。




// g


// error
// <= 16 . 16! 很大的
    int lt048a(string board, string hand)
    {
        unordered_map<char, int> map2;
        for (char ch : hand)
            map2[ch]++;

        vector<pair<char, int>> vp;
        char ch = board[0];
        int cnt = 1;
        for (int i = 1; i < board.size(); ++i)
        {
            if (board[i] != board[i - 1])
            {
                vp.push_back(make_pair(ch, cnt));
                ch = board[i];
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        vp.push_back({ch, cnt});

        int ans = dfsa1(vp, map2, 0);
        return ans;
    }

    // AABA
    int dfsa1(vector<pair<char, int>> vp, unordered_map<char, int>& map2, int depth)
    {
        if (vp.size() == 0)
            return 0;
        #ifdef __test
//        cout<<"1  "<<vp.size()<<endl;
        cout<<depth<<": ";
        for (pair<char, int>& p : vp)
        {
//            cout<<p.second<<endl;
//            for (int i = 0; i < p.second; ++i)
//                cout<<p.first;
            cout<<p.first<<""<<p.second<<", ";
        }
        cout<<endl;
        #endif // __test
        int ans = INT_MAX;
        for (int i = 0; i < vp.size(); ++i)
        {
            // remove or skip

            char ch = vp[i].first;
            char cnt = vp[i].second;
            if (map2[ch] >= (3 - cnt))
            {
                vector<pair<char, int>> vp2(begin(vp), end(vp));
                vp2.erase(begin(vp2) + i);

                int i3 = i;
                while (i3 > 0 && (vp2[i3].first == vp2[i3 - 1].first))
                {
                    if ((vp2[i3].second + vp2[i3 - 1].second >= 3))
                    {
                        vp2.erase(begin(vp2) + i3);
                        vp2.erase(begin(vp2) + i3 - 1);
                        i3--;
                    }
                    else
                    {
                        vp2[i3 - 1].second += vp2[i3].second;
                        vp2.erase(begin(vp2) + i3);
                        break;
                    }
                }
//                while (i > 0 && (vp2[i].first == vp2[i - 1].first) && (vp2[i].second + vp2[i - 1].second >= 3))
//                {
//                    vp2.erase(begin(vp2) + i);
//                    vp2.erase(begin(vp2) + i - 1);
//                    i--;
//                }

                map2[ch] -= (3 - cnt);
                int t2 = dfsa1(vp2, map2, depth + 1);

                if (t2 != -1)
                {
                    ans = min(ans, t2 + (3 - cnt));
                }

                map2[ch] += (3 - cnt);
            }
            else
            {
                ;
            }

        }
        return ans == INT_MAX ? -1 : ans;
    }

};

int main()
{

    LT0488 lt;

//    string s = "WWRRBBWW";
//    string t = "WRBRW";

//    string s = "WRRBBW";
//    string t = "RB";

//    string s = "WWGWGW";        // wwgwWWgw  wwggw  wwggGw
//    string t = "GWBWR";

    stromg s = "RRWWRRBBRR";    // ? 这？ 要么 RRWW 要么 BBRR , 怎么消得完？ 。。。RRWWRRBBR[w]R ...  那就得一个个试过去。。肯定tle的。
    strint t = "WB";        // 2


    cout<<lt.lt048a(s, t)<<endl;

    return 0;
}
