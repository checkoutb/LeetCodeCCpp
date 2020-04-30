
#include "../header/myheader.h"

class LT0724
{
public:



// discuss
// 一种是 left*2 + nums[i] = sum
// 一种是 left=0，right=sum。 遍历，right-=n, if (left == right) return



//Runtime: 28 ms, faster than 44.62% of C++ online submissions for Find Pivot Index.
//Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Find Pivot Index.
    int lt0724a(vector<int>& nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        int target = sum / 2;
        int n = 0;
        int i = 0;

//        cout<<n<<", "<<(sum - nums[i + 1])<<", "<<i<<endl;
////        cout<<(i < (nums.size() - 1))? 1 : 0 <<endl;
//    cout<<i<<", "<<nums.size()-1<<endl;
//    cout<<(i <= (nums.size() - 1))<<endl;
//    cout<<(int) nums.size()<<endl;
//int asz = nums.size();
//    if (i <nums.size())
//        cout<<"TTTT"<<endl;
//        else
//        cout<<"FFF"<<endl;
//
////        cout<<", "<< (n * 2 != ((sum - nums[i + 1]))) ? 1 : 0<<endl;
//cout<<(n * 2 != 3)<<endl;

// 无法重现了，之前 i<nums.size，返回false。。然后就用了sz1。。，但是无法复现了。。。。这。。。搞不清楚了。。。
//        #ifdef __test
//        if (i < (nums.size()-1)) cout<<"TTT"; else cout<<"FFFF"; cout<<endl;
//        int sz3 = nums.size();
//        if (i < sz3) cout<<"TTT"; else cout<<"FFF"; cout<<endl;
//        #endif // __test




        int sz1 = nums.size();

        while (i < sz1 && n * 2 != ((sum - nums[i])))
        {
//        cout<<n<<", "<<(sum - nums[i + 1])<<", "<<i<<endl;
            n += nums[i];
            i++;
        }
        return (i < nums.size() ? i : -1);
    }

};

int main()
{

    LT0724 lt;

    vector<int> v2[] = {{1, 7, 3, 6, 5, 6}
    ,{1,2,3},{0,0,0,0}
    };

    for (int i = 0; i < 3; i++)
    {
        vector<int> v1 = v2[i];
        cout<<lt.lt0724a(v1)<<endl;
    }

    return 0;
}
