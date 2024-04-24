
#include "../header/myheader.h"

class LT0898
{
public:


    // D D

        // int sz=arr.size();
        // unordered_set<int> st;
        // for(int i=0;i<sz;i++)
        // {
        //     st.insert(arr[i]);
        //     for(int j=i-1;j>=0;j--)
        //     {
        //         if((arr[i]|arr[j])==arr[j])      // .
        //             break;
        //         arr[j]|=arr[i];          // ..
        //         st.insert(arr[j]);
        //     }
        // }
        // return st.size();


        // vector<int> res;
        // int left = 0, right;
        // for (int a: A) {
        //     right = res.size();
        //     res.push_back(a);
        //     for (int i = left; i < right; ++i) {
        //         if (res.back() != (res[i] | a)) {
        //             res.push_back(res[i] | a);
        //         }
        //     }
        //     left = right;
        // }
        // return unordered_set(res.begin(), res.end()).size();


// Runtime
// 422ms
// Beats74.70%of users with C++
// Memory
// 102.36MB
// Beats84.94%of users with C++
    //....
    // ?
    int subarrayBitwiseORs(vector<int>& arr)
    {
        std::unordered_set<int> set2;
        vector<int> vi(arr.size());
        vi[arr.size() - 1] = arr.back();
        for (int i = arr.size() - 2; i >= 0; --i)
        {
            vi[i] = vi[i + 1] | arr[i];
        }

        for (int i = 0; i < arr.size(); ++i)
        {
            int t2 = 0;
            for (int j = i; j < arr.size(); ++j)
            {
                t2 |= arr[j];
                set2.insert(t2);
                if ((t2 & vi[j]) == vi[j])
                {
                    break;
                }
            }
        }

        return set2.size();
    }

};

int main()
{

    LT0898 lt;


    return 0;
}
