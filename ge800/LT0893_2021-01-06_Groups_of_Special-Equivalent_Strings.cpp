
#include "../header/myheader.h"

class LT0893
{
public:

// D D

//        string odd, even;
//        for (int i = 0; i < w.size (); ++i) {
//            if (i % 2) even  += w[i];
//            else       odd += w[i];
//        }
//        sort (even.begin (), even.end());
//        sort (odd.begin(), odd.end());
//        s.insert(even +  odd);
// detail 里，10s(最快了) 左右的 都是这种。
// 构建string 已经足够快了，～=不消耗时间。




//Runtime: 76 ms, faster than 7.36% of C++ online submissions for Groups of Special-Equivalent Strings.
//Memory Usage: 15.7 MB, less than 5.02% of C++ online submissions for Groups of Special-Equivalent Strings.
    int lt0893a(vector<string>& A)
    {
        int arr0[123] = {0};
        int arr1[123] = {0};
        unordered_set<string> set2;

        for (string& s : A)
        {
            for (int i = 'a'; i <= 'z'; ++i)
                arr0[i] = arr1[i] = 0;
            for (int i = 0; i < s.size(); ++i)
            {
                if (i % 2 == 0)
                {
                    arr0[s[i]]++;
                }
                else
                {
                    arr1[s[i]]++;
                }
            }
            string key1;
            string key0;
            for (int i = 'a'; i <= 'z'; ++i)
            {
                key0 += (to_string(arr0[i]) + ",");
                key1 += (to_string(arr1[i]) + ",");
            }
            key0 = key0 + "-" + key1;
            set2.insert(key0);
        }

        return set2.size();
    }

};

int main()
{
//    vector<string> vs = {"abcd","cdab","cbad","xyzz","zzxy","zzyx"};
    vector<string> vs = {"abc","acb","bac","bca","cab","cba"};

    LT0893 lt;

    cout<<lt.lt0893a(vs);

    return 0;
}
