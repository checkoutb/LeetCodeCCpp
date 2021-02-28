
#include "../header/myheader.h"

class LT1700
{
public:

// D D


//        int count[] = {0, 0}, n = A.size(), k;
//        for (int a : A)
//            count[a]++;
//        for (k = 0; k < n && count[B[k]] > 0; ++k)
//            count[B[k]]--;
//        return n - k;

// 。。 因为每个学生 都会 对 目前的三明治 作出判断，所以 只需要 当 出三明治，出到一个 剩下的学生 都不喜欢的时候，就 结束了。




//Runtime: 4 ms, faster than 74.66% of C++ online submissions for Number of Students Unable to Eat Lunch.
//Memory Usage: 8.6 MB, less than 99.29% of C++ online submissions for Number of Students Unable to Eat Lunch.
// 好像直接就是  学生 和 三明治 的 类型的差距，毕竟queue， 每个学生都会 对 目前第一个三明治
// 不，如果 目前是 0三明治(后续全是1三明治)， 而所有的剩下的学生都喜欢1三明治， 那么。。
// 估计有个非常简单的方法的。
    int lt1700a(vector<int>& students, vector<int>& sandwiches)
    {
        int ans = 0;
        int idx1 = 0;
        int sz1 = students.size();
        for (int i = 0; i < sandwiches.size(); ++i)
        {
            int sand = sandwiches[i];
            int t2 = 0;
            while (sand != students[idx1] && t2 <= sz1)
            {
                idx1 = (idx1 + 1) % sz1;
                t2++;
            }
            if (t2 > sz1)
            {
                break;
            }
            students[idx1] = -1;
//            idx1 = (idx1 + 1) % sz1;
        }
//        while (true)
//        {
//            for (int i)
//        }
        for (int i : students)
        {
            if (i != -1)
                ans++;
        }
        return ans;
    }

};

int main()
{
//    myvi v = {1,1,0,0};
//    myvi s = {0,1,0,1};

    myvi v = {1,1,1,0,0,1};
    myvi s = {1,0,0,0,1,1};

    LT1700 lt;

    cout<<lt.lt1700a(v,s);

    return 0;
}
