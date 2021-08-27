
#include "../header/myheader.h"

class LT0886
{
public:

// D D


//vector<vector<int>> graph(n+1);
//        for(int i =1; i<n+1; i++){
//            if(color[i]==-1){
//                color[i]=0;
//                q.push(i);
//                while(!q.empty()){


// 着色，dfs。

// a graph is bipartite  <=>  不包含奇数长度的环
//              <=> it is 2-colorable




//Runtime: 244 ms, faster than 20.37% of C++ online submissions for Possible Bipartition.
//Memory Usage: 67 MB, less than 50.60% of C++ online submissions for Possible Bipartition.
// 感觉上次也是这样想的， 但是错了。。。 就是 bfs扩展出去。不停的 分组
    bool lt0886a(int n, vector<vector<int>>& dislikes)
    {
        if (dislikes.empty())           // .
            return true;
        vector<int> vi(n + 1);
        unordered_map<int, vector<int>> map2;
        for (int i = 1; i < dislikes.size(); ++i)
        {
            int t2 = dislikes[i][0];
            int t3 = dislikes[i][1];
            map2[t2].push_back(t3);
            map2[t3].push_back(t2);
        }
        vi[dislikes[0][0]] = 1;
        vi[dislikes[0][1]] = 2;
        queue<int> que1;
        que1.push(dislikes[0][0]);
        que1.push(dislikes[0][1]);
        while (true)
        {
            if (que1.empty())           // .
            {
                for (int i = 1; i < vi.size(); ++i)
                {
                    if (vi[i] == 0)
                    {
                        vi[i] = 1;
                        que1.push(i);
                        goto AAA;
                    }
                }
                break;
            }
            AAA:
            int t2 = que1.front();
            que1.pop();
            if (map2.find(t2) != map2.end())
            {
                for (int dis : map2[t2])
                {
                    if (vi[dis] == 0)
                    {
                        vi[dis] = 3 - vi[t2];
                        que1.push(dis);
                    }
                    else if (vi[dis] == vi[t2])
                    {
                        return false;
                    }
//                    if (vi[dis] != 0 && vi[dis] == vi[t2])
//                        return false;
//                    if (vi[idx] )
                }
            }
        }
        return true;
    }

};

int main()
{
//    int n = 4;
//    myvvi vv = {{1,2},{1,3},{2,4}};

//    int n = 3;
//    myvvi vv = {{1,2},{1,3},{2,3}};

//    int n = 5;
//    myvvi vv = {{1,2},{2,3},{3,4},{4,5},{1,5}};

    int n = 5;
    myvvi vv = {{1,2},{3,4},{4,5},{3,5}};       // .... 没有遍历全。。


    LT0886 lt;

    cout<<lt.lt0886a(n, vv)<<endl;

    return 0;
}
