
#include "../header/myheader.h"

class LT0454
{
public:


// ... 1.这是map，能直接map[-val]...
// ... 2.第二个for for 里就能直接得到结果了。。
// res += AB[-c - d];


//Runtime: 472 ms, faster than 6.05% of C++ online submissions for 4Sum II.
//Memory Usage: 50.1 MB, less than 9.09% of C++ online submissions for 4Sum II.

    int lt0454a(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
    {
        int ans = 0;
        map<int, int> map1;
        map<int, int> map2;
        int sz1 = A.size();
        int sz2 = B.size();
        int sz3 = C.size();
        int sz4 = D.size();
        for (int i = 0; i < sz1; i++)
            for (int j = 0; j < sz2; j++)
                map1[A[i] + B[j]]++;
        for (int i = 0; i < sz3; i++)
            for (int j = 0; j < sz4; j++)
                map2[C[i] + D[j]]++;

        #ifdef __test
        for (auto p : map1)
            cout<<p.first<<" , "<<p.second<<endl;
        cout<<endl<<endl;
        for (auto p : map2)
            cout<<p.first<<" : "<<p.second<<endl;
        cout<<endl<<endl;
        #endif // __test

        for (map<int, int>::iterator it = map1.begin(); it != map1.end(); it++)
        {
            int val = 0 - it->first;
            int cnt = it->second;

            #ifdef __test
//            cout<<val<<", "<<cnt<<endl;
            #endif // __test

//            map<int, int>::iterator it2 = std::lower_bound(map2.begin(), map2.end(), val, [](auto p1, auto p2) { return p1.first >= p2.first;});

            map<int, int>::iterator it2 = map2.lower_bound(val);

            if (it2 != map2.end() && it2->first == val) {
                ans += (cnt * it2->second);
                #ifdef __test
//                cout<<it2->second<<endl;
                cout<<val<<" , "<<cnt<<" , "<<it2->second<<endl;
                #endif // __test
            }
        }
        return ans;
    }
};

int main()
{
//    vector<int> a = {1,2};
//        vector<int> b = {-2,-1};
//            vector<int> c = {-1,2};
//                vector<int> d = {0,2};


    vector<int> a = {-1,1,1,1,-1};
    vector<int> b = {0,-1,-1,0,1};
    vector<int> c = {-1,-1,1,-1,-1};
    vector<int> d = {0,1,0,-1,-1};              // mine:127    ans:132..... val忘记取反了。



    LT0454 lt;
    cout<<lt.lt0454a(a,b,c,d)<<endl;

    return 0;
}
