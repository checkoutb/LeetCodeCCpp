
#include "../header/myheader.h"

class LT1560
{
public:

// D D

//        int len = rounds.length, fr = rounds[0], to = rounds[len - 1];
//        List<Integer> res = new ArrayList<>();
//        if (to >= fr) {     // no circle, such as [1,3,1,2]
//            for (int i = fr; i <= to; i++) res.add(i);
//        } else {            // cross a circle, such as [2,3,2,1]
//            for (int i = 1; i <= n; i++) {
//                if (i == to + 1) i = fr;
//                res.add(i);
//            }
//        }


//        for (int i = A[0]; i <= A[A.size() - 1]; ++i)
//            res.push_back(i);
//        if (res.size() > 0) return res;
//        for (int i = 1; i <= A[A.size() - 1]; ++i)
//            res.push_back(i);
//        for (int i = A[0]; i <= n; ++i)
//            res.push_back(i);



//ascending order of sector numbers in the counter-clockwise direction
// ...  逆时针，  但是 [1,3] 是 顺时针啊。。 [3,1]才是 逆时针啊，
// 还是说           sector 是 逆时针，    但是 结果需要 升序？ 。。。

//Runtime: 4 ms, faster than 94.68% of C++ online submissions for Most Visited Sector in a Circular Track.
//Memory Usage: 11.7 MB, less than 14.63% of C++ online submissions for Most Visited Sector in a Circular Track.
// 绕圈的，所以只需要看最后 一圈。
// .. 绕圈，所以 只要看 终点 和 起点，  起点之后，终点之前， 就是 经过最多的。
    vector<int> lt1560a(int n, vector<int>& rounds)
    {

        vector<int> ans;
        for (int i = rounds[0]; i != rounds[rounds.size() - 1]; i = i % n + 1)
            ans.push_back(i);
        ans.push_back(rounds[rounds.size() - 1]);
        std::sort(std::begin(ans), std::end(ans));
        return ans;


//        vector<int> v(n + 1);
//        int mxst = 0;
//        int mx = 0;


//        vector<int> ans;
//
//        for (int i = rounds.size() - 1; i > 0; --i)
//        {
//            if (rounds[i] > rounds[i - 1])
//            {
//                for (int j = rounds[i]; j > rounds[i - 1]; --j)
//                {
//                    ans.push_back(j);
//                }
//            }
//            else
//            {
//                for (int j = rounds[i]; j >= 1; --j)
//                {
//                    ans.push_back(j);
//                }
//                break;
//            }
//        }
//
//        std::reverse(begin(ans), end(ans));
//        return ans;
    }

};

int main()
{

//    myvi v = {1,3,1,2};
//    int n{4};

//    myvi v = {2,1,2,1,2,1,2,1,2};
//    int n{2};

//    myvi v = {1,3,5,7};
//    int n{7};

    myvi v = {3,2,1,2,1,3,2,1,2,1,3,2,3,1};     // 1,3
    int n{3};

    LT1560 lt;

    myvi vi = lt.lt1560a(n, v);
    showVectorInt(vi);

    return 0;
}
