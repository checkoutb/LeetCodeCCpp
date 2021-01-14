
#include "../header/myheader.h"

class LT0519
{
public:



};

// D D

//        int idx = rand() % num;
//        int val = idx;
//        num--;
//        if(hit.find(idx) != hit.end()) idx = hit[idx];
//        hit[val] = hit.find(num) == hit.end() ? num : hit[num];
//        return {idx/c, idx%c};


//        while(true) {
//            int k = rand() % (r*c);
//            if(f.count(k)) continue;
//            f.insert(k);
//            int x = k/c, y = k%c;
//
//            return vector<int>{x, y};
//        }


//        int rd;
//        while (true) {
//            rd = rand() % m_size;
//            if (m_visited.count(rd) == 0) { break; }
//        }
//        m_visited.insert(rd);
//        return {rd / m_cols, rd % m_cols};

//    public int[] flip() {
//        int r = rand.nextInt(total--);
//        int x = map.getOrDefault(r, r);
//        map.put(r, map.getOrDefault(total, total));
//        return new int[]{x / cols, x % cols};
//    }


//Runtime: 76 ms, faster than 5.19% of C++ online submissions for Random Flip Matrix.
//Memory Usage: 19.2 MB, less than 97.04% of C++ online submissions for Random Flip Matrix.
// will not exceed 1000.   稀疏矩阵。
class Solution {
    vector<vector<int>> vv;
    int mod;
    int oriMod;
    int cols;
public:
    Solution(int n_rows, int n_cols) {
        vv = vector<vector<int>>(n_rows, vector<int>());
        mod = n_rows * n_cols;
        oriMod = mod;
        cols = n_cols;
    }

    vector<int> flip() {
        #ifdef __test
//        cout<<"========start"<<endl;
//        for (myvi& v : vv)
//        {
//            for (int& i : v)
//            {
//                cout<<i<<", ";
//            }
//            cout<<endl;
//        }
//        cout<<"========end"<<endl;
        #endif // __test
        int idx = rand() % mod;
        mod--;
        cout<<idx<<endl;
        for (int i = 0; i < vv.size(); ++i)
        {
//            cout<<idx<<endl;
            if ((cols - vv[i].size()) > idx)
            {
//                cout<<". . "<<idx<<endl;
                // idx + count of not 0
//                if (idx == 0 && )
//                {
//
//                }
                for (int j = 0; j <= vv[i].size(); ++j)
                {
                    if (j != vv[i].size() && idx >= vv[i][j])
                    {
                        idx++;
                    }
                    else
                    {
                        vv[i].insert(begin(vv[i]) + j, idx);
                        #ifdef __test
                        cout<<i<<", "<<idx<<endl;
                        #endif // __test
                        return {i, idx};
                    }
                }
            }
            else
            {
                idx -= (cols - vv[i].size());
            }
        }
        #ifdef __test
        cout<<"errrrrrrrror"<<endl;
        #endif // __test
        return {-1,-1};
    }

    void reset() {
        for (int i = 0; i < vv.size(); ++i)
            if (!vv[i].empty())
                vv[i].clear();
        mod = oriMod;
    }
};

int main()
{
    myvi v = {1,2,3};
    v.clear();
    cout<<v.size()<<endl;

    Solution sol(2,3);
//    vector<int> vi = sol.flip();
//    cout<<vi[0]<<", "<<vi[1];
//    vi = sol.flip()

    sol.flip();
    sol.flip();
    sol.flip();
    sol.flip();
    sol.flip();
    sol.flip();

    LT0519 lt;


    return 0;
}
