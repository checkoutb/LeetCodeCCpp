
#include "../../header/myheader.h"

class LT
{
public:



// gg
// i * gcd

    // 0 not chose , 1 chosen
    // status, score
    int lta(vector<int>& nums)
    {
        sort(begin(nums), end(nums));
        int sz1 = nums.size();
        int sz2 = (1 << sz1);
        vector<int> vi(sz2, 0);
        vector<pair<int, int>> vp = {{0,0}};
        vector<bool> vb(sz1, false);
        while (!vp.empty())
        {
//            vector<pair<int, int>> vp2;
//            std::fill(begin(vb), end(vb), false);

            unordered_map<int, int> map2;

            for (int i = 0; i < vp.size(); ++i)
            {
                int stt = vp[i].first;
                int scr = vp[i].second;

                for (int m = 0; m < sz1 - 1; ++m)
                {
                    if ((stt & (1 << m)) != 0)
                        continue;

                    for (int n = m + 1; n < sz1; ++n)
                    {
                        if ((stt & (1 << n)) != 0)
                            continue;
                        int t3 = scr + gcda1(nums[n], nums[m]);     // score
                        int t2 = stt | (1 << m) | (1 << n);     // new status
                        if (t3 > vi[t2])
                        {
                            map2[t2] = t3;
                            vi[t2] = t3;
                        }
                    }
                }
            }
            vp.clear();
            for (auto& [k, v] : map2)
            {
                vp.push_back(std::make_pair(k, v));
            }

            #ifdef __test
            for (auto& [k, v] : vp)
            {
                cout<<k<<" - "<<v<<endl;
            }
            cout<<" ------------------- "<<endl;
            #endif // __test

//            swap(vp, vp2);
        }

        #ifdef __test
        showVectorInt(vi);
        #endif // __test

        return vi[sz2 - 1];
    }

    int gcda1(int a, int b)
    {
        if (b == 0)
            return a;
        return gcda1(b, a % b);
    }


};

int main()
{

    LT lt;

    myvi v = {3,4,6,8};

    cout<<lt.lta(v)<<endl;

    return 0;
}
