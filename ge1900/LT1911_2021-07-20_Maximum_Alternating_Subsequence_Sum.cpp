
#include "../header/myheader.h"

class LT1911
{
public:

// D D

//    long long res = 0;
//    for (int i = 1; i < n.size(); i++)
//        res += max(0, n[i - 1] - n[i]);
//    return res + n.back();

//        while(i<n-1){
//            while(i!=(n-1) && nums[i+1]>=nums[i]) i++;
//            even+=nums[i];
//            while(i!=(n-1) && nums[i+1]<=nums[i]) i++;
//            if(i!= n-1) odd+=nums[i];
//        }
//        return even-odd;

//        long long int sum=nums[0];
//        for(long long int i=1;i<nums.size();i++)
//        {
//            sum=sum+max(0,nums[i]-nums[i-1]);
//        }
//        return sum;

//        long long odd = 0, even = 0;
//        for (int& a: A)
//            even = max(even, odd + a),
//            odd = even - a;
//        return even;

//        long res = A[0];
//        for (int i = 1; i < A.size(); ++i)
//            res += max(A[i] - A[i-1], 0);
//        return res;


// 但是还是 云里雾里。   真的是 文章本天成，
//Runtime: 156 ms, faster than 85.51% of C++ online submissions for Maximum Alternating Subsequence Sum.
//Memory Usage: 91.2 MB, less than 52.73% of C++ online submissions for Maximum Alternating Subsequence Sum.
    long long lt1911b(vector<int>& nums)
    {
        long t1 = nums[0];         // size % 2 == 1
        long t2 = INT_MIN;
        int sz1 = nums.size();
        for (int i = 1; i < sz1; ++i)
        {
            long a1 = max(t2 + nums[i], (long) nums[i]);
            long a2 = t1 - nums[i];
            t1 = max(a1, t1);
            t2 = max(a2, t2);
        }
        return t1;
    }



// tle....  是不是只需要2个，一遍。。
    long long lt1911a(vector<int>& nums)
    {
        long ans = 0;
        int sz1 = nums.size();
        vector<vector<vector<long>>> vvi(sz1, vector<vector<long>>(sz1, vector<long>(2, LONG_MIN)));
        // 0: size % 2 == 0,
        for (int i = sz1 - 1; i >= 0; --i)
        {
            for (int j = i; j < sz1; ++j)
            {
                if (i == j)
                {
                    vvi[i][j][1] = max(vvi[i][j][1], (long) nums[i]);
                }
                else
                {
                    vvi[i][j][0] = vvi[i][j - 1][0];
                    vvi[i][j][1] = vvi[i][j - 1][1];
                    vvi[i][j][0] = max(vvi[i][j][0], vvi[i][j - 1][1] - nums[j]);
                    vvi[i][j][1] = max(vvi[i][j][1], vvi[i][j - 1][0] + nums[j]);
                }
            }
        #ifdef __test
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz1; ++j)
            {
                cout<<"("<<vvi[i][j][0]<<","<<vvi[i][j][1]<<"), ";
            }
            cout<<endl;
        }
        cout<<"=-=========="<<endl;
        #endif // __test
        }
        for (int i = 0; i < sz1; ++i)
        {
            ans = max(vvi[i][sz1 - 1][1], ans);
        }
        return ans;
    }

};

int main()
{
    myvi v = {4,2,5,3};     // 7
//    myvi v = {5,6,7,8};       // 8
//    myvi v = {6,2,1,2,4,5};       // 10
//    myvi v = {}


    LT1911 lt;

    cout<<lt.lt1911b(v)<<endl;

    return 0;
}
