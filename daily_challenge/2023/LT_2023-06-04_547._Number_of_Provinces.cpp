
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        std::vector<int> visited(n, 0);
//        int groupCount = 0;
//        for (int i = 0; i < n; ++i)
//        {
//            if (visited[i])
//                continue;
//            ++groupCount;
//            std::stack<int> st;
//            st.push(i);
//
// 没有访问过，那么就++， 然后把所有连接点都访问掉。





//Runtime28 ms
//Beats
//51.98%
//Memory13.6 MB
//Beats
//87.38%
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int sz1 = isConnected.size();
        vector<int> uf(sz1, -1);
        int a, b;
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = i + 1; j < sz1; ++j)
            {
                if (isConnected[i][j] == 0)
                    continue;
                a = ufa(uf, i);
                b = ufa(uf, j);
                if (a != b)
                {
                    uf[a] = b;
                }
            }
        }
        int ans = 0;
        for (int i : uf)
            ans += i == -1;
        return ans;
    }

    int ufa(vector<int>& uf, int idx)
    {
        return uf[idx] == -1 ? idx : (uf[idx] = ufa(uf, uf[idx]));
    }

};

int main()
{

    LT lt;


    return 0;
}
