
#include "../../header/myheader.h"

class LT6134
{
public:



// AC... 炸了。。。
    int closestMeetingNode(vector<int>& edges, int node1, int node2)
    {
        if (node1 == node2)
            return node1;
        unordered_map<int, int> map2;

        map2[node1] = 0;
        //map2[node2] = 0;
        int dis = 0;

        while (edges[node1] != -1)
        {
            dis++;
            node1 = edges[node1];
            if (map2.find(node1) == map2.end())
            {
                map2[node1] = dis;
            }
            else
            {
                break;
            }
        }
        dis = 0;
        unordered_map<int, int> map3;
        map3[node2] = 0;
        while (edges[node2] != -1)
        {
            dis++;
            node2 = edges[node2];
            if (map3.find(node2) == map3.end())
                map3[node2] = dis;
            else
                break;
        }

        int ans = -1;
        int mndis = INT_MAX;

        for (auto& p : map2)
        {
            if (map3.find(p.first) != map3.end())
            {
                int t2 = max(p.second, map3[p.first]);
                if ((t2 < mndis))
                {
                    mndis = t2;
                    ans = p.first;
                }
                else if (t2 == mndis)
                {
                    ans = min(ans, p.first);
                }
            }
        }
        return ans;
    }


    // 从 i结点 到 edges[i] 结点 的 有向边。  出度<=1
    // max(distance(node1, x), dis(node2, x)) is min
    // LCA ？ .. md 。。
    int closestMeetingNode_a(vector<int>& edges, int node1, int node2)
    {
        if (node1 == node2)
            return node1;
        unordered_set<int> set2;
        set2.insert(node1);


        int ans = node2;
        int mndis = INT_MAX;
        int cnt = 0;
        int orin1 = node1;

        while (edges[node1] != -1)
        {
            node1 = edges[node1];
            if (set2.find(node1) != set2.end())
                break;
            set2.insert(node1);
            cnt++;
            if (node1 == node2)
            {
                ans = node2;
                mndis = cnt;        // node1 -> ,, node2 's distance
            }
        }

//        if (set2.find(node2) != set2.end())
//            return node2;

        unordered_set<int> set3;
        set3.insert(node2);

        cnt = 0;

        while (edges[node2] != -1)
        {
            node2 = edges[node2];

            cnt++;
            if (set2.find(node2) != set2.end())
            {
                if (node2 != orin1)
                    return node2;

                if (cnt < mndis)
                    return node2;
                if (cnt == mndis)
                    return min(node2, ans);
                if (cnt > mndis)
                    return ans;
            }

            if (set3.find(node2) != set3.end())
                break;
            else
                set3.insert(node2);
        }
        return -1;
    }

};

int main()
{

    LT6134 lt;

//    myvi v = {4,4,4,5,1,2,2};
//    int n1 = 1;
//    int n2 = 1;

//    myvi v = {5,3,1,0,2,4,5};       // 3
//    int n1 = 3;
//    int n2 = 2;


    myvi v = {1,2,-1};      // 2
    int n1 = 0;
    int n2 = 2;

    cout<<lt.closestMeetingNode(v,n1,n2)<<endl;

    return 0;
}
