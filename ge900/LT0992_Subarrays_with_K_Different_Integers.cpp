
#include "../header/myheader.h"

class LT0992
{
public:

// D
//exactly(K) = atMost(K) - atMost(K-1)


// error .. gg
    int lt0992b(vector<int>& A, int K)
    {
        int left = 0;
        int right = 0;
        int right2 = 0;
        int ans = 0;
        unordered_map<int, int> map2;
//        unordered_map<int, int> map3;
        for (int i = 0; i < A.size(); i++)
        {
            map2[A[i]]++;
            if (map2.size() == K)
            {
                int cnt2 = 0;
                int t5 = 0;
                for (; left < A.size(); left++)
                {
                    int t2 = A[left];
                    map2[t2]--;
                    cnt2++;
                    if (map2[t2] == 0)
                    {
                        map2.erase(t2);
                        t5 = t2;
                        map2[t5] = 1;
                        left++;
                        break;
                    }
                }

                int cnt3 = 1;
                for (int j = i; j < A.size(); j++)
                {
                    int t2 = A[j];
                    if (map2[t2] != 0)
                    {
                        cnt3++;
                        map2[t2]++;
                    }
                    else
                    {
                        break;
                    }
                }
                map2.erase(t5);
                #ifdef __test
                cout<<cnt2<<" * "<<cnt3<<endl;
                #endif // __test
                i = left;
                ans += cnt2 * cnt3;
            }
        }
        return ans;
    }


// 41 / 55 . tle
    int lt0992a(vector<int>& A, int K)
    {
        map<int, int> map2;
        int ans = 0;
        for (int i = 0; i < A.size(); i++)
        {
            map2.clear();
            for (int j = i; j < A.size(); j++)
            {
                map2[A[j]]++;
                if (map2.size() == K)
                    ans++;
                else if (map2.size() > K)
                    break;
            }
        }
        return ans;
    }

};

int main()
{

    vector<int> v = {1,2,1,2,3};
    int k = 2;

//    vector<int> v = {1,2,1,3,4};
//    int k = 3;

    LT0992 lt;

    cout<<lt.lt0992b(v, k)<<endl;

    return 0;
}
