
#include "../../header/myheader.h"

class LT
{
public:

// D D

//    void dfs(vector<int>& nums, int start, vector<int>& temp, vector<vector<int>>& ans){
//        ans.push_back(temp);
//
//        for (int i = start; i < nums.size(); ++i){
//            if (i > start && nums[i] == nums[i-1]) continue;
//            temp.push_back(nums[i]);
//            dfs(nums, i+1, temp, ans);
//            temp.pop_back();
//        }
//    }
// 如果和前面相等，那么就跳过。 并且有 i>start 的限制，所以 start 是能取到的。 然后dfs的就是start+1,也能取到。


//We can treat duplicate element as a spacial element.
//For example, if we have duplicate elements (5, 5),
//instead of treating them as two elements that are duplicate,
//we can treat it as one special element 5,
//but this element has more than two choices:
//    you can either NOT put it into the subset,
//    or put ONE 5 into the subset,
//    or put TWO 5s into the subset.

//        for(int i=0; i<nums.size(); i++) {
//            if(i==0 || nums[i] != nums[i-1]) start = 0;
//            for(int end=result.size(); start<end; start++){
//                vector<int> clone = result[start];
//                clone.push_back(nums[i]);
//                result.push_back(clone);
//            }
//        }
//result.push_back(move(clone));
// ==前面的时候， start 不会修改。 所以是 新加的那些 再加上 num。



// AC
    vector<vector<int>> lta(vector<int>& nums)
    {
        std::sort(begin(nums), end(nums));
        vector<vector<int>> ans = {{}};
        dfsa1(nums, ans, 0);
        return ans;
    }

    void dfsa1(vector<int>& vi, vector<vector<int>>& ans, int idx)
    {
        if (idx >= vi.size())
            return;
        vector<vector<int>> tmp;
        for (vector<int> v : ans)
        {
            v.push_back(vi[idx]);
            for (vector<int>& v2 : ans)
            {
                if (v.size() == v2.size())
                {
                    for (int i = 0; i < v.size(); ++i)
                    {
                        if (v[i] != v2[i])
                        {
                            goto BBB;
                        }
                    }
                    goto AAA;
                    BBB:
                    continue;
                }
            }
            tmp.push_back(v);
            AAA:
            continue;
        }
        ans.insert(ans.end(), begin(tmp), end(tmp));
        dfsa1(vi, ans, idx + 1);
    }

};

int main()
{
//    myvi v = {1,2,2};
//    myvi v = {0};
    myvi v = {4,4,4,1,4};

    LT lt;

    myvvi vv = lt.lta(v);

    for (myvi& vi : vv)
    {
        for (int i : vi)
            cout<<i<<", ";
        cout<<endl;
    }

    return 0;
}
