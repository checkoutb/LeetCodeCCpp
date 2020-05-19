
#include "../header/myheader.h"

class LT0773
{

    int target = 123450;

public:


// D D
// 用string，而不是vector<vector>
// 数组保存 当string下标x为0时，它可以和谁交换。



//Runtime: 76 ms, faster than 25.07% of C++ online submissions for Sliding Puzzle.
//Memory Usage: 16.8 MB, less than 16.67% of C++ online submissions for Sliding Puzzle.
// 。。
    int lt0773a(vector<vector<int>>& board)
    {
        int t = vvToInt(board);
        if (t == target)
            return 0;
        set<int> done;
        done.insert(t);
        int ans = 0;

        queue<vector<vector<int>>> que1;
        que1.push(board);
        bool flag = true;

        while (!que1.empty())
        {
            vector<vector<int>> vv2 = que1.front();
            que1.pop();

            #ifdef __test
            for (vector<int> v : vv2)
            {
                for (int i : v)
                {
                    cout<<i<<", ";
                }
                cout<<endl;
            }
            cout<<endl;
            #endif // __test


            if (vv2 == board)
            {
                ans++;
                if (!flag && !que1.empty())
                {
                    que1.push(board);
                }
            }

            if (vvToInt(vv2) == target)
                break;

            int i0 = 0;
            int j0 = 0;
            for (; i0 < 2; i0++)
            {
                for (j0 = 0; j0 < 3; j0++)
                {
                    if (vv2[i0][j0] == 0)
                    {
                        goto AAA;
                    }
                }
            }
            AAA:
            if (i0 == 0)
            {
                vector<vector<int>> vvNew(vv2);
                vvNew[i0][j0] = vvNew[i0 + 1][j0];
                vvNew[i0 + 1][j0] = 0;
                t = vvToInt(vvNew);
                if (done.count(t) == 0)
                {
                    que1.push(vvNew);
                    done.insert(t);
                }
            }
            else
            {
                vector<vector<int>> vvNew(vv2);
                vvNew[i0][j0] = vvNew[i0 - 1][j0];
                vvNew[i0 - 1][j0] = 0;
                t = vvToInt(vvNew);
                if (!done.count(t))
                {
                    que1.push(vvNew);
                    done.insert(t);
                }
            }
            if (j0 < 2)
            {
                vector<vector<int>> vvN(vv2);
                vvN[i0][j0] = vvN[i0][j0 + 1];
                vvN[i0][j0 + 1] = 0;
                t = vvToInt(vvN);
                if (!done.count(t))
                {
                    que1.push(vvN);
                    done.insert(t);
                }
            }
            if (j0 > 0)
            {
                vector<vector<int>> vvN(vv2);
                vvN[i0][j0] = vvN[i0][j0 - 1];
                vvN[i0][j0 - 1] = 0;
                t = vvToInt(vvN);
                if (!done.count(t))
                {
                    que1.push(vvN);
                    done.insert(t);
                }
            }
            if (flag)
            {
                flag ^= flag;
                que1.push(board);
            }
        }

        return que1.empty() ? -1 : ans;
    }

    int vvToInt(vector<vector<int>>& vv)
    {
        int ans = 0;
        for (vector<int> v : vv)
        {
            for (int i : v)
            {
                ans *= 10;
                ans += i;
            }
        }
        return ans;
    }

};

int main()
{


    // 412 053, 012 453, 102 453, 120 453, 123 450
//    vector<vector<int>> vv = {{4,1,2}, {5,0,3}};

//    vector<vector<int>> vv = {{1,2,3},{4,0,5}};

    vector<vector<int>> vv = {{1,2,3},{5,4,0}};

    LT0773 lt;

    cout<<lt.lt0773a(vv)<<endl;

    return 0;
}
