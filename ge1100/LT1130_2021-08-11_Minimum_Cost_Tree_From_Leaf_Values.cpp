
#include "../header/myheader.h"

class LT1130
{
public:

// D D



//https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/One-Pass-O(N)-Time-and-Space
// ..............................................................
//        vector<int> stack = {INT_MAX};
//        for (int a : A) {
//            while (stack.back() <= a) {
//                int mid = stack.back();
//                stack.pop_back();
//                res += mid * min(stack.back(), a);
//            }
//            stack.push_back(a);
//        }
//        for (int i = 2; i < stack.size(); ++i) {
//            res += stack[i] * stack[i - 1];
//        }



//      while(arr.size()>1){
//          int mnp=INT_MAX,idx=-1;
//          for(int i=0;i<arr.size()-1;i++){
//              if(arr[i]*arr[i+1]<mnp){
//                  mnp=arr[i]*arr[i+1];
//                  idx=arr[i]<arr[i+1]?i:i+1;
//              }
//          }
//          mns+=mnp;
//          arr.erase(arr.begin()+idx);
//      }






//Runtime: 4 ms, faster than 79.33% of C++ online submissions for Minimum Cost Tree From Leaf Values.
//Memory Usage: 9.3 MB, less than 20.74% of C++ online submissions for Minimum Cost Tree From Leaf Values.
// hint  dp
    int lt1130b(vector<int>& arr)
    {
        int sz1 = arr.size();
        vector<vector<int>> mxv(sz1, vector<int>(sz1, 0));
//        mxv[0][0] = arr[0];
        for (int i = 0; i < sz1; ++i)
        {
            mxv[i][i] = arr[i];
            for (int j = i + 1; j < sz1; ++j)
            {
                mxv[i][j] = max(mxv[i][j - 1], arr[j]);
            }
        }

        vector<vector<int>> vvi(sz1, vector<int>(sz1 + 1, 0));      // index, length
        for (int len = 2; len <= sz1; ++len)
        {
            for (int i = 0; i + len - 1 < sz1; ++i)
            {
                int mxj = i + len - 1;
                int t2 = INT_MAX;
                for (int j = i; j < mxj; ++j)           // [i,j] (j,i+len)  [j+1,i+len-1]
                {
                    t2 = min(t2, mxv[i][j] * mxv[j + 1][mxj] + vvi[i][j - i + 1] + vvi[j + 1][mxj - j]);
                }
                vvi[i][len] = t2;
            }
        }
        #ifdef __test
        for (myvi& vi : vvi)
        {
            for (int i : vi)
                cout<<i<<", ";
            cout<<endl;
        }
        #endif // __test

        return vvi[0][sz1];
    }



// tle...
// ....
//product of the largest leaf value in its left and right subtree
    int lt1130a(vector<int>& arr)
    {
        pair<int, int> ans = dividea1(arr, 0, arr.size() - 1);
        return ans.first;
    }

    // <non-leaf sum, max leaf>
    pair<int, int> dividea1(vector<int>& arr, int st, int en)
    {
        if (st == en)
            return {0, arr[st]};
        int sum2 = INT_MAX;
        int mx2 = -1;
        for (int i = st; i < en; ++i)
        {
            mx2 = max(mx2, arr[i]);
            pair<int, int> p2 = dividea1(arr, st, i);
            pair<int, int> p3 = dividea1(arr, i + 1, en);

            int t2 = p2.second * p3.second + p2.first + p3.first;
            sum2 = min(sum2, t2);
//            int mx2 = max(p2.second, p3.second);

//            int t2 = dividea1(arr, st, i);
//            int t3 = dividea1(arr, i + 1, en);
//            ans = min(t2 * t3, ans);
        }
        #ifdef __test
        cout<<st<<", "<<en<<", "<<sum2<<", "<<mx2<<endl;
        #endif // __test
        return {sum2, max(mx2, arr[en])};
    }

};

int main()
{
//    myvi v = {6,2,4};
    myvi v = {4,11};

    LT1130 lt;

    cout<<lt.lt1130b(v);

    return 0;
}
