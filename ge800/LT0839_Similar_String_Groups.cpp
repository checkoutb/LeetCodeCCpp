
#include "../header/myheader.h"

class LT0839
{
public:


// D

// 慢在v2这个数据结构，基本都是for{for{isSimilar}}的

class disjoint_set {
    vector<int> v;
    int sz;
public:
    disjoint_set(int n) {
        makeset(n);
    }

    void makeset(int n) {
        v.resize(n);
        iota(v.begin(), v.end(), 0);
        sz = n;
    }

    int find(int i) {
        if (i != v[i])
            v[i] = find(v[i]);
        return v[i];
    }

    void join(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri != rj) {
            v[ri] = rj;
            sz--;
        }
    }

    int size() {
        return sz;
    }
};

// 另一种：
int[] parent = new int[n];

private int find(int[] a, int x) {
    if (a[x] != x) {
        a[x] = find(a, a[x]);
    }
    return a[x];
}

// 看i,j2个下标的find返回值是否相等。 ！！
//        if (p1 != p2) {
//            parent[p2] = p1;
//        }
//
//        for (int i = 0; i < n; i++) {
//            if (parent[i] == i) res++;
//        }




// 59 / 63 . tle
    // same length and are anagrams
    int lt0839a(vector<string>& A)
    {
        vector<int> v2(A.size(), 0);
        for (int i = 0; i < v2.size(); i++)
        {
            v2[i] = i;
        }
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                if (isSimilarity(A[i], A[j]))
                {
                    if (v2[j] != j)
                    {
                        int t2 = v2[j];
                        int t3 = v2[i];
                        for (int k = 0; k < A.size(); k++)
                        {
                            if (v2[k] == t2)
                                v2[k] = t3;
                        }
                    }
                    v2[j] = v2[i];
                }
            }
        }
        #ifdef __test
        for_each(begin(v2), end(v2), fun_cout);
        cout<<endl;
        #endif // __test
        unordered_set<int> set2(v2.begin(), v2.end());
//        set2.erase(0);
        return set2.size();
    }

    bool isSimilarity(string s1, string s2)
    {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                diff++;
                if (diff > 2)
                    return false;
            }
        }
        return true;
    }

};

int main()
{

    vector<string> vv = {"tars","rats","arts","star"};

    LT0839 lt;

    cout<<lt.lt0839a(vv)<<endl;

    return 0;
}
