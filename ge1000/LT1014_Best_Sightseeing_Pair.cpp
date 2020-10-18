
#include "../header/myheader.h"

class LT1014
{
public:



// a[i]+i+a[j]-j == a[i]+a[j] + (i-x) + (j-x);
// 每次之前出现过的 max - 1。

// gg.... discuss hen jiandan...

    int lt1014c(vector<int>& A)
    {
        int ans = 0;
        map<int, vector<int>> map2;
        map2[-200000].push_back(-1);
        map2[-200001].push_back(-1);
        for (int i = 0; i < A.size(); i++)
        {
            A[i] += i;
            if (A[i] >= (map2.rbegin())->first)
            {
                if (A[i] == map2.rbegin()->first)
                {
                    map2[A[i]].push_back(i);
                }
                else
                {
                    map2[(++map2.rbegin())->first] = map2[(map2.rbegin())->first];
                    map2[A[i]].push_back(i);
                }
            }
            else if (A[i] >= (++map2.rbegin())->first)
            {
                map2[A[i]].push_back(i);
            }
            if (map2.size() > 2)
            {
                map2.erase(map2.begin());
            }
        }
        map<int, vector<int>> map3;
        map3[-222222].push_back(-1);
        map3[-333333].push_back(-1);
        for (int i = 0; i < A.size(); i++)
        {
            A[i] -= i * 2;
            if (A[i] >= map3.rbegin()->first)
            {
                if (A[i] == map3.rbegin()->first)
                {
                    map3[A[i]].push_back(i);
                }
                else
                {
                    map3[(++(map3.rbegin()))->first] = map3[map3.rbegin()->first];
                    map3[A[i]].push_back(i);
                }
            }
            else if (A[i] >= (++map3.rbegin())->first)
            {
//                if (A[i] == (map3.rbegin() + 1)->first)
//                {
//                    map3[A[i]].push_back(i);
//                }
//                else
//                {
                    map3[A[i]].push_back(i);
//                }
            }
            if (map3.size() > 2)
                map3.erase(map3.begin());
        }

        #ifdef __test
        for (auto& p : map2)
        {
            cout<<p.first<<" : ";
            for_each(begin(p.second), end(p.second), fun_cout);
            cout<<endl;
        }
        cout<<" = = "<<endl;
        for (auto& p : map3)
        {
            cout<<p.first<<" - ";
            for_each(begin(p.second), end(p.second), fun_cout);
            cout<<endl;
        }
        #endif // __test

        for (auto& p : map2)
        {
            int t1 = p.first;
            int i1 = p.second[0];
            for (auto& q : map3)
            {
                int t2 = q.first;
                for (int qi : q.second)
                {
                    if (qi > i1)
                    {
                        ans = max(ans, t1 + t2);
                        break;
                    }
                }
            }
        }

        return ans;
    }


// i == i... error
    int lt1014b(vector<int>& A)
    {
        int ans = 0;
//        vector<int> b(A.begin(), A.end());
//        int t1 = 0;
        for (int i = 0; i < A.size(); i++)
        {
            A[i] += i;
            ans = max(A[i], ans);
        }
//        int t1 = std::max_element(begin(A), end(A));
        int t2 = 0;
        for (int i = 0; i < A.size(); i++)
        {
            A[i] -= 2 * i;
            t2 = max(t2, A[i]);
        }

        return ans + t2;
    }


// tle
    int lt1014a(vector<int>& A)
    {
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                ans = max(ans, A[i] + A[j] - j + i);
            }
        }
        return ans;
    }

};

int main()
{

//    vector<int> v = {8,1,5,2,6};
    vector<int> v = {2,2,2};

    LT1014 lt;

    cout<<lt.lt1014c(v)<<endl;

    return 0;
}
