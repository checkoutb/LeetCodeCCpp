
#include "../header/myheader.h"

class LT0886
{
public:





// wrong. 49/70
    bool lt0886b(int N, vector<vector<int>>& dislikes)
    {
        vector<int> arr(N + 1, -1);
        map<int, vector<vector<int>>> map2;     // 升序
        for (vector<int>& v : dislikes)
        {
            if (v[0] < v[1])
                map2[v[0]].push_back(v);
            else
                map2[v[1]].push_back({v[1], v[0]});
        }
        unordered_set<int> set1;
        unordered_set<int> set2;
        while (!map2.empty())
        {
            int t2 = map2.begin()->first;
            if (arr[t2] == -1)
            {
                arr[t2] = 0;
            }
            int tag = (arr[t2] + 1) % 2;
            set1.clear();
            set2.clear();
            set1.insert(t2);
            while (!set1.empty())
            {
                for (int i : set1)
                {
                    vector<vector<int>>& vv2 = map2[i];
                    for (vector<int>& v2 : vv2)
                    {
                        int t2 = arr[v2[1]];
                        arr[v2[1]] = tag;
                        if (t2 != -1 && t2 != tag)
                        {
                            return false;
                        }
                        if (t2 == -1)
                        {
                            set2.insert(v2[1]);
                        }
                    }
                    map2.erase(i);          // 会导致数据释放，所以放上面的话，v2里的值全0。
                }
                tag = (tag + 1) % 2;
                set1.clear();
                set1.insert(set2.begin(), set2.end());
                set2.clear();
            }
        }
        return true;
    }


// 应该是不能成 奇数元素个数的环
    bool lt0886a(int N, vector<vector<int>>& dislikes)
    {
        unordered_set<int> set1;
        unordered_set<int> set2;
        unordered_map<int, vector<vector<int>>> map2;
        for (vector<int>& v : dislikes)
        {
            if (v[0] < v[1])
                map2[v[0]].push_back(v);
            else
                map2[v[1]].push_back({v[1], v[0]});
        }
        for (int i = 1; i <= N; i++)
        {
            vector<vector<int>> vv = map2[i];
            unordered_set<int>* seta = nullptr;
//            if (set1)
        }
        return true;
    }

};

int main()
{

//    int n = 4;
//    vector<vector<int>> vv = {{1,2},{1,3},{2,4}};

//    int n = 3;
//    vector<vector<int>> vv = {{1,2},{1,3},{2,3}};

    int n = 5;
    vector<vector<int>> vv = {{1,2},{2,3},{3,4},{4,5},{1,5}};

    LT0886 lt;

    cout<<lt.lt0886b(n, vv)<<endl;

    return 0;
}
