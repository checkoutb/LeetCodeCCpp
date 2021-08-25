
#include "../../header/myheader.h"

class LT
{
public:

// D

// 。。切分。
// 1种是，获得全部的 x，y的 set。
//      然后对于每个矩阵，切分，  切分是一个个块，记录下，反正一共就   x的个数 × y的个数 个 块。
//   就是一个块 可能是1*1  也可能是 100000×1000000. 。

// 另外一种是 对每个元素， dfs，如果和其他重叠，就放一个。




// error。。。
// ... 减去的太多了。。
// forfor 应该可行的。毕竟通过率在那儿。
    int ltb(myvvi& rectangles)
    {
        long long ans = 0;
        long long t2 = 0;
        for (int i = 0; i < rectangles.size(); ++i)
        {
            ans += 1L * (rectangles[i][3] - rectangles[i][1]) * (rectangles[i][2] - rectangles[i][0]);
            for (int j = i + 1; j < rectangles.size(); ++j)
            {
                ans -= coverb1(rectangles[i], rectangles[j]);
                cout<<" . .. "<<ans<<endl;
            }
            #ifdef __test
            cout<<ans<<endl;
            #endif // __test
        }
        return ans % (int) (1E9 + 7);
    }

    long long coverb1(vector<int>& v1, vector<int>& v2)
    {
        if (v1[0] < v2[2] && v1[2] > v2[0] && v1[1] < v2[3] && v1[3] > v2[1])
        {
            return 1L * (min(v1[2], v2[2]) - max(v1[0], v2[0])) * (min(v1[3], v2[3]) - max(v1[1], v2[1]));
        }
        return 0L;
    }


// 扫描线？   最多200个矩形
// stack？  priq
// for-for 查看 2个矩形是否有重叠， 有就-重叠。200个不多。
// 扫描线得记录些东西。。好烦的啊。
    int lta(vector<vector<int>>& rectangles)
    {
        long long ans = 0;
        priority_queue<pair<int, vector<int>>> priq;
        std::sort(begin(rectangles), end(rectangles));
        priq.push({rectangles[0][2], rectangles[0]});
        int xst = rectangles[0][0];
        int yl = rectangles[0][1];
        int yh = rectangles[0][3];
        for (int i = 1; i < rectangles.size(); ++i)
        {
            while (!priq.empty() && priq.top().first < rectangles[i][0])
            {
                priq.pop();
            }
            vector<vector<int>> vvi(begin(priq), end(priq));


        }
        return ans % (int) (1E9 + 7);
    }

};

int main()
{
    myvvi vv = {{0,0,2,2},{1,0,2,3},{1,0,3,1}};

    LT lt;

    cout<<lt.ltb(vv)<<endl;

    return 0;
}
