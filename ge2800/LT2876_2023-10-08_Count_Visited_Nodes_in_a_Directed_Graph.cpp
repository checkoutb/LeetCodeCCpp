
#include "../header/myheader.h"

class LT2876
{
public:





//Runtime365 ms
//Beats
//48.50%
//Memory145.4 MB
//Beats
//98.70%
    // 2 circle...
    vector<int> countVisitedNodes(vector<int>& edges)
    {
        int sz1 = edges.size();
//        vector<int> vi(sz1, 0);
        vector<bool> vst(sz1, false);
        vector<int> ans(sz1, 0);
        vector<bool> vb(vst.size(), false);
        for (int i = 0; i < sz1; ++i)
        {
            if (vst[i] == false)
            {
                circlea1(vst, edges, i, vb, ans);
            }
        }

        #ifdef __test
        showVectorInt(ans);
        #endif // __test

        for (int i = 0; i < sz1; ++i)
        {
            if (ans[i] == 0)
            {
                dfsa1(edges, i, ans);
            }
        }
        return ans;
//        int sz1
//        vector<bool> vst()
    }

    void circlea1(vector<bool>& vst, vector<int>& edges, int node, vector<bool>& vb, vector<int>& ans)
    {
        std::fill(begin(vb), end(vb), false);

//        vector<bool> vb(vst.size(), false);       // memory limit exceeded ... ?

        int circle = -1;

        while (vb[node] == false)
        {
            if (vst[node])
            {
                if (vb[node] == false)
                    return;
            }
            vst[node] = true;
            vb[node] = true;
            node = edges[node];
        }
        circle = node;

//        for (int i = 0; i < vst.size(); ++i)
//        {
//            if (vst[i])
//            {
//                for (int i = 0; i < vst.size(); ++i)
//                {
//                    if (vb[i])
//                    {
//                        #ifdef __test
//                        cout<<i<<" -1- "<<endl;
//                        #endif // __test
//                        vst[i] = true;
//                    }
//                }
//                return;
//            }
//
//            if (vb[edges[i]])
//            {
//                circle = edges[i];
//                break;
//            }
//            else
//            {
//                vb[edges[i]] = true;
//            }
//        }

        for (int i = 0; i < vst.size(); ++i)
        {
            if (vb[i])
            {
                #ifdef __test
                cout<<i<<" -2- "<<endl;
                #endif // __test
                vst[i] = true;
            }
        }

        if (circle == -1)
            circle = node;

        #ifdef __test
        cout<<circle<<endl;
        #endif // __test

        int circle_cnt = 1;
        int t2 = edges[circle];
        while (t2 != circle)
        {
            ++circle_cnt;
            t2 = edges[t2];
        }

        ans[circle] = circle_cnt;
        t2 = edges[circle];
        while (t2 != circle)
        {
            ans[t2] = circle_cnt;
            t2 = edges[t2];
        }
    }

    int dfsa1(vector<int>& edges, int node, vector<int>& ans)
    {
        if (ans[node] != 0)
            return ans[node];

        int t2 = dfsa1(edges, edges[node], ans);
        ++t2;
        ans[node] = t2;
        return t2;
    }

//    int dfsa1()

};

int main()
{

    LT2876 lt;

//    myvi v = {1,2,0,0};

//    myvi v = {1,2,3,4,0};

    myvi v = {6,3,6,1,0,8,0,6,6};

    myvi v2 = lt.countVisitedNodes(v);

    showVectorInt(v2);

    return 0;
}
