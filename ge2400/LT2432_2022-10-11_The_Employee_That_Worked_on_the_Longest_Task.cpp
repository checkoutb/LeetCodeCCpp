
#include "../header/myheader.h"

class LT2432
{
public:

    // D D


    //elif logs[i][1] - logs[i - 1][1] == Max and res > logs[i][0]:
    //    res = logs[i][0]

    //int len = a[0][1], id = a[0][0];
    //for (int i = 1; i < size(A); i++) {
    //    int curr = A[i][1] - A[i - 1][1];
    //    if (curr > len || curr == len and id > A[i][0])  len = curr, id = A[i][0];
    //}





    // у╗ая
        //10 / 11 / 2022 21:14	Accepted	58 ms	35.5 MB	cpp
        //10 / 11 / 2022 21 : 13	Wrong Answer	N / A	N / A	cpp
        //10 / 11 / 2022 21 : 11	Wrong Answer	N / A	N / A	cpp
        //10 / 11 / 2022 21 : 10	Wrong Answer	N / A	N / A	cpp
        //10 / 11 / 2022 21 : 05	Compile Error	N / A	N / A	cpp
//Runtime: 58 ms, faster than 99.90 % of C++ online submissions for The Employee That Worked on the Longest Task.
//Memory Usage : 35.5 MB, less than 80.06 % of C++ online submissions for The Employee That Worked on the Longest Task.
    int lt2432b(int n, myvvi& logs)
    {
        int mx = logs[0][1];
        vector<int> vi;
        vi.push_back(logs[0][0]);
        for (int i = 1; i < logs.size(); ++i)
        {
            int t2 = logs[i][1] - logs[i - 1][1];
            if (t2 > mx)
            {
                vi.clear();
                vi.push_back(logs[i][0]);
                mx = t2;
            }
            else if (t2 == mx)
            {
                vi.push_back(logs[i][0]);
            }
        }
        sort(begin(vi), end(vi));
        return vi[0];
    }


    // .... error
    int lt2432a(int n, vector<vector<int>>& logs)
    {
        //int arr[505] = { 0 };
        vector<int> arr(n);
        arr[logs[0][0]] += logs[0][1];
        for (int i = 1; i < logs.size(); ++i)
        {
            arr[logs[i][0]] += logs[i][1] - logs[i - 1][1];
        }

        int ans = 0;
        int mx = 0;

        for (int i = 0; i < n; ++i)
        {
            if (arr[i] > mx)
            {
                ans = i;
                mx = arr[i];
            }
        }
        return ans;
    }

};

int main()
{

    LT2432 lt;

    //myvvi vv = { {0,3},{2,5},{0,9},{1,15} };
    //int n = 10;

    int n = 26;
    myvvi vv = { {1,1},{3,7},{2,12},{7,17} };

    cout << lt.lt2432b(n, vv) << endl;

    return 0;
}
