
#include "../header/myheader.h"

class LT2653
{
public:


// D D

// 一共就50个值/槽，暴力就可以了。




// Runtime286 ms
// Beats
// 95.99%
// Memory186.6 MB
// Beats
// 42.65%
    // 2 map
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x)
    {
        map<int, int> map2, map3;       // size <= x, > x
        int sz2 = 0;

        for (int i = 0; i < k - 1; ++i)
        {
            int t2 = nums[i];
            if (t2 < 0)
            {
                // if (sz2 < x)
                {
                    ++map2[t2];
                    ++sz2;
                }
            }
        }
        vector<int> ans;
        for (int i = k - 1; i < nums.size(); ++i)
        {
            int t2 = nums[i];
            balancea1(map2, map3, sz2, x);
            #ifdef __test
            cout<<map2.size()<<"============="<<endl;
            #endif
            if (t2 < 0)
            {
                if (!map2.empty())
                    if (t2 <= map2.rbegin()->first)
                    {
                        ++map2[t2];
                        ++sz2;
                    }
                    else
                        ++map3[t2];
                else if (!map3.empty())
                {
                    if (t2 < map3.begin()->first)
                    {
                        ++map2[t2];
                        ++sz2;
                    }
                    else
                        ++map3[t2];
                }
                else
                {
                    map2[t2] = 1;
                    ++sz2;
                }
            }
            balancea1(map2, map3, sz2, x);
            
            // #ifdef __test
            // cout<<" =============== "<<endl<<i<<endl;
            // for (auto & p : map2)
            // {
            //     cout<<p.first<<":!! "<<p.second<<"\n";
            // }
            // cout<<"\n\n\n";
            // for (auto &p : map3)
            // {
            //     cout<<p.first<<":-- "<<p.second<<"\n";
            // }
            // #endif

            if (sz2 == x)
                ans.push_back(map2.rbegin()->first);
            else
                ans.push_back(0);
            
            t2 = nums[i - k + 1];

            #ifdef __test
            cout<<"  "<<t2<<", "<<i - k + 1<<endl;
            #endif
            if (t2 < 0)
            {
                if (t2 <= map2.rbegin()->first)
                {
                    --sz2;
                    if (map2[t2] == 1)
                    {
                        map2.erase(t2);
                    }
                    else
                    {
                        --map2[t2];
                    }
                }
                else
                {
                    if (map3[t2] == 1)
                    {
                        map3.erase(t2);
                    }
                    else
                    {
                        --map3[t2];
                    }
                }
            }
        }
        return ans;
    }

    void balancea1(map<int, int>& map2, map<int, int>& map3, int& sz2, int x)
    {
        // while (!map2.empty() && map2.rbegin()->second == 0)
        //     map2.erase(map2.rbegin());
        // while (!map3.empty() && map3.begin()->second == 0)
        //     map3.erase(map3.begin());

        while (sz2 < x && !map3.empty())
        {
            if (map3.begin()->second <= (x - sz2))
            {
                map2[map3.begin()->first] += map3.begin()->second;
                sz2 += map3.begin()->second;
                map3.erase(map3.begin());
            }
            else
            {
                map2[map3.begin()->first] += x - sz2;
                map3.begin()->second -= x - sz2;
                sz2 += x - sz2;
            }
        }

        while (sz2 > x)
        {
            if (map2.rbegin()->second <= sz2 - x)
            {
                map3[map2.rbegin()->first] += map2.rbegin()->second;
                sz2 -= map2.rbegin()->second;
                // map2.erase(map2.rbegin());
                map2.erase(std::prev(map2.end()));
            }
            else
            {
                map3[map2.rbegin()->first] += sz2 - x;
                map2.rbegin()->second -= sz2 - x;
                sz2 -= sz2 - x;
            }
        }
    }

};

int main()
{

    LT2653 lt;

    // myvi v = {1,-1,-3,-2,3};
    // int k{3};
    // int x(2);

    // myvi v = {-1,-2,-3,-4,-5};
    // int k = 2;
    // int x{2};

    myvi v = {-3,1,2,-3,0,-3};
    int k = 2;
    int x = 1;

    myvi v2 = lt.getSubarrayBeauty(v,k,x);

    showVectorInt(v2);

    return 0;
}
