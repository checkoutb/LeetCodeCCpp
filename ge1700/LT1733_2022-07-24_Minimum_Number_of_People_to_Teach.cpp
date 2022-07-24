
#include "../header/myheader.h"

class LT1733
{
public:

    // D D




//Runtime: 543 ms, faster than 48.11% of C++ online submissions for Minimum Number of People to Teach.
//Memory Usage: 59.8 MB, less than 96.23% of C++ online submissions for Minimum Number of People to Teach.
// ....
// 朋友关系已经确定了， 但是他们 语言不通，    你可以选择一种语言， 教给 某些 人，  使得，所有 有朋友关系的 都可以 互相交流。
// 朋友的朋友 不是朋友， 不需要交流。  所以只是一层关系。
// 应该是找到所有 语言不通的 朋友，  的 人 的 set， 然后 看 里面 会的最多的语言 是哪种， 就教哪种。
    int lt1733a(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships)
    {
        int sz1 = languages.size();     // person
        int ans = 0;

        unordered_set<int> set2;

        for (vector<int>& vi : languages)
        {
            sort(begin(vi), end(vi));
        }

        for (vector<int>& frd : friendships)
        {
            if (!canIntersection(languages[frd[0] - 1], languages[frd[1] - 1]))
            {
                set2.insert(frd[0] - 1);
                set2.insert(frd[1] - 1);
            }
        }

        vector<int> vi(n + 1);

        for (int i : set2)
        {
            for (int lang : languages[i])
            {
                vi[lang]++;
            }
        }

        int cnt = 0;

        for (int i = 1; i <= n; ++i)
        {
            if (vi[i] > cnt)
            {
                cnt = vi[i];
            }
        }

        ans = set2.size() - cnt;

        return ans;
    }

    bool canIntersection(vector<int>& v1, vector<int>& v2)
    {
        int st1 = 0;
        int st2 = 0;

        #ifdef __test
        cout<<v1.size()<<" - "<<v2.size()<<endl;
        #endif // __test

        while ((st1 < v1.size()) && (st2 < v2.size()))
        {
            if (v1[st1] == v2[st2])
                return true;
            else if (v1[st1] > v2[st2])
            {
                st2++;
            }
            else
                st1++;
        }

        return false;
    }

};

int main()
{

    LT1733 lt;

//    int n = 2;
//    myvvi vv = {{1},{2},{1,2}};
//    myvvi vv2 = {{1,2},{2,3},{1,3}};

    int n = 3;
    myvvi vv = {{2},{1,3},{1,2},{3}};
    myvvi vv2 = {{1,4},{1,2},{3,4},{2,3}};

    cout<<lt.lt1733a(n, vv, vv2)<<endl;

    return 0;
}
