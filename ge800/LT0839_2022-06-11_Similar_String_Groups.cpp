
#include "../header/myheader.h"

class LT0839
{
public:

// D D

//class disjoint_set {
//    vector<int> v;
//    int sz;
//public:
//    disjoint_set(int n) {
//        makeset(n);
//    }
//
//    void makeset(int n) {
//        v.resize(n);
//        iota(v.begin(), v.end(), 0);
//        sz = n;
//    }
//
//    int find(int i) {
//        if (i != v[i])
//            v[i] = find(v[i]);
//        return v[i];
//    }
//
//    void join(int i, int j) {
//        int ri = find(i), rj = find(j);
//        if (ri != rj) {
//            v[ri] = rj;
//            sz--;
//        }
//    }
//
//    int size() {
//        return sz;
//    }
//};




//Runtime: 41 ms, faster than 71.31% of C++ online submissions for Similar String Groups.
//Memory Usage: 10.2 MB, less than 76.28% of C++ online submissions for Similar String Groups.
//
    int lt0837a(vector<string>& strs)
    {
        int sz1 = strs.size();
        vector<int> uf(sz1, -1);
        for (int i = 1; i < sz1; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int t2 = ufa(uf, i);
                int t3 = ufa(uf, j);
                if (t2 != t3)
                {
                    if (isSimilar(strs[i], strs[j]))
                    {
                        uf[t2] = t3;
                    }
                }
            }
        }
        int ans = 0;
        for (int i : uf)
            ans += i == -1;
        return ans;
    }

    bool isSimilar(string& s1, string& s2)
    {
        int cnt = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] != s2[i])
                if (cnt++ == 2)
                    return false;
        }
        return cnt == 2 || cnt == 0;
    }

    int ufa(vector<int>& uf, int i)
    {
        return uf[i] == -1 ? i : (uf[i] = ufa(uf, uf[i]));
    }

};

int main()
{

    LT0839 lt;

//    vector<string> vs = {"tars","rats","arts","star"};

    vector<string> vs = {"omv","ovm"};

    cout<<lt.lt0837a(vs)<<endl;

    return 0;
}
