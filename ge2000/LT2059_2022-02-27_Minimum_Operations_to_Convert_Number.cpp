
#include "../header/myheader.h"

class LT2059
{
public:

// D D

//deque<pair<int,int>> Q;
//vector<bool> M(1001,false);
//Q.push_back(pair<int,int>(start,0));


//    vector<int> q{goal};
//    while (!q.empty()) {
//        ++cnt;
//        vector<int> q1;
//        for (auto x : q)
//            for (int n : nums)
//                for (int xn : {x + n, x - n, x ^ n})
//                    if (xn >= 0 && xn <= 1000 && !seen[xn]) {
//                        if (xn == start)
//                            return cnt;
//                        seen[xn] = true;
//                        q1.push_back(xn);
//                    }
//        swap(q, q1);
//    }


//Runtime: 41 ms, faster than 96.06% of C++ online submissions for Minimum Operations to Convert Number.
//Memory Usage: 8.9 MB, less than 97.10% of C++ online submissions for Minimum Operations to Convert Number.
    int lt2059a(vector<int>& nums, int start, int goal)
    {
        if (start == goal)
            return 0;
        int arr[1001] = {0};            // step to get index(value)
//        int ans = -1;
        queue<int> que1;
        que1.push(start);
        while (!que1.empty())
        {
            int t2 = que1.front();
            que1.pop();
            int t3 = -1;
            for (int n : nums)
            {
                t3 = n + t2;
                if (t3 == goal)
                    return arr[t2] + 1;
                if (t3 <= 1000 && t3 >= 0 && arr[t3] == 0 && t2 != t3)
                {
                    arr[t3] = arr[t2] + 1;
                    que1.push(t3);
                }

                t3 = t2 - n;
                if (t3 == goal)
                    return arr[t2] + 1;
                if (t3 <= 1000 && t3 >= 0 && arr[t3] == 0 && t2 != t3)
                {
                    arr[t3] = arr[t2] + 1;
                    que1.push(t3);
                }

                t3 = t2 ^ n;
//                if (n == 35)
//                    cout<<t3<<", "<<t2<<", "<<arr[t2]<<endl;
                if (t3 == goal)
                    return arr[t2] + 1;
                if (t3 <= 1000 && t3 >= 0 && arr[t3] == 0 && t2 != t3)
                {
                    arr[t3] = arr[t2] + 1;
                    que1.push(t3);
                }
            }
        }
        return -1;
    }

};

int main()
{

    LT2059 lt;

    myvi v = {
    336

    ,0,

    17,-956,492,789,453,-10,-108,366,-617,-553,-640,250,-256,-544,274,
    253,732,-156,-703,699,-234,-439,-280,-805,-449,-828,-368,-109,-203,-199,-516,-647,
    -772,63,52,-441,949,-317,35,881,-583,-763,-239,-396,-600,540,-307,-83,-5,29,215,999,
    828,-194,443,339,438,-581,960,-409,-900,-951,-552,844,643,-562,-202,805,91,249,-765,
    -788,-26,458,-285,688,267,-533,-251,-513,-642,-560,-908,-769,770,-192,14,176,925,-791,
//    -174,384,-177,-741,-438,-555,-21,-509,-325,251,471,591,-623,816,-795,212,356,410,21,-800,
//    -494,-7,-60,-993,191,-110,-798,879,-11,-230,130,382,-853,730,99,-312,16,332,-762,825,-814,
//    -340,432,-206,-187,508,-863,648,425,161,236,-221,-995,-81,-164,459,-446,-751,863,159,-246,
//    304,633,875,-541,-65,778,-604,731,184,-817,-427,506,-940,-148
    };
    int st = 870;
    int g = 837;            // 1

    // -33, 33
//    cout<<(870 ^ 837)<<endl;
//    cout<<(870 ^ 35)<<endl;

    cout<<lt.lt2059a(v, st, g);

    return 0;
}
