
#include "../header/myheader.h"

class LT1642
{
public:

// D D

//        priority_queue<int> pq;
//        for (int i = 0; i < A.size() - 1; i++) {
//            int d = A[i + 1] - A[i];
//            if (d > 0)
//                pq.push(-d);
//            if (pq.size() > ladders) {
//                bricks += pq.top();
//                pq.pop();
//            }
//            if (bricks < 0)
//                return i;
//        }
//        return A.size() - 1;


//        multiset<int> s;
//        for (int i = 0; i < A.size() - 1; i++) {
//            int d = A[i + 1] - A[i];
//            if (d > 0)
//                s.insert(A[i + 1] - A[i]);
//            if (s.size() > ladders) {
//                bricks -= *s.begin();
//                s.erase(s.begin());
//                if (bricks < 0) return i;
//            }
//        }
//        return A.size() - 1;




//Runtime: 276 ms, faster than 37.93% of C++ online submissions for Furthest Building You Can Reach.
//Memory Usage: 64.4 MB, less than 18.63% of C++ online submissions for Furthest Building You Can Reach.
// 保存坑， 优先梯子，梯子用完， 最小的坑用砖头，直到砖头用完
    int lt1642a(vector<int>& heights, int bricks, int ladders)
    {
        multiset<int> mset2;        // or priority_queue  or  heap....
//        int ans = 0;
        int i = 0;
        for (; i < heights.size() - 1; ++i)
        {
            if (heights[i] < heights[i + 1])
            {
                if (ladders > 0)
                {
                    ladders--;
                    mset2.insert(heights[i + 1] - heights[i]);
                }
                else
                {
                    int t2 = mset2.empty() ? INT_MAX : *mset2.begin();
//                    if (t2 <= bricks)
                    if (t2 < (heights[i + 1] - heights[i]))
                    {
                        if (t2 <= bricks)
                        {
                            bricks -= t2;
                            mset2.erase(mset2.begin());
                            mset2.insert(heights[i + 1] - heights[i]);
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        t2 = heights[i + 1] - heights[i];
                        if (t2 <= bricks)
                        {
                            bricks -= t2;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }
        return i;
    }

};

int main()
{
//    myvi v = {4,2,7,6,9,14,12};
//    int a{5}, b{1};

//    myvi v = {4,12,2,7,3,18,20,3,19};
//    int a{10}, b{2};

//    myvi v = {1,2};
//    int a{0}, b{0};

    myvi v = {1,5,1,2,3,4,10000};         // 5
    int a = 4;
    int b = 1;

    LT1642 lt;

    cout<<lt.lt1642a(v,a,b);

    return 0;
}
