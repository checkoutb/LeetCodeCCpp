
#include "../header/myheader.h"

class Solution {

public:


// TreeMap: int key = map.higherKey(randInt);




//Runtime: 84 ms, faster than 89.95% of C++ online submissions for Random Point in Non-overlapping Rectangles.
//Memory Usage: 28.3 MB, less than 12.50% of C++ online submissions for Random Point in Non-overlapping Rectangles.

    // 不知道有没有 按中心旋转x度的矩阵。

    Solution(vector<vector<int>>& rects) {
        srand(time(NULL));
        for (int i = 0; i < rects.size(); i++)
        {
            vector<int> v2 = rects[i];
            int s2 = (v2[2] - v2[0] + 1) * (v2[3] - v2[1] + 1);
            sum += s2;
            sums.push_back(sum);
        }
        rect2.assign(rects.begin(), rects.end());               // ...
    }
    vector<int> sums;
    int sum = 0;
    vector<vector<int>> rect2;
    vector<int> pick() {
        int t1 = rand() % sum;
        int i = 0;
        for (; i < sums.size(); i++)
        {
            if (t1 < sums[i])
            {
//                i--;
                break;
            }
        }
        if (i > 0)
            t1 -= sums[i - 1];
        vector<int> v5 = rect2[i];
        int t2 = t1 / (v5[2] - v5[0] + 1);
        int t3 = t1 % (v5[2] - v5[0] + 1);
        return {v5[0] + t3, v5[1] + t2};
    }
};

int main()
{
    vector<vector<int>> v = {{1,1,5,5}};

    Solution sol(v);

    vector<int> r = sol.pick();

    for_each(r.begin(), r.end(), fun_cout);
    cout<<endl;

    return 0;
}
