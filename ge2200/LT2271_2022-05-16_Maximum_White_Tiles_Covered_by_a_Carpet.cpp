
#include "../header/myheader.h"

class LT2271
{
public:

// D D


//    int res = 0, j = 0, cover = 0;
//    sort(begin(t), end(t));
//    for (int i = 0; res < len && i < t.size(); )
//        if (j == i || t[j][0] + len > t[i][1]) {
//            cover += min(len, t[i][1] - t[i][0] + 1);
//            res = max(res, cover);
//            ++i;
//        }
//        else {
//            int partial = max(0, t[j][0] + len - t[i][0]);
//            res = max(res, cover + partial);
//            cover -= (t[j][1] - t[j][0] + 1);
//            ++j;
//        }
//    return res;




//Runtime: 747 ms, faster than 50.00% of C++ online submissions for Maximum White Tiles Covered by a Carpet.
//Memory Usage: 70.8 MB, less than 50.00% of C++ online submissions for Maximum White Tiles Covered by a Carpet.
    int lt2271b(vector<vector<int>>& tiles, int carpetLen)
    {
        int sz1 = tiles.size();
        std::sort(begin(tiles), end(tiles));
        vector<int> vi(sz1);
        for (int i = 0; i < tiles.size(); ++i)
        {
            vi[i] = tiles[i][1] - tiles[i][0] + 1;
            if (i != 0)
                vi[i] += vi[i - 1];
        }
        int eni = 0;
        int ans = 0;
        for (int i = 0; i < sz1; ++i)
        {
            int cpst = tiles[i][0];
            int cpen = cpst + carpetLen - 1;
            while (eni < sz1 && tiles[eni][1] <= cpen)
            {
                eni++;
            }
            int t2 = vi[eni - 1] - (i == 0 ? 0 : vi[i - 1]);
            if (eni == sz1)
            {
                if (t2 > ans)
                    ans = t2;
                break;
            }
            else
            {
                int t3 = cpen - tiles[eni][0] + 1;
                t2 += max(t3, 0);
                if (t2 > ans)
                    ans = t2;
            }
        }
        return ans;
    }


// g, 还是弄个prefix sum。。。
// 在 carpetlen 长度内，最多有多少个数字
// carpet 的起始 可以是每个 tile 的 起始。 其他不需要关心。
    int lt2271a(vector<vector<int>>& tiles, int carpetLen)
    {
        std::sort(begin(tiles), end(tiles));
        int st = 0;
        int en = 0;
        int cpst = tiles[st][0];
        int cpen = cpst + carpetLen - 1;        // [ , ]
        int sz1 = tiles.size();
        while (en < sz1 && tiles[en][0] <= cpen)
        {
            en++;
        }
        en--;
        int ans = 0;
        for (int i = st; i < en; ++i)
        {
            ans += tiles[i][1] - tiles[i][0] + 1;
        }
        int a = ans;
        ans += min(cpen, tiles[en][1]) - tiles[en][0] + 1;
        en--;

        #ifdef __test
        cout<<a<<", "<<ans<<", "<<cpst<<", "<<cpen<<endl;
        #endif // __test

        for (st++ ; cpen < tiles[sz1 - 1][1]; st++)
        {
//            a -= tiles[st - 1][1] - tiles[st - 1][0] + 1;
//            a = max(0, a);
            if (st <= en)
            {
                a -= tiles[st - 1][1] - tiles[st - 1][0] + 1;
            }
            int en2 = en;
            cpst = tiles[st][0];
            cpen = cpst + carpetLen - 1;
            en = max(st, en);
            while (en < sz1 && tiles[en][0] <= cpen)
            {
                en++;
            }
            en--;
            for (int i = en2 + 1; i < en; ++i)
            {
                a += tiles[i][1] - tiles[i][0];
            }
            int t2 = a + min(cpen, tiles[en][1]) - tiles[en][0] + 1;
            en--;
            if (t2 > ans)
            {
                ans = t2;
            }

            #ifdef __test
            cout<<a<<", "<<ans<<", "<<t2<<endl;
            #endif // __test

        }
        return ans;
    }

};

int main()
{

    LT2271 lt;

//    myvvi vv = {{1,5},{10,11},{12,18},{20,25},{30,32}};
//    int cpl = 10;       // 9

//    myvvi vv = {{10,11},{1,1}};
//    int cpl = 2;

// 126
    myvvi vv = {{8051,8057},{8074,8089},{7994,7995},{7969,7987},{8013,8020},{8123,8139},{7930,7950},{8096,8104},{7917,7925},{8027,8035},{8003,8011}};
    int cpl = 9854;

    cout<<lt.lt2271b(vv, cpl)<<endl;

    return 0;
}
