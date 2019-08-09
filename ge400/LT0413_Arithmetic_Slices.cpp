
#include "../header/myheader.h"

class LT0413
{


// 至少3个数，并且 按序相减的 差 相同。那就map<diff, list<int>> ?     C5取3. C5取4，+1.，， map无意义。不是 组合。
// 3重for，ijk, if (k - j == j - i) abs.。记录下k的个数n， ans + n - 3 + n-4 + n-5 + n-6.. +1  等差。n-2.
// 不对。n重for。i-j-k-l-m-n。。直接while lower_bound(j+j-i).。。1，2....n-2..

// ...是连续的。。。。


public:



// details
// 基本都是0 or 4s。
//        vector<int> dp(A.size(), 0);
//        for(int i = 2; i < A.size(); i++){
//            if(A[i] - A[i-1] == A[i-1] - A[i-2])
//                dp[i] = dp[i-1] + 1;
//        }
//        int sum = 0;
//        for(int n: dp)
//            sum += n;
//        return sum;

//        int count = 0;
//        int ret = 0;
//        for (int i = 1; i < A.size()-1; i++) {
//            if (A[i] - A[i-1] == A[i+1] - A[i]) {
//                ret += ++count;
//            } else {
//                count = 0;
//            }
//        }
//        return ret;

// A[i] - A[i-1] == A[i+1] - A[i] ...
// count替代了dp的作用。






//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Arithmetic Slices.
//Memory Usage: 8.7 MB, less than 87.64% of C++ online submissions for Arithmetic Slices.

    int lt0413b(vector<int>& A)
    {
        int ans = 0;
        int sz1 = A.size();
        int sz2 = sz1 - 1;

        for (int i = 0; i < sz2; i--)
        {
            int diff = A[i + 1] - A[i];
            int count = 2;
            i++;
            int t1 = A[i] + diff;
            i++;
            while (i < sz1)
            {
                if (t1 == A[i])
                {
                    count++;
                    t1 += diff;
                }
                else
                {
                    break;
                }
                i++;
            }
            if (count >= 3)
            {
                ans += (count - 1) * (count - 2) / 2;
            }
        }

        return ans;
    }


    // wrong..这里是非连续的，即认为{1,2,3,4,5,6}中{2,4,6}符合。实际上是不符合的。
    int lt0413a(vector<int>& A)
    {
        int ans = 0;
        int sz1 = A.size();
        map<int, set<int>> diffIndex;

        int t1 = 0;
        int a1 = 0;
        int c1 = 0;
        for (int i = 0; i < sz1; i++)
        {
            for (int j = i + 1; j < sz1; j++)
            {
                t1 = A[j] - A[i];
                a1 = A[j] + t1;
                int k = j + 1;
                c1 = 0;

                set<int> indexSet = diffIndex[t1];
                if (indexSet.find(i) != indexSet.end() && indexSet.find(j) != indexSet.end())
                    continue;

                while (k < sz1)
                {
                    if (A[k] == a1)
                    {
                        #ifdef __test
                        cout<<A[i]<<", "<<A[j]<<", "<<A[k]<<", "<<t1<<endl;
                        if (indexSet.empty())
                            cout<<"set is empty"<<endl;
                        else
                        {
                            cout<<"set : ";
                            for_each(indexSet.begin(), indexSet.end(), fun_cout);
                            cout<<endl;
                        }
                        #endif // __test

                        c1++;
                        a1 += t1;
                        if (indexSet.empty())
                        {
                            indexSet.insert(i);
                            indexSet.insert(j);
                            indexSet.insert(k);
                        }
                        else
                        {
                            indexSet.insert(k);
                        }
                    }
                    diffIndex[t1] = indexSet;               // .不然这个set加不进去。
                    k++;
                }
                #ifdef __test
                cout<<c1<<endl;
                #endif // __test
                if (c1 != 0)
                {
                    ans += (1 + c1) * c1 / 2;
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> v1 = {1,2,3,4};

//    vector<int> v1 = {1,2,3,4,5,6};

    LT0413 lt;
    cout<<endl<<"result: "<<lt.lt0413b(v1)<<endl;

    return 0;
}
