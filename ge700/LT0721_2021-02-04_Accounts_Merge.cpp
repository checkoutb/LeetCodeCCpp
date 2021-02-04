
#include "../header/myheader.h"

class LT0721
{
public:

// D D

//1.Union Find，2.Graph + BFS，3.Graph + DFS



//Runtime: 88 ms, faster than 94.35% of C++ online submissions for Accounts Merge.
//Memory Usage: 33.7 MB, less than 87.68% of C++ online submissions for Accounts Merge.
    vector<vector<string>> lt0721b(vector<vector<string>>& accounts)
    {
        unordered_map<string, int> map2;
        vector<int> uf(accounts.size());
        for (int i = 0; i < uf.size(); ++i)
            uf[i] = i;
        for (int i = 0; i < accounts.size(); ++i)
        {
            vector<int> vi;
            for (int j = 1; j < accounts[i].size(); ++j)
            {
                if (map2.find(accounts[i][j]) != map2.end())
                {
                    vi.push_back(map2[accounts[i][j]]);
                }
                map2[accounts[i][j]] = i;
            }
            for (int m = 0; m < vi.size(); ++m)
            {
                int t1 = ufb(uf, i);
                int t2 = ufb(uf, vi[m]);
                if (t1 != t2)
                {
                    uf[t2] = t1;
                }
            }
        }
        unordered_map<int, vector<int>> map3;
        for (int i = 0; i < uf.size(); ++i)
        {
            int row = ufb(uf, i);
            map3[row].push_back(i);
        }
        vector<vector<string>> ans;
        for (unordered_map<int, vector<int>>::iterator it = map3.begin(); it != map3.end(); it++)
        {
            string name = accounts[it->first][0];
            set<string> set2;
            for (int i : it->second)
            {
                for (int j = 1; j < accounts[i].size(); ++j)
                {
                    set2.insert(accounts[i][j]);
                }
            }
            vector<string> vs = {name};
            vs.insert(end(vs), begin(set2), end(set2));
            ans.push_back(vs);
        }
        return ans;
    }

    int ufb(vector<int>& uf, int i)
    {
        if (uf[i] == i)
            return i;
        int ans = ufb(uf, uf[i]);
        uf[i] = ans;
        return ans;
    }


// error
// 相同的邮箱地址，人名必然相同，    人名相同!=邮箱连接
// 名字无所额，可以用行数代替。邮箱是唯一的，不可能 出现相同名字，不同邮箱。
// union-find,  后来感觉 floyd ？ 每点对间路径。
    vector<vector<string>> lt0721a(vector<vector<string>>& accounts)
    {
        unordered_map<string, vector<int>> map2;
        for (int i = 0; i < accounts.size(); ++i)
        {
            for (int j = 1; j < accounts[i].size(); ++j)
            {
                map2[accounts[i][j]].push_back(i);
            }
        }
        vector<int> vi(accounts.size());
        for (int i = 0; i < vi.size(); ++i)
            vi[i] = i;
//        for (int i = 0; i < vi.size(); ++i)
//        {
//            int mni = map2[accounts[i][1]][0];
//        }
//        for (unordered_map<string, vector<int>>::iterator it = map2.begin(), it != map2.end(); it++)
//        {
//            vector<int>& vi = it->second;
//
//        }
        for (int i = 0; i < vi.size(); ++i)
        {
            int mni = INT_MAX;
            vector<string>& vs = accounts[i];
            vector<int> vi2;
            for (int j = 1; j < vs.size(); ++j)
            {
                vi2.insert(end(vi2), begin(map2[vs[j]]), end(map2[vs[j]]));
            }

        }

    }


};

int main()
{

    vector<vector<string>> vvs = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"},
    {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};

    LT0721 lt;

    vector<vector<string>> ans = lt.lt0721b(vvs);
    for (vector<string>& vs : ans)
    {
        for (string& s : vs)
            cout<<s<<", ";
        cout<<endl;
    }

    return 0;
}
