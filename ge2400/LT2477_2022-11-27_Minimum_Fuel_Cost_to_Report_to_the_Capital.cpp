
#include "../header/myheader.h"

class LT2477
{
public:





    //Runtime1132 ms
    //    Beats
    //    60.46 %
    //    Memory198.3 MB
    //    Beats
    //    57.61 %
    long long lt2477a(vector<vector<int>>& roads, int seats)
    {
        int sz1 = roads.size();
        vector<vector<int>> vvi(sz1 + 1);

        for (vector<int>& rd : roads)
        {
            vvi[rd[0]].push_back(rd[1]);
            vvi[rd[1]].push_back(rd[0]);
        }

        long long ans = 0;
        dfsa1(vvi, 0, seats, 0, -1, ans);

        return ans;
    }

    // remain seat
    int dfsa1(vector<vector<int>>& vvi, int node, int seats, int depth, int parent, long long& ans)
    {
        long long rem = 0;
        for (int nxt : vvi[node])
        {
            if (nxt == parent)
                continue;

            rem += dfsa1(vvi, nxt, seats, depth + 1, node, ans);
        }

        if (rem == 0)
        {
            ans += depth;
            rem = seats;
        }
        --rem;
        
        if (rem >= seats)
        {
            ans -= rem / seats * depth;
            rem = rem % seats;
        }

        return rem;
    }

};

int main()
{

    LT2477 lt;


    return 0;
}
