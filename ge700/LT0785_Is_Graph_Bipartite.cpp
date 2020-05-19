
#include "../header/myheader.h"

class LT0785
{
public:


// D D
// 使用 数组，值表示2种颜色。


// 好难写。。。
//Runtime: 72 ms, faster than 13.02% of C++ online submissions for Is Graph Bipartite?.
//Memory Usage: 15.5 MB, less than 7.69% of C++ online submissions for Is Graph Bipartite?.

// 遍历图，第一个度不为0的结点作为一个集合，和第一个结点有边相连的作为第二个集合，和第二个集合中点有边相连的点加入到第一个集合，然后再遍历第一个集合。。。
// 如果一个点即在第一个集合，又在第二个集合。。。return false
    bool lt0785a(vector<vector<int>>& graph)
    {
        set<int> set1;
        set<int> set2;
        set<int>* setp = &set1;
        set<int>* setp2 = &set2;
//        set<int> set4;
        vector<int> v3;

        for (int i = 0, n = graph.size(); i < n; i++)
        {
            if (!graph[i].empty())
            {
//                v3.push_back(i);
//                set4.insert(i);
                v3.insert(v3.begin(), i);
            }
        }

//        v3.reverse();
        while (!v3.empty())
        {
            int t2 = v3.back();
            v3.pop_back();
            set1.clear();
            set2.clear();
            setp = &set1;
            setp2 = &set2;
//            setp->insert(t2);
            set2.insert(t2);
            queue<int> que2;
            que2.push(t2);
            que2.push(-1);
            while (!que2.empty())
            {


                int fnt = que2.front();
//            cout<<"              "<<fnt<<", "<<t2<<endl;
                que2.pop();
                if (fnt != -1)
                {
//                    setp->insert(fnt);
                    for (int ip : graph[fnt])
                    {
                        if (ip > fnt)
                        {
                            que2.push(ip);
//                            v3.erase(ip);

                            for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
                            {
                                if (*it == ip)
                                {
                                    v3.erase(it);
                                    break;
                                }
                            }

                            setp->insert(ip);
                            if (setp2->count(ip))
                            {
//                    cout<<ip<<",    "<<fnt<<", "<<endl;
//
//                    for_each(set1.begin(), set1.end(), fun_cout);
//                    cout<<endl;
//                    for_each(set2.begin(), set2.end(), fun_cout);
//                    cout<<endl;
//                    cout<<(setp2 == &set2)<<" : "<<(setp2 == &set1)<<endl;

                                return false;
                            }
                        }
                    }
                }
                else
                {
                    if (!que2.empty())
                        que2.push(-1);
                    setp = (setp == &set1) ? &set2 : &set1;
                    setp2 = (setp2 == &set1) ? &set2 : &set1;
                }
            }
        }

        return true;
    }

};

int main()
{

//    vector<vector<int>> vv2 = {{1,3},{0,2},{1,3},{0,2}};

    vector<vector<int>> vv2 = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};

    LT0785 lt;

    cout<<lt.lt0785a(vv2)<<endl;

    return 0;
}
