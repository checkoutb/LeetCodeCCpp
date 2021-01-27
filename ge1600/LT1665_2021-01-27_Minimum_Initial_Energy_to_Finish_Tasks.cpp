
#include "../header/myheader.h"

class LT1665
{
public:

// D D

//        for (auto &a : A)
//            a[0] = a[1] - a[0];
//        sort(A.begin(), A.end());
//        for (auto &a : A)
//            res = max(res + a[1] - a[0], a[1]);


//    sort(begin(tasks), end(tasks), [](vector<int> &t1, vector<int> &t2)
//         { return t1[1] - t1[0] > t2[1] - t2[0]; });
//    for (auto &t : tasks) {
//        res += max(0, t[1] - energy);
//        energy = max(energy, t[1]) - t[0];
//    }




//Runtime: 476 ms, faster than 87.22% of C++ online submissions for Minimum Initial Energy to Finish Tasks.
//Memory Usage: 93.3 MB, less than 89.47% of C++ online submissions for Minimum Initial Energy to Finish Tasks.
    int lt1665b(vector<vector<int>>& tasks)
    {
        std::sort(begin(tasks), end(tasks), [](const vector<int>& v1, const vector<int>& v2)
        {
            int d1 = v1[1] - v1[0];
            int d2 = v2[1] - v2[0];
            return d1 == d2 ? v1[1] < v2[1] : d1 > d2;
        });
        #ifdef __test
        for (myvi& vi : tasks)
            cout<<vi[0]<<" : "<<vi[1]<<endl;
        #endif // __test
        int ans = 0;
        int remain = 0;
        for (int i = 0; i < tasks.size(); ++i)
        {
            if (remain < tasks[i][1])
            {
                ans += (tasks[i][1] - remain);
                remain = tasks[i][1];
            }
            remain -= tasks[i][0];
        }
        return ans;
    }


// error
    int lt1665a(vector<vector<int>>& tasks)
    {
        std::sort(begin(tasks), end(tasks), [](const vector<int>& v1, const vector<int>& v2) { return v1[1] == v2[1] ? v1[0] < v1[0] : v1[1] > v2[1]; });
        #ifdef __test
        for (myvi& vi : tasks)
        {
            cout<<vi[0]<<" : "<<vi[1]<<endl;
        }
        #endif // __test
        int ans = 0;
        int remain = 0;
        for (int i = 0; i < tasks.size(); ++i)
        {
            if (remain < tasks[i][1])
            {
                ans += (tasks[i][1] - remain);
                remain = tasks[i][1];
            }
            remain -= tasks[i][0];
        }
        return ans;
    }

};

int main()
{
//    myvvi vv = {{1,2},{2,4},{4,8}};
//    myvvi vv = {{1,3},{2,4},{10,11},{10,12},{8,9}};
    myvvi vv = {{1,7},{2,8},{3,9},{4,10},{5,11},{6,12}};

    LT1665 lt;

    cout<<lt.lt1665b(vv);

    return 0;
}
