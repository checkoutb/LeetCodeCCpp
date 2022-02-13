
#include "../header/myheader.h"

class LT2007
{
public:


// D D



//Runtime: 694 ms, faster than 30.55% of C++ online submissions for Find Original Array From Doubled Array.
//Memory Usage: 144.2 MB, less than 41.79% of C++ online submissions for Find Original Array From Doubled Array.
// N * 2 >= N
    vector<int> lt2007a(vector<int>& changed)
    {
        vector<int> ans;
        if (changed.size() % 2 == 1)
        {
            return ans;
        }
        sort(begin(changed), end(changed));

        map<int, int> map2;
        for (int& n : changed)
        {
            map2[n]++;
        }
        for (map<int, int>::iterator it = begin(map2); it != end(map2); it++)
        {
            if (it->second != 0)
            {
                int t2 = it->first;
                if (map2.count(t2 * 2) && map2[t2 * 2] >= it->second)
                {
                    if (t2 == 0)
                    {
                        for (int i = 0; i < it->second; i += 2)
                            ans.push_back(t2);
                    }
                    else
                    {
                        for (int i = 0; i < it->second; i++)
                            ans.push_back(t2);
                    }
                    map2[t2 * 2] -= it->second;
                }
                else
                {
                    return {};
                }
            }
        }

//        showVectorInt(changed);
//        int sz5 = changed.size() / 2;
//        cout<<sz5;
//        for (int i = 0; i < sz5; i++)
//        {
//            if (changed[i] * 2 != changed[i + sz5])
//            {
//                return ans;
//            }
//        }
//        ans = vector<int>(begin(ans), begin(ans) + sz5);
//        cout<<ans.size()<<endl;
        return ans;
    }

};

int main()
{

    LT2007 lt;

//    myvi v = {1,3,4,2,6,8};
    myvi v = {0,0,0,0};

    myvi ans = lt.lt2007a(v);

    showVectorInt(ans);

    return 0;
}
