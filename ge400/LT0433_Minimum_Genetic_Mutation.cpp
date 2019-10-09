
#include "../header/myheader.h"




// details
// vector<vector<int>>& adj, int i, vector<int>& visited  替代map, set
// 在dfs开头处 gone.add(now)



// discuss
// bfs。。。碰到的第一个就是最少次数的转换。。dfs需要运行完，虽然可以每一步都可能提前退出。
// queue..队头如果==end，return level。每次保存queue.size，只处理这么几个，处理完就是level++。
// 都是，for(8个位置){for(4种嘌呤){每个位置都尝试4种嘌呤(只改了一个char)，看这个string是否存在于bank中。}}




//Runtime: 8 ms, faster than 53.77% of C++ online submissions for Minimum Genetic Mutation.
//Memory Usage: 9.1 MB, less than 25.00% of C++ online submissions for Minimum Genetic Mutation.


// 应该先对bank做个处理，变成map<string, list<string>>。

class LT0433
{
private:
    int temp = INT_MAX;

public:
    lt0433a(string start, string end, vector<string>& bank)
    {
        bank.push_back(start);
        int sz1 = bank.size();

        map<string, set<string>> map2;
        for (int i = 0; i < sz1; i++)
        {
            string str1 = bank[i];
            for (int j = 0; j < sz1; j++)
            {
                if (j == i)
                    continue;
                string str2 = bank[j];
                int diff = 0;
                int k = 0;
                while (diff <=1 && k < 8)
                {
                    diff += (str1[k] != str2[k]);
                    k++;
                }
                if (diff == 1)
                {
//                    if (map2.find(str1) == map2.end())
//                    {
//                        set<string> set1;
//                        map2.insert({str1, set1});
//                    }
                    map2[str1].insert(str2);            // 上面没必要。
                }
            }
        }

        #ifdef __test
        cout<<map2.size()<<endl;
        for (map<string, set<string>>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            cout<<it->first<<" : "<<it->second.size()<<endl;
        }
        #endif // __test

        set<string> set2;
        int ans = dfs(start, end, map2, 0, set2);
        ans = (ans == INT_MAX ? -1 : ans);
        return ans;
    }

    int dfs(string now, string end, map<string, set<string>>& map2, int depth, set<string> gone)
    {
        if (depth >= temp)
            return temp;
        if (now == end)
        {
            if (depth < temp)
                temp = depth;
            return depth;
        }
        int ans = temp;
        for (set<string>::iterator it = map2[now].begin(); it != map2[now].end(); it++)
        {
            if (gone.find(*it) == gone.end())
            {
                gone.insert(*it);
                int t1 = dfs(*it, end, map2, depth + 1, gone);
                gone.erase(*it);
                if (t1 < ans)
                    ans = t1;
            }
        }
        return ans;
    }
};

int main()
{

//    cout<<(int)('A'^'C')<<endl;           // 2

    LT0433 lt;

    string st = "AACCGGTT";
    string end = "AACCGGTA";
    vector<string> bank;
    bank.push_back("AACCGGTA");

    cout<<lt.lt0433a(st, end, bank);

    return 0;
}
