
#include "../header/myheader.h"

class LT1409
{
public:

// D D


// Fenwick Tree
// budong.

// 但是看到 树状数组 这名字，，， 想到能不能 2个数组，一个是 1-m， 一个是 下标。 等于 数组实现链表。这样速度快一点，不需要删除，push，只需要修改 第二个数组。


//Runtime: 12 ms, faster than 89.99% of C++ online submissions for Queries on a Permutation With Key.
//Memory Usage: 8.8 MB, less than 51.90% of C++ online submissions for Queries on a Permutation With Key.
    vector<int> lt1409a(vector<int>& queries, int m)
    {
        vector<int> v(m);
        for (int i = 0; i < m; ++i)
        {
            v[i] = m - i;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i)
        {
            int qidx = 0;
            for (; qidx < m; qidx++)
            {
                if (v[qidx] == queries[i])
                    break;
            }
            ans[i] = (v.size() - 1 - qidx);
            v.erase(begin(v) + qidx);
            v.push_back(queries[i]);
        }
        return ans;
    }

};

int main()
{

//    vector<int> qv = {3,1,2,1};
//    int m{5};

//    vector<int> qv = {4,1,2,2};
//    int m{4};

    vector<int> qv = {7,5,5,8,3};
    int m{8};

    LT1409 lt;

    vector<int> ans = lt.lt1409a(qv, m);
    showVectorInt(ans);

    return 0;
}
