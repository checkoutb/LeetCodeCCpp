
#include "../header/myheader.h"

class LT0947
{
public:

// D
//You probably apply a DFS, from one stone to next connected stone.
//You can remove stones in reversed order.
//In this way, all stones can be removed but the stone that you start your DFS.

// Unify index

// Union-Find

//


// gg...
// remove 最少的
    int lt0947a(vector<vector<int>>& stones)
    {
//        sort(begin(stones), end(stones));
        unordered_map<int, vector<int>> map1;
        unordered_map<int, vector<int>> map2;
        for (int i = 0; i < stones.size(); i++)
        {
            map2[stones[i][1]].push_back(i);
            map1[stones[i][0]].push_back(i);
        }
//        int arr[1001] = {0};
        vector<int> arr(stones.size(), 0);
        for (int i = 0; i < stones.size(); i++)
        {
            arr[i] = map1[stones[i][0]].size() + map2[stones[i][1]].size() - 2;
        }
        int cntmn = INT_MAX;
        int mni = -1;
        int ans = 0;

        #ifdef __test
        cout<<mni<<endl;
        for_each(begin(arr), end(arr), fun_cout);
        cout<<endl;
        #endif // __test

        while (mni != -2)
        {
            mni = -2;
            cntmn = INT_MAX;
            int t2 = 0;
            for (int i = 0; i < arr.size(); i++)
            {
                if (arr[i] <= 0)
                    continue;
                if (arr[i] < cntmn)
                {
                    cntmn = arr[i];
                    mni = i;
                }
                t2++;
            }
            if (t2 == 1)
                break;

            if (mni != -2)
            {
                ans++;
                for (int i : map1[stones[mni][0]])
                {
                    arr[i]--;
                }
                for (int i : map2[stones[mni][1]])
                {
                    arr[i]--;
                }
                arr[mni] = 0;
            }

            #ifdef __test
            cout<<mni<<endl;
            for_each(begin(arr), end(arr), fun_cout);
            cout<<endl;
            #endif // __test

        }
        return ans;
    }


};

int main()
{

//    vector<vector<int>> v = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};

//    vector<vector<int>> v = {{0,0},{0,2},{1,1},{2,0},{2,2}};

//    vector<vector<int>> v = {{0,0}};

    vector<vector<int>> v = {{5,9},{9,0},{0,0},{7,0},{4,3},{8,5},{5,8},{1,1},{0,6},{7,5},{1,6},{1,9},{9,4},{2,8},{1,3},{4,2},{2,5},{4,1},{0,2},{6,5}};


    LT0947 lt;

    cout<<lt.lt0947a(v)<<endl;

    return 0;
}
