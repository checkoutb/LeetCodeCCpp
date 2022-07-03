
#include "../header/myheader.h"

class LT0818
{
public:





    // 或许就是一条路走到底，然后转向，再走到底。
    // 不不不， 这个反向走是 抵消。  所以就变成了  x.x+1.x+2.x+3 长度是 target 的 最小
    // 也不是， 可以 2次反向走。
    int lt0818b(int target)
    {

    }


    // it will stackoverflow... 或许可以 先 走到底，再走到底 * N... 然后找到 一个 ans， 用来 剪枝。目前， ans 一直都是 INT_MAX。。。
    int lt0818a(int target)
    {
        //int arr[10001] = { 0 };
        //bool vst[10001] = { false };

        // ... 

        unordered_map<int, unordered_map<int, int>> map2;           // <position, <speed, length>>
        int t2 = INT_MAX;
        int ans = dfsa1(target, map2, 0, 1, 0, 0, t2);
        return ans;
    }

    int dfsa1(int target, unordered_map<int, unordered_map<int, int>>& map2, int idx, int speed, int step, int chg, int& ans)
    {
#ifdef __test
        cout << idx << ", " << step << ", " << chg << ", " << speed << ", " << ans << endl;
        //getchar();
#endif
        //if (abs(idx) > target * 2)
        //    return -1;
        if (chg > 2)
            return -1;

        if (step > ans)
            return -1;

        if (idx == target)
        {
            ans = min(ans, step);
            return step;
        }

        if (map2[idx].find(speed) != map2[idx].end())
            return map2[idx][speed];

        map2[idx][speed] = -1;

        int t2 = -1;
        if (abs(idx) < target)
            t2 = dfsa1(target, map2, idx + speed, speed * 2, step + 1, 0, ans);
        int t3 = dfsa1(target, map2, idx, (speed > 0 ? -1 : 1), step + 1, chg + 1, ans);

        map2[idx][speed] = min(t2 == -1 ? INT_MAX : t2, t3 == -1 ? INT_MAX : t3);
        return map2[idx][speed];
    }

};

int main()
{

    LT0818 lt;

    int tar = 8976;


    cout << lt.lt0818a(tar) << endl;

    return 0;
}
