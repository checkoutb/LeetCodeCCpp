
#include "../header/myheader.h"


// discuss
// 搜索用二分。
// lower_bound


//Runtime: 128 ms, faster than 28.63% of C++ online submissions for Data Stream as Disjoint Intervals.
//Memory Usage: 30.1 MB, less than 7.69% of C++ online submissions for Data Stream as Disjoint Intervals.


// 并查集。

// 5/9....要求有序。。。duiduidui,,,有序的话，只要和前面/后面比较一下，看是否需要合并。不需要forEach。。
// 这里 无序的原因是 v6 是队尾插入的。需要找一下位置。
class SummaryRanges
{
private:
    vector<vector<int>> intervals;
public:
    SummaryRanges()
    {

    }

    void addNum(int val)
    {
        int t1 = val + 1;
        int t2 = val - 1;
        bool flag = true;
        int flag2 = 0;
        int a = 0;
        for (vector<int> v2 : intervals)
//        for (vector<vector<int>>::iterator it = intervals.begin(); it != intervals.end(); it++)
        {
            if (v2[0] <= t1 && v2[1] >= t2)
            {
                flag = false;
                flag2 = 0;
                if (val < v2[0])
                {
                    flag2 = 1;
//                    v2[0] = val;
                    (*(intervals.begin() + a))[0] = val;
                }
                else if (val > v2[1])
                {
                    flag2 = 2;
                    (*(intervals.begin() + a))[1] = val;
                }

                #ifdef __test
                cout<<"iiiii  "<<a<<", "<<val<<","<<v2[0]<<","<<v2[1]<<endl;
                #endif // __test

                if (flag2 != 0)
                {
                    int t3 = val + (flag2 == 1 ? -1 : 1);
                    flag2 %= 2;
                    int t5 = 0;
                    for (vector<int> v5 : intervals)
                    {
                        if (v5[flag2] == t3)
                        {
//                            v2[(flag2 + 1) % 2] = v5[(flag2 + 1) % 2];

                            (*(intervals.begin() + a))[(flag2 + 1) % 2] = v5[(flag2 + 1) % 2];

                            #ifdef __test
                            cout<<(flag2 + 1) % 2<<endl;
                            cout<<v2[(flag2 + 1) % 2]<<endl;
                            #endif // __test

                            intervals.erase(intervals.begin() + t5);
                            break;
                        }
                        t5++;
                    }
                }
                return;
            }
            a++;
        }
        vector<int> v6;
        v6.push_back(val);
        v6.push_back(val);
        vector<vector<int>>::iterator it = intervals.begin();
        while (it != intervals.end() && (*it)[0] < val)
        {
            it++;
        }
        intervals.insert(it, v6);
    }

    vector<vector<int>> getIntervals()
    {
        return this->intervals;
    }
};

int main()
{
    int arr[] = {3, 1, 7, 2, 6};

    SummaryRanges lt;

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        lt.addNum(arr[i]);
        vector<vector<int>> vv = lt.getIntervals();
        cout<<"i : "<<i<<", ";
        for (vector<int> v : vv)
        {
            cout<<", ";
            for_each(v.begin(), v.end(), fun_cout);
        }
        cout<<endl;
    }

    cout<<endl<<endl<<endl;

    vector<int> v4 = {1,2,3};
    vector<vector<int>> vv4 = {v4};

    for (vector<int> v3 : vv4)
    {
        v3[1] = 1000;           // 擦，没用的。。。。
    }

    for_each(vv4[0].begin(), vv4[0].end(), fun_cout);

    int i = 0;
    for (vector<int> v3 : vv4)
    {
        if (i = 1)
            (*(vv4.begin()))[1] = 222;          // ok
        i++;
    }
    cout<<endl;
    for_each(vv4[0].begin(), vv4[0].end(), fun_cout);

    for (vector<vector<int>>::iterator it = vv4.begin(); it != vv4.end(); it++)
    {
        vector<int> v3 = *it;
        v3[1] = 333;            // 没用,,是不是 v3是一个局部变量。。
        v3 = {12,3};
    }
    cout<<endl;
    for_each(vv4[0].begin(), vv4[0].end(), fun_cout);


    return 0;
}
