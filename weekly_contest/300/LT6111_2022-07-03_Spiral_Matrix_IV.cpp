
#include "../../header/myheader.h"

class LT6111
{
public:




    // AC
    vector<vector<int>> lta(int m, int n, ListNode* head)
    {
        vector<vector<int>> vvi(m, vector<int>(n, -1));
        int row = 0, col = -1;
        int arr[][2] = { {0,1},{1,0},{0,-1},{-1,0} };
        int dir = 0;
        while (head != nullptr)
        {
            int t2 = head->val;
            head = head->next;

            int tr = row + arr[dir][0];
            int tc = col + arr[dir][1];

            if (tr < 0 || tc < 0 || tr >= m || tc >= n || vvi[tr][tc] != -1)
            {
                dir = (dir + 1) % 4;
                tr = row + arr[dir][0];
                tc = col + arr[dir][1];
            }

            vvi[tr][tc] = t2;
            row = tr;
            col = tc;
        }

        return vvi;
    }

};

int main()
{

    LT6111 lt;

    int m = 3, n = 5;
    int arr[] = { 3,0,2,6,8,1,7,9,4,2,5,5,0 };
    ListNode* r = convertArray(arr);

    myvvi vv = lt.lta(m, n, r);

    for (myvi& vi : vv)
    {
        for (int i : vi)
            cout << i << ", ";
        cout << endl;
    }

    return 0;
}
