
#include "../header/myheader.h"

class LT1718
{
public:

// D D


//        int len = 2*n-1;
//        vector<int> ans(2*n-1);
//        function<bool(int, int)> dfs=[&](int i, int s){
//            if(i==len){ return true;}
//            if(ans[i]) return dfs(i+1, s);
//            for(int d=n;d>0;--d){
//                int j = i + (d==1?0:d);
//                if( j>=len || s & (1<<d) || ans[j]) continue;
//                ans[i] = ans[j] = d;
//                if(dfs(i+1, s|(1<<d))) return true;
//                ans[i] = ans[j] = 0;
//            }
//            return false;
//        };
//        dfs(0,0);
//        return ans;


//vector<int> dfs(vector<int> &nums, vector<int> &arr, int p) {
//    if (p == arr.size())
//        return arr;
//    if (arr[p] != 0)
//        return dfs(nums, arr, p + 1);
//    for (int i = nums.size() - 1; i >= 1; --i) {
//        int dist = i == 1 ? 0 : i;
//        if (nums[i] != 0 && dist + p < arr.size() && arr[dist + p] == 0) {
//            arr[p] = arr[p + dist] = i;
//            nums[i] = 0;
//            auto res = dfs(nums, arr, p + 1);
//            if (!res.empty())
//                return res;
//            nums[i] = 1;
//            arr[p] = arr[p + dist] = 0;
//        }
//    }
//    return {};
//}




//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Construct the Lexicographically Largest Valid Sequence.
//Memory Usage: 6.2 MB, less than 91.77% of C++ online submissions for Construct the Lexicographically Largest Valid Sequence.
// 6 4 1 - - 4 6 - -
    vector<int> lt1718a(int n)
    {
        vector<int> vi(n * 2 - 1, -1);
        vector<int> nums(n);
        for (int i = n; i > 0; --i)
            nums[n - i] = i;
        dfsa1(vi, nums, 0);
        return ans;
    }
    vector<int> ans;
    bool dfsa1(vector<int>& vi, vector<int>& nums, int vii)
    {
        if (vii < vi.size() && vi[vii] != -1)
        {
//            cout<<" . . . "<<vii<<endl;
            return dfsa1(vi, nums, vii + 1);
        }
        bool emp = true;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != -1)
            {
                int v2 = nums[i];
                nums[i] = -1;

                emp = false;
                if (v2 == 1)
                {
                    vi[vii] = 1;
                    if (dfsa1(vi, nums, vii + 1))
                        return true;
                    vi[vii] = -1;
                }
                else
                {
                    int idx1 = vii;
                    int idx2 = vii + v2;

                    #ifdef __test
//                    cout<<idx2<<", "<<v2<<", "<<idx1<<", "<<vi.size()<<endl;
////                    cout
//                    showVectorInt(vi);
                    #endif // __test

                    if (idx2 >= vi.size())
                    {
                        nums[i] = v2;
                        return false;
                    }
    //                    continue;
                    if (vi[idx2] != -1)
                        goto AAA;

                    vi[idx1] = v2;
                    vi[idx2] = v2;
//showVectorInt(vi);
                    if (dfsa1(vi, nums, vii + 1))
                        return true;
                    vi[idx2] = -1;
                    vi[idx1] = -1;
                }
                AAA:
                nums[i] = v2;
            }
        }
        if (emp)
        {
//            showVectorInt(vi);
//            ans = vector<int>(begin(vi), end(vi));
            ans = vi;
        }
        return emp;
    }

};

int main()
{
    int n{20};

    LT1718 lt;

    myvi v = lt.lt1718a(n);

    showVectorInt(v);

    return 0;
}
