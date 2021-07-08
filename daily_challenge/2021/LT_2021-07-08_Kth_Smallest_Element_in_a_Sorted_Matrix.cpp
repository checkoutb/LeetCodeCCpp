
#include "../../header/myheader.h"

class LT
{
public:

// D D

// ... 直接转成一维数组，sort，  36ms。
// 全部放到priq<int>， 然后pop，40ms

// binary search,
// [0][0] - [sz1-1][sz1-1]




// AC  68ms
    int ltb(vector<vector<int>>& matrix, int k)
    {
        int sz1 = matrix.size();
        map<int, int> map2;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz1; ++j)
            {
                map2[matrix[i][j]]++;
            }
        }
        int ans = -1;
        while (k > 0)
        {
            ans = map2.begin()->first;
            k -= map2.begin()->second;
            map2.erase(ans);
        }
        return ans;
    }



// AC   Runtime: 48 ms     beat 24%      most are [24,40]ms
// 转map。。。
// priq
    int lta(vector<vector<int>>& matrix, int k)
    {
        int sz1 = matrix.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>> > priq;
        priq.push(std::make_tuple(matrix[0][0], 0, 0));
        while (k-- > 1)
        {
            tuple<int, int, int> tiii = priq.top();
            priq.pop();
            int r = std::get<1>(tiii);
            int c = std::get<2>(tiii);
            #ifdef __test
            cout<<std::get<0>(tiii)<<", ";
            #endif // __test
            if (r + 1 < sz1 && matrix[r + 1][c] != INT_MAX)
            {
                priq.push(make_tuple(matrix[r + 1][c], r + 1, c));
                matrix[r + 1][c] = INT_MAX;
            }
            if (c + 1 < sz1 && matrix[r][c + 1] != INT_MAX)
            {
                priq.push(make_tuple(matrix[r][c + 1], r, c + 1));
                matrix[r][c + 1] = INT_MAX;
            }
        }
        int ans = std::get<0>(priq.top());
        return ans;
    }

};

int main()
{
//    myvvi vv = {{1,5,9},{10,11,13},{12,13,15}};
//    int k = 8;

    myvvi vv = {{1,3,5},{6,7,12},{11,14,14}};
    int k = 6;          // 11

    LT lt;

    cout<<lt.ltb(vv, k)<<endl;

    return 0;
}
