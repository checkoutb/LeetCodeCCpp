
#include "../header/myheader.h"

class LT1947
{
public:

// D D

//int dp[256] = {[0 ... 255] = -1};
//int maxCompatibilitySum(vector<vector<int>>& s, vector<vector<int>>& m, int i = 0, int mask = 0) {
//    if (i == s.size())
//        return 0;
//    if (dp[mask] < 0)
//        for (int j = 0; j < m.size(); ++j) {
//            if ((mask & (1 << j)) == 0)
//                dp[mask] = max(dp[mask],
//                    inner_product(begin(s[i]), end(s[i]), begin(m[j]), 0, plus<int>(), equal_to<int>())
//                    + maxCompatibilitySum(s, m, i + 1, mask + (1 << j)));
//        }
//    return dp[mask];
//}
//


//	int ans = 0;
//	vector<int> pos;
//	for(int i=0;i<students.size();i++) pos.push_back(i);
//	do{
//		int curr = 0;
//		for(int i = 0;i<students.size(); i++)
//			for(int j=0;j<students[pos[i]].size();j++)
//				curr += (students[pos[i]][j] == mentors[i][j]);
//		ans = max(ans, curr);
//	} while(next_permutation(pos.begin(), pos.end()) );
//	return ans;




//Runtime: 116 ms, faster than 64.17% of C++ online submissions for Maximum Compatibility Score Sum.
//Memory Usage: 9.9 MB, less than 78.39% of C++ online submissions for Maximum Compatibility Score Sum.
    int lt1947a(vector<vector<int>>& students, vector<vector<int>>& mentors)
    {
        vector<bool> vis(mentors.size(), false);
        int ans = dfsa1(students, mentors, 0, vis, 0);
        return ans;
    }

    // idx : students's index     vis: mentors' visited
    int dfsa1(vector<vector<int>>& ss, vector<vector<int>>& ms, int got, vector<bool>& vis, int idx)
    {
        if (idx >= ss.size())
            return got;
        int ans = 0;
        for (int i = 0; i < ms.size(); ++i)
        {
            if (vis[i])         // mentor
                continue;
            int t2 = cnta1(ss[idx], ms[i]);
            vis[i] = true;
            ans = max(ans, dfsa1(ss, ms, got + t2, vis, idx + 1));
            vis[i] = false;
        }
        return ans;
    }

    int cnta1(vector<int>& v1, vector<int>& v2)
    {
        int ans = 0;
        for (int i = 0; i < v1.size(); ++i)
        {
            if (v1[i] == v2[i])
                ans++;
        }
        return ans;
    }

};

int main()
{
//    myvvi vv1 = {{1,1,0},{1,0,1},{0,0,1}};
//    myvvi vv2 = {{1,0,0},{0,0,1},{1,1,0}};

    myvvi vv1 = {{0,0},{0,0},{0,0}};
    myvvi vv2 = {{1,1},{1,1},{1,1}};

    LT1947 lt;

    cout<<lt.lt1947a(vv1, vv2)<<endl;

    return 0;
}
